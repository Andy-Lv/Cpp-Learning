#pragma warning(disable:4996)
#include"Sound Velocity.h"

void Save_Sound_Velocity(map<int, double>& Sound_Velocity)
{
	//打开svp文件
	CString svp_file_name = "svp.txt";
	CStdioFile svp;
	CString strLine;//每行读取的缓存
	svp.Open(svp_file_name, CFile::modeRead);

	double depth, velocity;//储存每一个深度的声速的临时变量
	double diff;//相离最近两个的深度差
	map<double, double>sound_velocity;

	while (svp.ReadString(strLine))//循环读取每个深度以及声速
	{
		sscanf(strLine, "%lf %lf ", &depth, &velocity);
		sound_velocity.insert(make_pair(depth, velocity));
	}

	//利用lower_bound函数返回第一个大于等于findkey的迭代器指针

	for (int i = 0; i <= 12000; i++)
	{
		auto back_pos = sound_velocity.lower_bound(i);
		if (back_pos == sound_velocity.begin())//如果找到的为第一个，则直接按照第一个的value值进行插入
		{
			Sound_Velocity.insert(make_pair(i, back_pos->second));
		}
		else//对最接近这个值的两个value值进行内插
		{
			auto front_pos = back_pos--;

			diff = back_pos->first - front_pos->first;
			velocity = front_pos->second * (back_pos->first - i) / diff + back_pos->second * (i - front_pos->first) / diff;

			Sound_Velocity.insert(make_pair(i, velocity));
		}		
	}

	svp.Close();
}

void Coordinate(map<int, double>& Sound_Velocity)
{
	//输出坐标文件
	ofstream Coordinate;
	Coordinate.open("Coordinate.txt");

	//读取RawData文件
	CString data_file_name = "RawData.txt";
	CStdioFile RawData;
	CString strLine;//每行读取的缓存
	RawData.Open(data_file_name, CFile::modeRead);

	RawData.ReadString(strLine);//读取第一行文件头

	//定义中间变量
	int pingnum, beamnum;
	double GNSS_N, GNSS_E, GNSS_Z;
	double roll, pitch;
	double heave;
	double heading, azimuth, angle, trans_time;

	while (RawData.ReadString(strLine))
	{
		//读取数据
		sscanf(strLine, "%d %d %lf %lf %lf %lf %lf %lf %lf %lf %lf %lf ", &pingnum, &beamnum, &GNSS_N, &GNSS_E, &GNSS_Z, &roll, &pitch, &heave, &heading, &azimuth, &angle, &trans_time);

		//第一步，计算op和ot
		double temp_time = 0;
		double OP = 0, OT = 0;
		double sin_angle = 0;

		for (int i = 0; i <= 12000 ; i++)
		{
			//入射角的正弦除以水面的声速（深度=0）等于任意深度下传播方向正弦除以这个深度下的声速
			auto pos = Sound_Velocity.find(i);
			sin_angle = pos->second * sin(angle * rad) / 1543.0;
			OT += 1;
			OP += sin_angle / sqrt(1 - sin_angle * sin_angle);
			temp_time += 1 / sqrt(1 - sin_angle * sin_angle) / pos->second;

			if (temp_time > trans_time / 2)
			{
				break;
			}
		}
		auto pos_end = Sound_Velocity.find(OT - 1);
		double sin_angle_end = pos_end->second * sin(angle * rad) / 1543.0;
		OT -= pos_end->second * (temp_time - trans_time / 2) * sqrt(1 - sin_angle_end * sin_angle_end);
		OP -= pos_end->second * (temp_time - trans_time / 2) * sin_angle_end;

		//得到P点坐标矩阵
		Matrix<double, 3, 1> TFS;
		TFS(0, 0) = OP * cos(azimuth * rad);
		TFS(1, 0) = OP * sin(azimuth * rad);
		TFS(2, 0) = OT;

		//换能器相对于GNSS的在船体坐标系下的相对位置
		Matrix<double, 3, 1> VFS;
		VFS(0, 0) = 26.31 + 16.37;
		VFS(1, 0) = 2.07;
		VFS(2, 0) = 6.11 + 20.42;

		//两个旋转矩阵
		Matrix<double, 3, 3> R_r;
		Matrix<double, 3, 3> R_p;
		R_r << 1, 0, 0,
			0, cos(roll * rad), sin(roll * rad),
			0, -sin(roll * rad), cos(roll * rad);

		R_p << -sin(pitch * rad), 0, cos(pitch * rad),
			0, 1, 0,
			cos(pitch * rad), 0, sin(pitch * rad);

		//姿态变化后，换能器与GNSS在理想船体坐标系下的相对位置变化
		VFS = R_p * R_r * VFS;

		//姿态改正后，测深点P与GNSS在理想船体坐标系下的相对位置为
		VFS = TFS + VFS;

		//GNSS实测坐标
		Matrix<double, 3, 1> GRF;
		GRF(0, 0) = GNSS_N;
		GRF(1, 0) = GNSS_E;
		GRF(2, 0) = GNSS_Z;

		//旋转矩阵
		Matrix<double, 3, 3> R_a;
		R_a << -sin(heading * rad), cos(heading * rad), 0,
			cos(heading * rad), sin(heading * rad), 0,
			0, 0, -1;

		//基于GNSS实测坐标和航向角，求测深点地理坐标
		GRF = GRF + R_a * VFS;

		//输出点坐标
		Coordinate << fixed;
		Coordinate.precision(6);//以保留6位小数不使用科学计数法输出

		Coordinate << GRF(0,0) << " " << GRF(1, 0) << " " << GRF(2, 0) << endl;
	}
	Coordinate.close();
	RawData.Close();
}
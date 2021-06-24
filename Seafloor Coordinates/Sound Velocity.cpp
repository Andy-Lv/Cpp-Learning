#pragma warning(disable:4996)
#include"Sound Velocity.h"

void Save_Sound_Velocity(map<int, double>& Sound_Velocity)
{
	//��svp�ļ�
	CString svp_file_name = "svp.txt";
	CStdioFile svp;
	CString strLine;//ÿ�ж�ȡ�Ļ���
	svp.Open(svp_file_name, CFile::modeRead);

	double depth, velocity;//����ÿһ����ȵ����ٵ���ʱ����
	double diff;//���������������Ȳ�
	map<double, double>sound_velocity;

	while (svp.ReadString(strLine))//ѭ����ȡÿ������Լ�����
	{
		sscanf(strLine, "%lf %lf ", &depth, &velocity);
		sound_velocity.insert(make_pair(depth, velocity));
	}

	//����lower_bound�������ص�һ�����ڵ���findkey�ĵ�����ָ��

	for (int i = 0; i <= 12000; i++)
	{
		auto back_pos = sound_velocity.lower_bound(i);
		if (back_pos == sound_velocity.begin())//����ҵ���Ϊ��һ������ֱ�Ӱ��յ�һ����valueֵ���в���
		{
			Sound_Velocity.insert(make_pair(i, back_pos->second));
		}
		else//����ӽ����ֵ������valueֵ�����ڲ�
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
	//��������ļ�
	ofstream Coordinate;
	Coordinate.open("Coordinate.txt");

	//��ȡRawData�ļ�
	CString data_file_name = "RawData.txt";
	CStdioFile RawData;
	CString strLine;//ÿ�ж�ȡ�Ļ���
	RawData.Open(data_file_name, CFile::modeRead);

	RawData.ReadString(strLine);//��ȡ��һ���ļ�ͷ

	//�����м����
	int pingnum, beamnum;
	double GNSS_N, GNSS_E, GNSS_Z;
	double roll, pitch;
	double heave;
	double heading, azimuth, angle, trans_time;

	while (RawData.ReadString(strLine))
	{
		//��ȡ����
		sscanf(strLine, "%d %d %lf %lf %lf %lf %lf %lf %lf %lf %lf %lf ", &pingnum, &beamnum, &GNSS_N, &GNSS_E, &GNSS_Z, &roll, &pitch, &heave, &heading, &azimuth, &angle, &trans_time);

		//��һ��������op��ot
		double temp_time = 0;
		double OP = 0, OT = 0;
		double sin_angle = 0;

		for (int i = 0; i <= 12000 ; i++)
		{
			//����ǵ����ҳ���ˮ������٣����=0��������������´����������ҳ����������µ�����
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

		//�õ�P���������
		Matrix<double, 3, 1> TFS;
		TFS(0, 0) = OP * cos(azimuth * rad);
		TFS(1, 0) = OP * sin(azimuth * rad);
		TFS(2, 0) = OT;

		//�����������GNSS���ڴ�������ϵ�µ����λ��
		Matrix<double, 3, 1> VFS;
		VFS(0, 0) = 26.31 + 16.37;
		VFS(1, 0) = 2.07;
		VFS(2, 0) = 6.11 + 20.42;

		//������ת����
		Matrix<double, 3, 3> R_r;
		Matrix<double, 3, 3> R_p;
		R_r << 1, 0, 0,
			0, cos(roll * rad), sin(roll * rad),
			0, -sin(roll * rad), cos(roll * rad);

		R_p << -sin(pitch * rad), 0, cos(pitch * rad),
			0, 1, 0,
			cos(pitch * rad), 0, sin(pitch * rad);

		//��̬�仯�󣬻�������GNSS�����봬������ϵ�µ����λ�ñ仯
		VFS = R_p * R_r * VFS;

		//��̬�����󣬲����P��GNSS�����봬������ϵ�µ����λ��Ϊ
		VFS = TFS + VFS;

		//GNSSʵ������
		Matrix<double, 3, 1> GRF;
		GRF(0, 0) = GNSS_N;
		GRF(1, 0) = GNSS_E;
		GRF(2, 0) = GNSS_Z;

		//��ת����
		Matrix<double, 3, 3> R_a;
		R_a << -sin(heading * rad), cos(heading * rad), 0,
			cos(heading * rad), sin(heading * rad), 0,
			0, 0, -1;

		//����GNSSʵ������ͺ���ǣ��������������
		GRF = GRF + R_a * VFS;

		//���������
		Coordinate << fixed;
		Coordinate.precision(6);//�Ա���6λС����ʹ�ÿ�ѧ���������

		Coordinate << GRF(0,0) << " " << GRF(1, 0) << " " << GRF(2, 0) << endl;
	}
	Coordinate.close();
	RawData.Close();
}
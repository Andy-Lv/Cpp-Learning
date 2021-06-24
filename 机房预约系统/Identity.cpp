#include"Identity.h"

//进入管理员的子菜单界面
void ManagerMenu(Identity*& manager)
{
	while (true)
	{
		//调用管理员子菜单
		manager->OpenMenu();

		//将父类指针，转换为子类指针，调用子类里的其他接口
		Manager* man = (Manager*)manager;

		//接收用户选择
		int selete;
		cin >> selete;

		if (selete == 1)//添加账号
		{
			cout << "添加账号" << endl;
			man->AddPerson();
		}
		else if(selete == 2)//查看账号
		{
			cout << "查看账号" << endl;
			man->ShowPerson();
		}
		else if (selete == 3)//查看机房
		{
			cout << "查看机房" << endl;
			man->ShowComputer();
		}
		else if(selete == 4)//清空预约
		{
			cout << "清空预约" << endl;
			man->CleanFile();
		}
		else
		{
			delete manager;//销毁堆区对象
			cout << "注销成功" << endl;
			system("pause");
			system("cls");
			return;
		}
	}
}

//进入学生的子菜单界面
void StudentMenu(Identity*& student)
{
	while (true)
	{
		//调用管理员子菜单
		student->OpenMenu();

		//将父类指针，转换为子类指针，调用子类里的其他接口
		Student* man = (Student*)student;

		//接收用户选择
		int selete;
		cin >> selete;

		if (selete == 1)//添加账号
		{
			cout << "申请预约" << endl;
			man->ApplyOrder();
		}
		else if (selete == 2)//查看账号
		{
			cout << "查看自身预约" << endl;
			man->ShowOrder();
		}
		else if (selete == 3)//查看机房
		{
			cout << "查看所有预约" << endl;
			man->ShowAllOrder();
		}
		else if (selete == 4)//清空预约
		{
			cout << "取消预约" << endl;
			man->CancelOrder();
		}
		else
		{
			delete student;//销毁堆区对象
			cout << "注销成功" << endl;
			system("pause");
			system("cls");
			return;
		}
	}
}

void LoginIn(string filename, int type)
{
	//父类指针用于指向子类对象
	Identity* person = NULL;

	//读文件
	ifstream ifs;
	ifs.open(filename, ios::in);

	if (!ifs.is_open())
	{
		cout << "文件不存在" << endl;
		ifs.close();
		return;
	}

	//准备接收用户的信息

	int id = 0;
	string name;
	string password;

	if (type==1)
	{
		cout << "请输入你的学号" << endl;
		cin >> id;
	}
	if (type == 2)
	{
		cout << "请输入您的职工号" << endl;
		cin >> id;
	}

	cout << "请输入用户名" << endl;
	cin >> name;
	cout << "请输入密码" << endl;
	cin >> password;

	if (type == 1)
	{
		int fid;
		string fname;
		string fpassword;

		while (ifs >> fid && ifs >> fname && ifs >> fpassword)
		{
			if (id == fid && fname == name && fpassword == password)
			{
				cout << "学生登陆成功" << endl;
				system("pause");
				system("cls");

				person = new Student(id, name, password);

				//进入学生子菜单
				StudentMenu(person);

				return;
			}
			
		}
	}

	if (type == 2)
	{
		int fid;
		string fname;
		string fpassword;

		while (ifs >> fid && ifs >> fname && ifs >> fpassword)
		{
			if (id == fid && fname == name && fpassword == password)
			{
				cout << "教师登陆成功" << endl;
				system("pause");
				system("cls");

				person = new Teacher(id, name, password);

				//进入教师子菜单
				TeacherMenu(person);

				return;
			}

		}
	}

	if (type==3)
	{
		int fid;
		string fname;
		string fpassword;

		while (ifs >> fid && ifs >> fname && ifs >> fpassword)
		{
			if (id == fid && fname == name && fpassword == password)
			{
				cout << "管理员登陆成功" << endl;
				system("pause");
				system("cls");

				person = new Manager(name, password);

				//进入管理员子菜单
				ManagerMenu(person);

				return;
			}

		}
	}
	cout << "登陆失败" << endl;
	system("pause");
	system("cls");
}

//有参构造
Student::Student(int ID, string name, string password)
{
	this->ID = ID;
	this->m_Name = name;
	this->m_Password = password;

	//初始化机房信息
	ifstream ifs;
	ifs.open(COMPUTER_FILE, ios::in);

	ComputerRoom com;
	while (ifs >> com.ID && ifs >> com.m_MaxNumber)
	{
		vCom.push_back(com);
	}
	ifs.close();
}

//菜单界面
void Student::OpenMenu()
{
	cout << "欢迎学生" << this->m_Name << "登录" << endl;
	cout << "==========================================================" << endl;
	cout << "             ------------------------------               " << endl << endl;
	cout << "            |          1、申请预约         |              " << endl << endl;
	cout << "            |          2、自身预约         |              " << endl << endl;
	cout << "            |          3、所有预约         |              " << endl << endl;
	cout << "            |          4、取消预约         |              " << endl << endl;
	cout << "            |          0、注销登录         |              " << endl << endl;
	cout << "             ------------------------------               " << endl << endl;
	cout << "==========================================================" << endl;

	cout << "请选择您的操作:" << endl;
}

//申请预约
void Student::ApplyOrder()
{
	cout << "机房开放的时间为周一到周五" << endl;
	cout << "请输入您要预约的时间" << endl;
	cout << "1、周一" << endl;
	cout << "2、周二" << endl;
	cout << "3、周三" << endl;
	cout << "4、周四" << endl;
	cout << "5、周五" << endl;

	int date = 0;//日期
	int interval = 0;//时间段
	int room = 0;//机房编号
	
	while (true)
	{
		cin >> date;
		if (date >= 1 && date <= 5)
		{

			break;
		}
		else
		{
			cout << "输入错误,请重新输入" << endl;
		}
	}

	cout << "请输入申请的时间段" << endl;
	cout << "1、上午   2、下午" << endl;
	
	while (true)
	{
		cin >> interval;
		if (interval >= 1 && interval <= 2)
		{

			break;
		}
		else
		{
			cout << "输入错误,请重新输入" << endl;
		}
	}

	cout << "请选择机房" << endl;

	for (int i = 0; i < vCom.size(); i++)
	{
		cout << vCom[i].ID << "号机房容量为" << vCom[i].m_MaxNumber << endl;
	}
	
	while (true)
	{
		cin >> room;
		if (room >= 1 && room <= 3)
		{

			break;
		}
		else
		{
			cout << "输入错误,请重新输入" << endl;
		}
	}

	cout << "预约成功,审核中" << endl;

	ofstream ofs;
	ofs.open(ORDER_FILE, ios::app);

	ofs << "date:" << date << " ";
	ofs << "interval:" << interval << " ";
	ofs << "student_ID:" << this->ID << " ";
	ofs << "student_Name" << this->m_Name << " ";
	ofs << "roomID" << room << " ";
	ofs << "status:" << 1 << endl;

	ofs.close();

	system("pause");
	system("cls");
}

//查看自身预约
void Student::ShowOrder()
{
	OrderFile of;
	if (of.m_Size == 0)
	{
		cout << "无预约记录" << endl;
		system("pause");
		system("cls");
		return;
	}

	for (int i = 0; i < of.m_Size; i++)
	{
		//string 转int    string利用c.str()转const char *,再利用atoi(const char *)转int
		if (this->ID == atoi(of.m_OrderData[i]["student_ID"].c_str()))
		{
			cout << "预约日期：周" << of.m_OrderData[i]["date"];
			cout << "时间段：" << (of.m_OrderData[i]["interval"] == "1" ? "上午" : "下午");
			cout << "机房号：" << of.m_OrderData[i]["room_ID"];
			string status = "状态：";
			if (of.m_OrderData[i]["status"] == "1")
			{
				status += "审核中";
			}
			else if(of.m_OrderData[i]["status"] == "2")
			{
				status += "预约成功";
			}
			else if (of.m_OrderData[i]["status"] == "3")
			{
				status += "预约失败";
			}
			else
			{
				status += "预约已取消";
			}
			cout << status << endl;
		}
	}
	system("pause");
	system("cls");
}

//查看所有预约
void Student::ShowAllOrder()
{
	OrderFile of;
	if (of.m_Size == 0)
	{
		cout << "无预约记录" << endl;
		system("pause");
		system("cls");
		return;
	}

	for (int i = 0; i < of.m_Size; i++)
	{
		cout << "i+1" << "、 ";

		cout << "预约日期：周" << of.m_OrderData[i]["date"];
		cout << "时间段：" << (of.m_OrderData[i]["interval"] == "1" ? "上午" : "下午");
		cout << "学号：" << of.m_OrderData[i]["student_ID"];
		cout << "姓名：" << of.m_OrderData[i]["student_Name"];
		cout << "机房号：" << of.m_OrderData[i]["room_ID"];
		string status = "状态：";
		if (of.m_OrderData[i]["status"] == "1")
		{
			status += "审核中";
		}
		else if (of.m_OrderData[i]["status"] == "2")
		{
			status += "预约成功";
		}
		else if (of.m_OrderData[i]["status"] == "3")
		{
			status += "预约失败";
		}
		else
		{
			status += "预约已取消";
		}
		cout << status << endl;
	}
	system("pause");
	system("cls");
}

//取消预约
void Student::CancelOrder()
{
	OrderFile of;
	if (of.m_Size == 0)
	{
		cout << "无预约记录" << endl;
		system("pause");
		system("cls");
		return;
	}
	cout << "审核中或预约成功的巨鹿可以取消，请输入取消的记录" << endl;

	vector<int>v;
	int index = 1;
	for (int i = 0; i < of.m_Size; i++)
	{
		if (this->ID == atoi(of.m_OrderData[i]["student_ID"].c_str()))
		{
			if (of.m_OrderData[i]["status"] == "1" || of.m_OrderData[i]["status"] == "2")
			{
				v.push_back(i);
				cout << index++ << "、 ";
				cout << "预约日期：周" << of.m_OrderData[i]["date"];
				cout << "时间段：" << (of.m_OrderData[i]["interval"] == "1" ? "上午" : "下午");
				cout << "机房号：" << of.m_OrderData[i]["room_ID"];
				
				string status = "状态：";
				if (of.m_OrderData[i]["status"] == "1")
				{
					status += "审核中";
				}
				else if (of.m_OrderData[i]["status"] == "2")
				{
					status += "预约成功";
				}
				else if (of.m_OrderData[i]["status"] == "3")
				{
					status += "预约失败";
				}
				else
				{
					status += "预约已取消";
				}
				cout << status << endl;
			}
		}
	}

	cout << "请输入取消的记录，0代表返回" << endl;
	int select = 0;
	while (true)
	{
		cin >> select;
		if (select>=0&&select<=v.size())
		{
			if (select==0)
			{
				break;
			}
			else
			{
				of.m_OrderData[v[select - 1]]["status"] = "0";
				of.updateOrder();
				cout << "已成功取消" << endl;
				break;
			}
		}
		cout << "输入有误，请重新输入" << endl;
	}
	system("pause");
	system("cls");
}

//有参构造
Teacher::Teacher(int empID, string name, string password)
{
	this->ID = empID;
	this->m_Name = name;
	this->m_Password = password;
}

//打开菜单
void Teacher::OpenMenu()
{
	cout << "欢迎教师" << this->m_Name << "登录" << endl;
	cout << "==========================================================" << endl;
	cout << "             ------------------------------               " << endl << endl;
	cout << "            |          1、查看所有预约     |              " << endl << endl;
	cout << "            |          2、审核预约         |              " << endl << endl;
	cout << "            |          3、注销登录         |              " << endl << endl;
	cout << "             ------------------------------               " << endl << endl;
	cout << "==========================================================" << endl;

	cout << "请选择您的操作:" << endl;
}

//进入教师菜单界面
void TeacherMenu(Identity* &teacher)
{
	while (true)
	{
		teacher->OpenMenu();

		Teacher* tea = (Teacher*)teacher;

		int select = 0;

		cin >> select;

		if (select==1)
		{
			tea->ShowAllOrder();
		}
		else if(select==2)
		{
			tea->ValidOrder();
		}
		else
		{
			delete teacher;
			cout << "注销成功" << endl;
			system("pause");
			system("cls");
			return;
		}
	}
}
//查看所有预约
void Teacher::ShowAllOrder()
{
	OrderFile of;
	if (of.m_Size == 0)
	{
		cout << "无预约记录" << endl;
		system("pause");
		system("cls");
		return;
	}

	for (int i = 0; i < of.m_Size; i++)
	{
		cout << "i+1" << "、 ";

		cout << "预约日期：周" << of.m_OrderData[i]["date"];
		cout << "时间段：" << (of.m_OrderData[i]["interval"] == "1" ? "上午" : "下午");
		cout << "学号：" << of.m_OrderData[i]["student_ID"];
		cout << "姓名：" << of.m_OrderData[i]["student_Name"];
		cout << "机房号：" << of.m_OrderData[i]["room_ID"];
		string status = "状态：";
		if (of.m_OrderData[i]["status"] == "1")
		{
			status += "审核中";
		}
		else if (of.m_OrderData[i]["status"] == "2")
		{
			status += "预约成功";
		}
		else if (of.m_OrderData[i]["status"] == "3")
		{
			status += "预约失败";
		}
		else
		{
			status += "预约已取消";
		}
		cout << status << endl;
	}
	system("pause");
	system("cls");
}

//审核预约
void Teacher::ValidOrder()
{
	OrderFile of;
	if (of.m_Size == 0)
	{
		cout << "无预约记录" << endl;
		system("pause");
		system("cls");
		return;
	}
	cout << "待审核的记录如下:" << endl;

	vector<int>v;
	int index = 0;
	for (int i = 0; i < of.m_Size; i++)
	{
		if (of.m_OrderData[i]["status"] == "1")
		{
			v.push_back(i);
			cout << index++ << "、 ";
			cout << "预约日期：周" << of.m_OrderData[i]["date"];
			cout << "时间段：" << (of.m_OrderData[i]["interval"] == "1" ? "上午" : "下午");
			cout << "机房号：" << of.m_OrderData[i]["room_ID"];

			string status = "状态：";
			if (of.m_OrderData[i]["status"] == "1")
			{
				status += "审核中";
			}
			else if (of.m_OrderData[i]["status"] == "2")
			{
				status += "预约成功";
			}
			else if (of.m_OrderData[i]["status"] == "3")
			{
				status += "预约失败";
			}
			else
			{
				status += "预约已取消";
			}
			cout << status << endl;
		}
	}

	cout << "请输入审核的记录，0代表返回" << endl;
	int select = 0;
	int ret = 0;
	while (true)
	{
		cin >> select;
		if (select >= 0 && select <= v.size())
		{
			if (select == 0)
			{
				break;
			}
			else
			{
				cout << "请输入审核结果" << endl;
				cout << "1、通过" << endl;
				cout << "2、不通过" << endl;
				cin >> ret;

				if (ret==1)
				{
					of.m_OrderData[v[select - 1]]["status"] = "2";
				}
				else
				{
					of.m_OrderData[v[select - 1]]["status"] = "-1";
				}
				of.m_OrderData[v[select - 1]]["status"] = "0";
				of.updateOrder();
				cout << "已成功审核" << endl;
				break;
			}
		}
		cout << "输入有误，请重新输入" << endl;
	}
	system("pause");
	system("cls");
}

//有参构造
Manager::Manager(string name, string password)
{
	this->m_Name = name;
	this->m_Password = password;

	//初始化容器 获取到所有文件中学生和老师信息

	this->InitVector();

	//初始化机房信息
	ifstream ifs;
	ifs.open(COMPUTER_FILE, ios::in);

	ComputerRoom com;
	while (ifs >> com.ID && ifs >> com.m_MaxNumber)
	{
		vCom.push_back(com);
	}

	ifs.close();
}

//打开菜单
void Manager::OpenMenu() 
{
	cout << "欢迎管理员" << this->m_Name << "登录" << endl;
	cout << "==========================================================" << endl;
	cout << "             ------------------------------               " << endl << endl;
	cout << "            |          1、添加人员         |              " << endl << endl;
	cout << "            |          2、查看账号         |              " << endl << endl;
	cout << "            |          3、查看机房         |              " << endl << endl;
	cout << "            |          0、清空记录         |              " << endl << endl;
	cout << "             ------------------------------               " << endl << endl;
	cout << "==========================================================" << endl;

	cout << "请选择您的操作:" << endl;
}

//添加人员
void Manager::AddPerson()
{
	cout << "请输入添加账号的类型" << endl;
	cout << "1、添加学生" << endl;
	cout << "2、添加老师" << endl;

	string filename;
	string tip;

	ofstream ofs;
	int selete;
	switch (selete)
	{
	case 1:
		filename = STUDENT_FILE;
		tip = "请输入学号";
		break;
	case 2:
		filename = TEACHER_FILE;
		tip = "请输入职工号";
	default:
		break;
	}

	ofs.open(filename, ios::out | ios::app);//追加的方式写文件

	int id;
	string name;
	string password;

	//检测输入编号是否重复
	cout << tip << endl;

	while (true)
	{
		cin >> id;
		bool ret = CheckRepeat(id, selete);
		if (ret)
		{
			cout << "用户名已存在" << endl;
		}
		else
		{
			break;
		}
	}

	cout << "请输入姓名：" << endl;
	cin >> name;
	cout << "请输入密码";
	cin >> password;

	ofs << id << " " << name << " " << password << endl;
	cout << "添加成功" << endl;

	system("pause");
	system("cls");

	ofs.close();

	this->InitVector();//及时初始化信息，否则在一次打开程序的时候添加，容器没有初始化，造成重复添加
}

void printComputer(ComputerRoom& com)
{
	cout << com.ID << " 号机房容量为" << com.m_MaxNumber << endl;
}

void Manager::ShowComputer()
{
	cout << "机房信息如下：" << endl;
	for_each(vCom.begin(), vCom.end(), printComputer);
	
}
void printStudent(Student& s)
{
	cout << "学号：" << s.ID << " 姓名" << s.m_Name << " 密码:" << s.m_Password << endl;
}

void printTeacher(Teacher& s)
{
	cout << "工号：" << s.ID << " 姓名" << s.m_Name << " 密码:" << s.m_Password << endl;
}

//查看账号
void Manager::ShowPerson()
{
	cout << "请选择查看内容" << endl;
	cout << "1、查看所有学生" << endl;
	cout << "1、查看所有老师" << endl;

	int selete;
	cin >> selete;

	if (selete==1)
	{
		cout << "所有学生信息如下：" << endl;
		for_each(vStu.begin(), vStu.end(), printStudent);
	}

	if (selete == 2)
	{
		cout << "所有教师信息如下：" << endl;
		for_each(vTea.begin(), vTea.end(), printTeacher);
	}

	system("pause");
	system("cls");
}

//清空预约记录
void Manager::CleanFile()
{
	ofstream ofs;
	ofs.open(ORDER_FILE, ios::trunc);
	ofs.close();
	
	cout << "清空成功" << endl;
	system("pause");
	system("cls");
}

//初始化容器
void Manager::InitVector()
{
	//确保容器是空的
	vStu.clear();
	vTea.clear();

	//读取信息，学生和老师
	ifstream ifs;
	ifs.open(STUDENT_FILE, ios::in);
	if (!ifs.is_open())
	{
		cout << "文件读取失败" << endl;
		return;
	}

	Student s;
	while (ifs >> s.ID && ifs >> s.m_Name && ifs >> s.m_Password)
	{
		vStu.push_back(s);
	}

	cout << "当前学生数量为" << vStu.size() << endl;

	ifs.close();

	Teacher t;

	ifs.open(TEACHER_FILE, ios::in);
	if (!ifs.is_open())
	{
		cout << "文件读取失败" << endl;
		return;
	}

	Student s;
	while (ifs >> t.ID && ifs >> t.m_Name && ifs >> t.m_Password)
	{
		vTea.push_back(t);
	}

	cout << "当前老师数量为" << vTea.size() << endl;

	ifs.close();
}

bool Manager::CheckRepeat(int id, int type)
{
	if (type==1)//检测学生
	{
		for (vector<Student>::iterator it = vStu.begin(); it != vStu.end(); it++)
		{
			if (it->ID == id)
			{
				return true;
			}
		}
	}

	else
	{
		for (vector<Teacher>::iterator it = vTea.begin(); it != vTea.end(); it++)
		{
			if (it->ID == id)
			{
				return true;
			}
		}
	}

	return false;
}

OrderFile::OrderFile()
{
	ifstream ifs;
	ifs.open(ORDER_FILE, ios::in);

	string date;
	string interval;
	string student_ID;
	string student_Name;
	string roomID;
	string status;

	this->m_Size = 0;

	while (ifs >> date && ifs >> interval && ifs >> student_ID && ifs >> student_Name && ifs >> roomID && ifs >> status)
	{
		string key;
		string value;
		map<string, string>m;

		int pos = date.find(":");

		if (pos!=-1)
		{
			key = date.substr(0, pos);//date数据中有冒号，需要提取出来

			value = date.substr(pos + 1, date.size() - pos - 1);

			m.insert(make_pair(key, value));
		}
		
		int pos = interval.find(":");

		if (pos != -1)
		{
			key = interval.substr(0, pos);//interval数据中有冒号，需要提取出来

			value = interval.substr(pos + 1, interval.size() - pos - 1);

			m.insert(make_pair(key, value));
		}

		int pos = student_ID.find(":");

		if (pos != -1)
		{
			key = student_ID.substr(0, pos);//interval数据中有冒号，需要提取出来

			value = student_ID.substr(pos + 1, student_ID.size() - pos - 1);

			m.insert(make_pair(key, value));
		}

		int pos = student_Name.find(":");

		if (pos != -1)
		{
			key = student_Name.substr(0, pos);//interval数据中有冒号，需要提取出来

			value = student_Name.substr(pos + 1, student_Name.size() - pos - 1);

			m.insert(make_pair(key, value));
		}

		int pos = roomID.find(":");

		if (pos != -1)
		{
			key = roomID.substr(0, pos);//interval数据中有冒号，需要提取出来

			value = roomID.substr(pos + 1, roomID.size() - pos - 1);

			m.insert(make_pair(key, value));
		}

		int pos = status.find(":");

		if (pos != -1)
		{
			key = status.substr(0, pos);//interval数据中有冒号，需要提取出来

			value = status.substr(pos + 1, status.size() - pos - 1);

			m.insert(make_pair(key, value));
		}

		this->m_OrderData.insert(make_pair(this->m_Size, m));
		this->m_Size++;
	}

	ifs.close();
}

//更新预约记录
void OrderFile::updateOrder()
{
	if (this->m_Size==0)
	{
		return;
	}

	ofstream ofs(ORDER_FILE, ios::out | ios::trunc);

	for (int i = 0; i < m_Size; i++)
	{
		ofs << "date:" << this->m_OrderData[i]["date"] << " ";
		ofs << "interval:" << this->m_OrderData[i]["interval"] << " ";
		ofs << "student_ID:" << this->m_OrderData[i]["student_ID"] << " ";
		ofs << "student_Name:" << this->m_OrderData[i]["student_Name"] << " ";
		ofs << "roomID:" << this->m_OrderData[i]["roomID"] << " ";
		ofs << "status:" << this->m_OrderData[i]["status"] << " " << endl;
	}
}


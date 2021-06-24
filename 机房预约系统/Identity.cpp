#include"Identity.h"

//�������Ա���Ӳ˵�����
void ManagerMenu(Identity*& manager)
{
	while (true)
	{
		//���ù���Ա�Ӳ˵�
		manager->OpenMenu();

		//������ָ�룬ת��Ϊ����ָ�룬����������������ӿ�
		Manager* man = (Manager*)manager;

		//�����û�ѡ��
		int selete;
		cin >> selete;

		if (selete == 1)//����˺�
		{
			cout << "����˺�" << endl;
			man->AddPerson();
		}
		else if(selete == 2)//�鿴�˺�
		{
			cout << "�鿴�˺�" << endl;
			man->ShowPerson();
		}
		else if (selete == 3)//�鿴����
		{
			cout << "�鿴����" << endl;
			man->ShowComputer();
		}
		else if(selete == 4)//���ԤԼ
		{
			cout << "���ԤԼ" << endl;
			man->CleanFile();
		}
		else
		{
			delete manager;//���ٶ�������
			cout << "ע���ɹ�" << endl;
			system("pause");
			system("cls");
			return;
		}
	}
}

//����ѧ�����Ӳ˵�����
void StudentMenu(Identity*& student)
{
	while (true)
	{
		//���ù���Ա�Ӳ˵�
		student->OpenMenu();

		//������ָ�룬ת��Ϊ����ָ�룬����������������ӿ�
		Student* man = (Student*)student;

		//�����û�ѡ��
		int selete;
		cin >> selete;

		if (selete == 1)//����˺�
		{
			cout << "����ԤԼ" << endl;
			man->ApplyOrder();
		}
		else if (selete == 2)//�鿴�˺�
		{
			cout << "�鿴����ԤԼ" << endl;
			man->ShowOrder();
		}
		else if (selete == 3)//�鿴����
		{
			cout << "�鿴����ԤԼ" << endl;
			man->ShowAllOrder();
		}
		else if (selete == 4)//���ԤԼ
		{
			cout << "ȡ��ԤԼ" << endl;
			man->CancelOrder();
		}
		else
		{
			delete student;//���ٶ�������
			cout << "ע���ɹ�" << endl;
			system("pause");
			system("cls");
			return;
		}
	}
}

void LoginIn(string filename, int type)
{
	//����ָ������ָ���������
	Identity* person = NULL;

	//���ļ�
	ifstream ifs;
	ifs.open(filename, ios::in);

	if (!ifs.is_open())
	{
		cout << "�ļ�������" << endl;
		ifs.close();
		return;
	}

	//׼�������û�����Ϣ

	int id = 0;
	string name;
	string password;

	if (type==1)
	{
		cout << "���������ѧ��" << endl;
		cin >> id;
	}
	if (type == 2)
	{
		cout << "����������ְ����" << endl;
		cin >> id;
	}

	cout << "�������û���" << endl;
	cin >> name;
	cout << "����������" << endl;
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
				cout << "ѧ����½�ɹ�" << endl;
				system("pause");
				system("cls");

				person = new Student(id, name, password);

				//����ѧ���Ӳ˵�
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
				cout << "��ʦ��½�ɹ�" << endl;
				system("pause");
				system("cls");

				person = new Teacher(id, name, password);

				//�����ʦ�Ӳ˵�
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
				cout << "����Ա��½�ɹ�" << endl;
				system("pause");
				system("cls");

				person = new Manager(name, password);

				//�������Ա�Ӳ˵�
				ManagerMenu(person);

				return;
			}

		}
	}
	cout << "��½ʧ��" << endl;
	system("pause");
	system("cls");
}

//�вι���
Student::Student(int ID, string name, string password)
{
	this->ID = ID;
	this->m_Name = name;
	this->m_Password = password;

	//��ʼ��������Ϣ
	ifstream ifs;
	ifs.open(COMPUTER_FILE, ios::in);

	ComputerRoom com;
	while (ifs >> com.ID && ifs >> com.m_MaxNumber)
	{
		vCom.push_back(com);
	}
	ifs.close();
}

//�˵�����
void Student::OpenMenu()
{
	cout << "��ӭѧ��" << this->m_Name << "��¼" << endl;
	cout << "==========================================================" << endl;
	cout << "             ------------------------------               " << endl << endl;
	cout << "            |          1������ԤԼ         |              " << endl << endl;
	cout << "            |          2������ԤԼ         |              " << endl << endl;
	cout << "            |          3������ԤԼ         |              " << endl << endl;
	cout << "            |          4��ȡ��ԤԼ         |              " << endl << endl;
	cout << "            |          0��ע����¼         |              " << endl << endl;
	cout << "             ------------------------------               " << endl << endl;
	cout << "==========================================================" << endl;

	cout << "��ѡ�����Ĳ���:" << endl;
}

//����ԤԼ
void Student::ApplyOrder()
{
	cout << "�������ŵ�ʱ��Ϊ��һ������" << endl;
	cout << "��������ҪԤԼ��ʱ��" << endl;
	cout << "1����һ" << endl;
	cout << "2���ܶ�" << endl;
	cout << "3������" << endl;
	cout << "4������" << endl;
	cout << "5������" << endl;

	int date = 0;//����
	int interval = 0;//ʱ���
	int room = 0;//�������
	
	while (true)
	{
		cin >> date;
		if (date >= 1 && date <= 5)
		{

			break;
		}
		else
		{
			cout << "�������,����������" << endl;
		}
	}

	cout << "�����������ʱ���" << endl;
	cout << "1������   2������" << endl;
	
	while (true)
	{
		cin >> interval;
		if (interval >= 1 && interval <= 2)
		{

			break;
		}
		else
		{
			cout << "�������,����������" << endl;
		}
	}

	cout << "��ѡ�����" << endl;

	for (int i = 0; i < vCom.size(); i++)
	{
		cout << vCom[i].ID << "�Ż�������Ϊ" << vCom[i].m_MaxNumber << endl;
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
			cout << "�������,����������" << endl;
		}
	}

	cout << "ԤԼ�ɹ�,�����" << endl;

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

//�鿴����ԤԼ
void Student::ShowOrder()
{
	OrderFile of;
	if (of.m_Size == 0)
	{
		cout << "��ԤԼ��¼" << endl;
		system("pause");
		system("cls");
		return;
	}

	for (int i = 0; i < of.m_Size; i++)
	{
		//string תint    string����c.str()תconst char *,������atoi(const char *)תint
		if (this->ID == atoi(of.m_OrderData[i]["student_ID"].c_str()))
		{
			cout << "ԤԼ���ڣ���" << of.m_OrderData[i]["date"];
			cout << "ʱ��Σ�" << (of.m_OrderData[i]["interval"] == "1" ? "����" : "����");
			cout << "�����ţ�" << of.m_OrderData[i]["room_ID"];
			string status = "״̬��";
			if (of.m_OrderData[i]["status"] == "1")
			{
				status += "�����";
			}
			else if(of.m_OrderData[i]["status"] == "2")
			{
				status += "ԤԼ�ɹ�";
			}
			else if (of.m_OrderData[i]["status"] == "3")
			{
				status += "ԤԼʧ��";
			}
			else
			{
				status += "ԤԼ��ȡ��";
			}
			cout << status << endl;
		}
	}
	system("pause");
	system("cls");
}

//�鿴����ԤԼ
void Student::ShowAllOrder()
{
	OrderFile of;
	if (of.m_Size == 0)
	{
		cout << "��ԤԼ��¼" << endl;
		system("pause");
		system("cls");
		return;
	}

	for (int i = 0; i < of.m_Size; i++)
	{
		cout << "i+1" << "�� ";

		cout << "ԤԼ���ڣ���" << of.m_OrderData[i]["date"];
		cout << "ʱ��Σ�" << (of.m_OrderData[i]["interval"] == "1" ? "����" : "����");
		cout << "ѧ�ţ�" << of.m_OrderData[i]["student_ID"];
		cout << "������" << of.m_OrderData[i]["student_Name"];
		cout << "�����ţ�" << of.m_OrderData[i]["room_ID"];
		string status = "״̬��";
		if (of.m_OrderData[i]["status"] == "1")
		{
			status += "�����";
		}
		else if (of.m_OrderData[i]["status"] == "2")
		{
			status += "ԤԼ�ɹ�";
		}
		else if (of.m_OrderData[i]["status"] == "3")
		{
			status += "ԤԼʧ��";
		}
		else
		{
			status += "ԤԼ��ȡ��";
		}
		cout << status << endl;
	}
	system("pause");
	system("cls");
}

//ȡ��ԤԼ
void Student::CancelOrder()
{
	OrderFile of;
	if (of.m_Size == 0)
	{
		cout << "��ԤԼ��¼" << endl;
		system("pause");
		system("cls");
		return;
	}
	cout << "����л�ԤԼ�ɹ��ľ�¹����ȡ����������ȡ���ļ�¼" << endl;

	vector<int>v;
	int index = 1;
	for (int i = 0; i < of.m_Size; i++)
	{
		if (this->ID == atoi(of.m_OrderData[i]["student_ID"].c_str()))
		{
			if (of.m_OrderData[i]["status"] == "1" || of.m_OrderData[i]["status"] == "2")
			{
				v.push_back(i);
				cout << index++ << "�� ";
				cout << "ԤԼ���ڣ���" << of.m_OrderData[i]["date"];
				cout << "ʱ��Σ�" << (of.m_OrderData[i]["interval"] == "1" ? "����" : "����");
				cout << "�����ţ�" << of.m_OrderData[i]["room_ID"];
				
				string status = "״̬��";
				if (of.m_OrderData[i]["status"] == "1")
				{
					status += "�����";
				}
				else if (of.m_OrderData[i]["status"] == "2")
				{
					status += "ԤԼ�ɹ�";
				}
				else if (of.m_OrderData[i]["status"] == "3")
				{
					status += "ԤԼʧ��";
				}
				else
				{
					status += "ԤԼ��ȡ��";
				}
				cout << status << endl;
			}
		}
	}

	cout << "������ȡ���ļ�¼��0������" << endl;
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
				cout << "�ѳɹ�ȡ��" << endl;
				break;
			}
		}
		cout << "������������������" << endl;
	}
	system("pause");
	system("cls");
}

//�вι���
Teacher::Teacher(int empID, string name, string password)
{
	this->ID = empID;
	this->m_Name = name;
	this->m_Password = password;
}

//�򿪲˵�
void Teacher::OpenMenu()
{
	cout << "��ӭ��ʦ" << this->m_Name << "��¼" << endl;
	cout << "==========================================================" << endl;
	cout << "             ------------------------------               " << endl << endl;
	cout << "            |          1���鿴����ԤԼ     |              " << endl << endl;
	cout << "            |          2�����ԤԼ         |              " << endl << endl;
	cout << "            |          3��ע����¼         |              " << endl << endl;
	cout << "             ------------------------------               " << endl << endl;
	cout << "==========================================================" << endl;

	cout << "��ѡ�����Ĳ���:" << endl;
}

//�����ʦ�˵�����
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
			cout << "ע���ɹ�" << endl;
			system("pause");
			system("cls");
			return;
		}
	}
}
//�鿴����ԤԼ
void Teacher::ShowAllOrder()
{
	OrderFile of;
	if (of.m_Size == 0)
	{
		cout << "��ԤԼ��¼" << endl;
		system("pause");
		system("cls");
		return;
	}

	for (int i = 0; i < of.m_Size; i++)
	{
		cout << "i+1" << "�� ";

		cout << "ԤԼ���ڣ���" << of.m_OrderData[i]["date"];
		cout << "ʱ��Σ�" << (of.m_OrderData[i]["interval"] == "1" ? "����" : "����");
		cout << "ѧ�ţ�" << of.m_OrderData[i]["student_ID"];
		cout << "������" << of.m_OrderData[i]["student_Name"];
		cout << "�����ţ�" << of.m_OrderData[i]["room_ID"];
		string status = "״̬��";
		if (of.m_OrderData[i]["status"] == "1")
		{
			status += "�����";
		}
		else if (of.m_OrderData[i]["status"] == "2")
		{
			status += "ԤԼ�ɹ�";
		}
		else if (of.m_OrderData[i]["status"] == "3")
		{
			status += "ԤԼʧ��";
		}
		else
		{
			status += "ԤԼ��ȡ��";
		}
		cout << status << endl;
	}
	system("pause");
	system("cls");
}

//���ԤԼ
void Teacher::ValidOrder()
{
	OrderFile of;
	if (of.m_Size == 0)
	{
		cout << "��ԤԼ��¼" << endl;
		system("pause");
		system("cls");
		return;
	}
	cout << "����˵ļ�¼����:" << endl;

	vector<int>v;
	int index = 0;
	for (int i = 0; i < of.m_Size; i++)
	{
		if (of.m_OrderData[i]["status"] == "1")
		{
			v.push_back(i);
			cout << index++ << "�� ";
			cout << "ԤԼ���ڣ���" << of.m_OrderData[i]["date"];
			cout << "ʱ��Σ�" << (of.m_OrderData[i]["interval"] == "1" ? "����" : "����");
			cout << "�����ţ�" << of.m_OrderData[i]["room_ID"];

			string status = "״̬��";
			if (of.m_OrderData[i]["status"] == "1")
			{
				status += "�����";
			}
			else if (of.m_OrderData[i]["status"] == "2")
			{
				status += "ԤԼ�ɹ�";
			}
			else if (of.m_OrderData[i]["status"] == "3")
			{
				status += "ԤԼʧ��";
			}
			else
			{
				status += "ԤԼ��ȡ��";
			}
			cout << status << endl;
		}
	}

	cout << "��������˵ļ�¼��0������" << endl;
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
				cout << "��������˽��" << endl;
				cout << "1��ͨ��" << endl;
				cout << "2����ͨ��" << endl;
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
				cout << "�ѳɹ����" << endl;
				break;
			}
		}
		cout << "������������������" << endl;
	}
	system("pause");
	system("cls");
}

//�вι���
Manager::Manager(string name, string password)
{
	this->m_Name = name;
	this->m_Password = password;

	//��ʼ������ ��ȡ�������ļ���ѧ������ʦ��Ϣ

	this->InitVector();

	//��ʼ��������Ϣ
	ifstream ifs;
	ifs.open(COMPUTER_FILE, ios::in);

	ComputerRoom com;
	while (ifs >> com.ID && ifs >> com.m_MaxNumber)
	{
		vCom.push_back(com);
	}

	ifs.close();
}

//�򿪲˵�
void Manager::OpenMenu() 
{
	cout << "��ӭ����Ա" << this->m_Name << "��¼" << endl;
	cout << "==========================================================" << endl;
	cout << "             ------------------------------               " << endl << endl;
	cout << "            |          1�������Ա         |              " << endl << endl;
	cout << "            |          2���鿴�˺�         |              " << endl << endl;
	cout << "            |          3���鿴����         |              " << endl << endl;
	cout << "            |          0����ռ�¼         |              " << endl << endl;
	cout << "             ------------------------------               " << endl << endl;
	cout << "==========================================================" << endl;

	cout << "��ѡ�����Ĳ���:" << endl;
}

//�����Ա
void Manager::AddPerson()
{
	cout << "����������˺ŵ�����" << endl;
	cout << "1�����ѧ��" << endl;
	cout << "2�������ʦ" << endl;

	string filename;
	string tip;

	ofstream ofs;
	int selete;
	switch (selete)
	{
	case 1:
		filename = STUDENT_FILE;
		tip = "������ѧ��";
		break;
	case 2:
		filename = TEACHER_FILE;
		tip = "������ְ����";
	default:
		break;
	}

	ofs.open(filename, ios::out | ios::app);//׷�ӵķ�ʽд�ļ�

	int id;
	string name;
	string password;

	//����������Ƿ��ظ�
	cout << tip << endl;

	while (true)
	{
		cin >> id;
		bool ret = CheckRepeat(id, selete);
		if (ret)
		{
			cout << "�û����Ѵ���" << endl;
		}
		else
		{
			break;
		}
	}

	cout << "������������" << endl;
	cin >> name;
	cout << "����������";
	cin >> password;

	ofs << id << " " << name << " " << password << endl;
	cout << "��ӳɹ�" << endl;

	system("pause");
	system("cls");

	ofs.close();

	this->InitVector();//��ʱ��ʼ����Ϣ��������һ�δ򿪳����ʱ����ӣ�����û�г�ʼ��������ظ����
}

void printComputer(ComputerRoom& com)
{
	cout << com.ID << " �Ż�������Ϊ" << com.m_MaxNumber << endl;
}

void Manager::ShowComputer()
{
	cout << "������Ϣ���£�" << endl;
	for_each(vCom.begin(), vCom.end(), printComputer);
	
}
void printStudent(Student& s)
{
	cout << "ѧ�ţ�" << s.ID << " ����" << s.m_Name << " ����:" << s.m_Password << endl;
}

void printTeacher(Teacher& s)
{
	cout << "���ţ�" << s.ID << " ����" << s.m_Name << " ����:" << s.m_Password << endl;
}

//�鿴�˺�
void Manager::ShowPerson()
{
	cout << "��ѡ��鿴����" << endl;
	cout << "1���鿴����ѧ��" << endl;
	cout << "1���鿴������ʦ" << endl;

	int selete;
	cin >> selete;

	if (selete==1)
	{
		cout << "����ѧ����Ϣ���£�" << endl;
		for_each(vStu.begin(), vStu.end(), printStudent);
	}

	if (selete == 2)
	{
		cout << "���н�ʦ��Ϣ���£�" << endl;
		for_each(vTea.begin(), vTea.end(), printTeacher);
	}

	system("pause");
	system("cls");
}

//���ԤԼ��¼
void Manager::CleanFile()
{
	ofstream ofs;
	ofs.open(ORDER_FILE, ios::trunc);
	ofs.close();
	
	cout << "��ճɹ�" << endl;
	system("pause");
	system("cls");
}

//��ʼ������
void Manager::InitVector()
{
	//ȷ�������ǿյ�
	vStu.clear();
	vTea.clear();

	//��ȡ��Ϣ��ѧ������ʦ
	ifstream ifs;
	ifs.open(STUDENT_FILE, ios::in);
	if (!ifs.is_open())
	{
		cout << "�ļ���ȡʧ��" << endl;
		return;
	}

	Student s;
	while (ifs >> s.ID && ifs >> s.m_Name && ifs >> s.m_Password)
	{
		vStu.push_back(s);
	}

	cout << "��ǰѧ������Ϊ" << vStu.size() << endl;

	ifs.close();

	Teacher t;

	ifs.open(TEACHER_FILE, ios::in);
	if (!ifs.is_open())
	{
		cout << "�ļ���ȡʧ��" << endl;
		return;
	}

	Student s;
	while (ifs >> t.ID && ifs >> t.m_Name && ifs >> t.m_Password)
	{
		vTea.push_back(t);
	}

	cout << "��ǰ��ʦ����Ϊ" << vTea.size() << endl;

	ifs.close();
}

bool Manager::CheckRepeat(int id, int type)
{
	if (type==1)//���ѧ��
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
			key = date.substr(0, pos);//date��������ð�ţ���Ҫ��ȡ����

			value = date.substr(pos + 1, date.size() - pos - 1);

			m.insert(make_pair(key, value));
		}
		
		int pos = interval.find(":");

		if (pos != -1)
		{
			key = interval.substr(0, pos);//interval��������ð�ţ���Ҫ��ȡ����

			value = interval.substr(pos + 1, interval.size() - pos - 1);

			m.insert(make_pair(key, value));
		}

		int pos = student_ID.find(":");

		if (pos != -1)
		{
			key = student_ID.substr(0, pos);//interval��������ð�ţ���Ҫ��ȡ����

			value = student_ID.substr(pos + 1, student_ID.size() - pos - 1);

			m.insert(make_pair(key, value));
		}

		int pos = student_Name.find(":");

		if (pos != -1)
		{
			key = student_Name.substr(0, pos);//interval��������ð�ţ���Ҫ��ȡ����

			value = student_Name.substr(pos + 1, student_Name.size() - pos - 1);

			m.insert(make_pair(key, value));
		}

		int pos = roomID.find(":");

		if (pos != -1)
		{
			key = roomID.substr(0, pos);//interval��������ð�ţ���Ҫ��ȡ����

			value = roomID.substr(pos + 1, roomID.size() - pos - 1);

			m.insert(make_pair(key, value));
		}

		int pos = status.find(":");

		if (pos != -1)
		{
			key = status.substr(0, pos);//interval��������ð�ţ���Ҫ��ȡ����

			value = status.substr(pos + 1, status.size() - pos - 1);

			m.insert(make_pair(key, value));
		}

		this->m_OrderData.insert(make_pair(this->m_Size, m));
		this->m_Size++;
	}

	ifs.close();
}

//����ԤԼ��¼
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


#include"WorkerManager.h"

WorkerManager::WorkerManager()
{
	//文件不存在
	ifstream ifs;
	ifs.open(FILENAME, ios::in);
	if (!ifs.is_open())
	{
		cout << "文件不存在" << endl;

		//初始化属性
		this->m_EmpNum = 0;
		this->m_EmpArray = NULL;
		this->FileIsEmpty = true;
		ifs.close();
	}

	//文件为空
	char ch;
	ifs >> ch;
	if (ifs.eof())
	{
		cout << "文件为空" << endl;

		//初始化属性
		this->m_EmpNum = 0;
		this->m_EmpArray = NULL;
		this->FileIsEmpty = true;
		ifs.close();
	}

	//文件不为空
	int num = this->GetNum();
	cout << "目前职工人数为：" << num << endl;
	this->m_EmpNum = num;

	this->m_EmpArray = new Worker * [this->m_EmpNum];
	this->InitEmp();
}

void WorkerManager::ShowMenu()
{
	cout << "******************************************" << endl;
	cout << "***********欢迎使用职工管理系统***********" << endl;
	cout << "*************1、增加职工信息**************" << endl;
	cout << "*************2、显示职工信息**************" << endl;
	cout << "*************3、删除离职员工**************" << endl;
	cout << "*************4、修改职工信息**************" << endl;
	cout << "*************5、查找职工信息**************" << endl;
	cout << "*************6、按照编号排序**************" << endl;
	cout << "*************7、清空所有文档**************" << endl;
	cout << "*************8、退出管理程序**************" << endl;
	cout << "******************************************" << endl;
}

void WorkerManager::ExitSystem()
{
	cout << "欢迎下次使用" << endl;
	system("pause");
	exit(0);//退出系统
}

void WorkerManager::AddEmployor()
{
	cout << "请输入添加职工的数量" << endl;
	int AddNum = 0;
	while (true)
	{
		cin >> AddNum;
		if (AddNum > 0)
		{
			break;
		}
		cout << "输入数据有误,请重新输入" << endl;
	}
	//计算添加新空间大小
	int NewSize = this->m_EmpNum + AddNum;

	//开辟新空间
	Worker** newSpace = new Worker * [NewSize];

	if (this->m_EmpArray != NULL)
	{
		for (int i = 0; i < this->m_EmpNum; i++)
		{
			newSpace[i] = this->m_EmpArray[i];
		}
	}

	for (int i = 0; i < AddNum; i++)
	{
		int id;
		string name;
		int Dept;

		cout << "请输入第" << i + 1 << "个新员工编号：" << endl;
		cin >> id;

		cout << "请输入第" << i + 1 << "个新员工姓名：" << endl;
		cin >> name;

		cout << "请输入第" << i + 1 << "个新员工职位：1、普通员工   2、经理   3、老板" << endl;
		cin >> Dept;

		Worker* worker = NULL;
		switch (Dept)
		{
		case 1:
			worker = new Employee(id, name, 1);
			break;
		case 2:
			worker = new Manager(id, name, 2);
			break;
		case 3:
			worker = new Employor(id, name, 3);
			break;
		default:
			break;
		}
		//创建职工职责，并保存到数组中
		newSpace[this->m_EmpNum + i] = worker;
		if (Dept == 1)
			cout << "成功添加：" << id << "\t" << name << "\t" << "员工" << endl;
		else if(Dept==2)
			cout << "成功添加：" << id << "\t" << name << "\t" << "经理" << endl;
		else
			cout << "成功添加：" << id << "\t" << name << "\t" << "老板" << endl;
	}
	//释放原有的空间
	delete[] this->m_EmpArray;
	//更改新空间的指向
	this->m_EmpArray = newSpace;
	//更新新的职工人数
	this->m_EmpNum = NewSize;
	//更新职工不为空
	this->FileIsEmpty = false;

	cout << "成功添加" << AddNum << "名新员工" << endl;

	this->Save();

	system("pause");
	system("cls");
}

void WorkerManager::Save()
{
	ofstream ofs;
	ofs.open(FILENAME, ios::out);

	for (int i = 0; i < this->m_EmpNum; i++)
	{
		ofs << this->m_EmpArray[i]->m_ID << " "
			<< this->m_EmpArray[i]->m_Name << " "
			<< this->m_EmpArray[i]->m_DeptID << " " << endl;
	}
	ofs.close();
}

int WorkerManager::GetNum()
{
	int ID, Dept;
	string Name;
	ifstream ifs;
	int num = 0;
	ifs.open(FILENAME, ios::in);
	if (!ifs.is_open())
	{
		cout << "文件未打开" << endl;
	}

	while (ifs >> ID && ifs >> Name && ifs >> Dept)
	{
		num++;
	}

	return num;
}

void WorkerManager::InitEmp()
{
	int ID, Dept;
	string Name;
	ifstream ifs;
	int index = 0;

	ifs.open(FILENAME, ios::in);
	if (!ifs.is_open())
	{
		cout << "文件未打开" << endl;
	}
	while (ifs >> ID && ifs >> Name && ifs >> Dept)
	{
		Worker* worker = NULL;

		if (Dept == 1)
			worker = new Employee(ID, Name, Dept);
		else if (Dept == 2)
			worker = new Manager(ID, Name, Dept);
		else
			worker = new Employor(ID, Name, Dept);

		this->m_EmpArray[index] = worker;
		index++;
	}
	ifs.close();
}

void WorkerManager::ShowEmployor()
{
	if (this->FileIsEmpty)
	{
		cout << "文件不存在或记录为空" << endl;
	}
	else
	{
		for (int i = 0; i < this->m_EmpNum; i++)
		{
			this->m_EmpArray[i]->ShowInformation();
		}
	}
	system("pause");
	system("cls");
}

void WorkerManager::DeleteEmployor()
{
	int choice;
	int yes = 0;
	int ID;
	int del;
	string Name;
	cout << "请选择检索方式：1、姓名    2、ID" << endl;
	cin >> choice;
	switch (choice)
	{
	case 1:
		cout << "请输入离职员工的姓名" << endl;
		cin >> Name;

		while (true)
		{
			for (int i = 0; i < m_EmpNum; i++)
			{
				if (this->m_EmpArray[i]->m_Name == Name)
				{
					cout << "查询到";
					this->m_EmpArray[i]->ShowInformation();
					cout << "是否删除:1、是  2、否" << endl;
					cin >> del;
					if (del == 1)
					{
						for (int j = i; j < this->m_EmpNum - 1; j++)
						{
							this->m_EmpArray[j] = this->m_EmpArray[j + 1];
						}
						this->m_EmpNum--;
						this->Save();
						yes = 1;
					}
					else
					{
						return;
					}
				}
			}

			if (yes = 1)
			{
				cout << "删除成功" << endl;
				break;
			}
			cout << "输入错误，未找到此员工，请重新输入" << endl;
			cin >> ID;
		}
		break;
	case 2:
		cout << "请输入离职员工的ID" << endl;
		cin >> ID;

		while (true)
		{
			for (int i = 0; i < m_EmpNum; i++)
			{
				if (this->m_EmpArray[i]->m_ID == ID)
				{
					cout << "查询到";
					this->m_EmpArray[i]->ShowInformation();
					cout << "是否删除:1、是  2、否" << endl;
					cin >> del;
					if (del == 1)
					{
						for (int j = i; j < this->m_EmpNum - 1; j++)
						{
							this->m_EmpArray[j] = this->m_EmpArray[j + 1];
						}
						this->m_EmpNum--;
						this->Save();
						yes = 1;
					}
					else
					{
						return;
					}
				}
			}

			if (yes = 1)
			{
				cout << "删除成功" << endl;
				break;
			}
			cout << "输入错误，未找到此员工，请重新输入" << endl;
			cin >> ID;
		}
		break;
	}
	system("pause");
	system("cls");
}

void WorkerManager::ModifyEmployor()
{
	if (this->FileIsEmpty)
	{
		cout << "文件不存在或记录为空" << endl;
	}
	else
	{
		int choice;
		int yes = 0;
		int ID;
		int del;
		string Name;
		cout << "请选择检索方式：1、姓名    2、ID" << endl;
		cin >> choice;
		switch (choice)
		{
		case 1:
			cout << "请输入需要修改员工的姓名" << endl;
			cin >> Name;

			while (true)
			{
				for (int i = 0; i < m_EmpNum; i++)
				{
					if (this->m_EmpArray[i]->m_Name == Name)
					{
						cout << "查询到";
						this->m_EmpArray[i]->ShowInformation();
						cout << "是否修改:1、是  2、否" << endl;
						cin >> del;
						if (del == 1)
						{
							cout << "请输入修改后的ID" << endl;
							cin >> this->m_EmpArray[i]->m_ID;

							cout << "请输入修改后的姓名" << endl;
							cin >> this->m_EmpArray[i]->m_Name;

							cout << "请输入修改后的部门：1、员工  2、经理  3、老板" << endl;
							cin >> this->m_EmpArray[i]->m_DeptID;

							this->Save();
							yes = 1;
						}
						else
						{
							return;
						}
					}
				}

				if (yes = 1)
				{
					cout << "修改成功" << endl;
					break;
				}
				cout << "输入错误，未找到此员工，请重新输入" << endl;
				cin >> ID;
			}
			break;
		case 2:
			cout << "请输入需要修改员工的ID" << endl;
			cin >> ID;

			while (true)
			{
				for (int i = 0; i < m_EmpNum; i++)
				{
					if (this->m_EmpArray[i]->m_ID == ID)
					{
						cout << "查询到";
						this->m_EmpArray[i]->ShowInformation();
						cout << "是否修改:1、是  2、否" << endl;
						cin >> del;
						if (del == 1)
						{
							cout << "请输入修改后的ID" << endl;
							cin >> this->m_EmpArray[i]->m_ID;

							cout << "请输入修改后的姓名" << endl;
							cin >> this->m_EmpArray[i]->m_Name;

							cout << "请输入修改后的部门：1、员工  2、经理  3、老板" << endl;
							cin >> this->m_EmpArray[i]->m_DeptID;

							this->Save();
							yes = 1;
						}
						else
						{
							return;
						}
					}
				}

				if (yes = 1)
				{
					cout << "修改成功" << endl;
					break;
				}
				cout << "输入错误，未找到此员工，请重新输入" << endl;
				cin >> ID;
			}
			break;
		}
		system("pause");
		system("cls");
	}
}

void WorkerManager::SeekEmployor()
{
	if (this->FileIsEmpty)
	{
		cout << "文件不存在或记录为空" << endl;
	}
	else
	{
		int choice;
		int yes = 0;
		int ID;
		string Name;
		cout << "请选择检索方式：1、姓名    2、ID" << endl;
		cin >> choice;
		switch (choice)
		{
		case 1:
			cout << "请输入需要修改员工的姓名" << endl;
			cin >> Name;

			while (true)
			{
				for (int i = 0; i < m_EmpNum; i++)
				{
					if (this->m_EmpArray[i]->m_Name == Name)
					{
						cout << "查询到";
						this->m_EmpArray[i]->ShowInformation();
						yes = 1;

					}
				}

				if (yes = 1)
				{
					break;
				}
				cout << "输入错误，未找到此员工，请重新输入" << endl;
				cin >> ID;
			}
			break;
		case 2:
			cout << "请输入需要查找员工的ID" << endl;
			cin >> ID;

			while (true)
			{
				for (int i = 0; i < m_EmpNum; i++)
				{
					if (this->m_EmpArray[i]->m_ID == ID)
					{
						cout << "查询到";
						this->m_EmpArray[i]->ShowInformation();
						yes = 1;
					}
				}
				if (yes==1)
				{
					break;
				}
				cout << "输入错误，未找到此员工，请重新输入" << endl;
				cin >> ID;
			}
			break;
		}
		system("pause");
		system("cls");
	}
}

void WorkerManager::SortEmployor()
{
	if (this->FileIsEmpty)
	{
		cout << "文件不存在或记录为空" << endl;
	}
	else
	{
		cout << "请选择排序方式：1、按ID升序  2、按ID降序" << endl;
		int choice;
		cin >> choice;

		for (int i = 0; i < this->m_EmpNum; i++)
		{
			for (int j = 0; j < this->m_EmpNum - 1 - i; j++)
			{
				if (choice==1)
				{
					if (this->m_EmpArray[j]->m_ID> this->m_EmpArray[j+1]->m_ID)
					{
						Worker* temp = this->m_EmpArray[j];
						this->m_EmpArray[j] = this->m_EmpArray[j + 1];
						this->m_EmpArray[j + 1] = temp;
					}
				}
				else
				{
					if (this->m_EmpArray[j]->m_ID < this->m_EmpArray[j + 1]->m_ID)
					{
						Worker* temp = this->m_EmpArray[j];
						this->m_EmpArray[j] = this->m_EmpArray[j + 1];
						this->m_EmpArray[j + 1] = temp;
					}
				}
			}
		}
	}
	cout << "排序完成" << endl;
	this->Save();
	this->ShowEmployor();

	system("pause");
	system("cls");
}

void WorkerManager::CleanEmployor()
{
	cout << "确认清空？" << endl;
	cout << "1、确认" << endl;
	cout << "2、返回" << endl;
	
	int choice;
	cin >> choice;
	if (choice==1)
	{
		ofstream ofs(FILENAME, ios::trunc);
		ofs.close();

		//删除堆区每个职工对象
		if (this->m_EmpArray != NULL)
		{
			for (int i = 0; i < this->m_EmpNum; i++)
			{
				delete this->m_EmpArray[i];
				this->m_EmpArray[i] = NULL;
			}
		}

		//删除堆区数组指针
		delete[] this->m_EmpArray;
		this->m_EmpArray = NULL;
		this->m_EmpNum = 0;
		this->FileIsEmpty = true;

		cout << "清空成功" << endl;
	}
	system("pause");
	system("cls");
}

Employee::Employee(int ID, string name, int DeptID)
{
	this->m_ID = ID;
	this->m_Name = name;
	this->m_DeptID = DeptID;
}

void Employee::ShowInformation()
{
	cout << "职工编号" << this->m_ID << "\t职工姓名" << this->m_Name << "/t岗位" << this->GetDeptName() << "\t岗位职责：完成经理交给的任务" << endl;
}

string Employee::GetDeptName()
{
	return string("员工");
}

Employor::Employor(int ID, string name, int DeptID)
{
	this->m_ID = ID;
	this->m_Name = name;
	this->m_DeptID = DeptID;
}

void Employor::ShowInformation()
{
	cout << "职工编号" << this->m_ID << "\t职工姓名" << this->m_Name << "/t岗位" << this->GetDeptName() << "\t岗位职责：决定公司走向" << endl;
}

string Employor::GetDeptName()
{
	return string("老板");
}

Manager::Manager(int ID, string name, int DeptID)
{
	this->m_ID = ID;
	this->m_Name = name;
	this->m_DeptID = DeptID;
}

void Manager::ShowInformation()
{
	cout << "职工编号" << this->m_ID << "\t职工姓名" << this->m_Name << "/t岗位" << this->GetDeptName() << "\t岗位职责：给员工布置任务" << endl;
}

string Manager::GetDeptName()
{
	return string("经理");
}

WorkerManager::~WorkerManager()
{
	if (this->m_EmpArray != NULL)
	{
		for (int i = 0; i < this->m_EmpNum; i++)
		{
			if (this->m_EmpArray[i] != NULL)
			{
				delete this->m_EmpArray[i];
			}
		}
		delete[] this->m_EmpArray;
		this->m_EmpArray = NULL;
	}
}
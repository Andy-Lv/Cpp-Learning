#include <iostream>
#include<string>
#define MAX 1000
using namespace std;

//联系人结构体
struct Person
{
	string name;
	int sex;
	int age;
	string tel;
	string add;
};

//通讯录结构体
struct AddressBook
{
	Person person[MAX];
	int account;//记录通讯录中的人数
};

void ShowMenu()
{
	cout << "################################" << endl;
	cout << "#######  1、添加联系人   #######" << endl;
	cout << "#######  2、显示联系人   #######" << endl;
	cout << "#######  3、删除联系人   #######" << endl;
	cout << "#######  4、查找联系人   #######" << endl;
	cout << "#######  5、修改联系人   #######" << endl;
	cout << "#######  6、清空联系人   #######" << endl;
	cout << "#######  0、退出通讯录   #######" << endl;
	cout << "################################" << endl;
}

void addperson(AddressBook * addressbook)
{
	//判断通讯录中是否已满，如果满了就不再添加
	if (addressbook->account == MAX)
	{
		cout << "通讯录中人员已满，添加失败！" << endl;
		return;
	}
	else
	{
		cout << "请输入姓名" << endl;
		cin >> addressbook->person[addressbook->account].name;

		cout << "请输入性别：1、男   2、女" << endl;
		while (true)
		{
			int sex = 0;
			cin >> sex;
			if (sex == 1 || sex == 2)
			{
				addressbook->person[addressbook->account].sex = sex;
				break;
			}
			else
			{
				cout << "输入有误，请重新输入" << endl;
			}
		}
		
		cout << "请输入年龄" << endl;
		cin >> addressbook->person[addressbook->account].age;

		cout << "请输入电话" << endl;
		cin >> addressbook->person[addressbook->account].tel;

		cout << "请输入地址" << endl;
		cin >> addressbook->person[addressbook->account].add;
	}

	//更新通讯录人数
	addressbook->account++;
	cout << "添加成功" << endl;

	//添加成功之后暂停屏幕，按任意键之后清除屏幕
	system("pause");

	system("cls");

}

void showperson(AddressBook * addressbook)
{
	//判断通讯录中人数是否为0
	if (addressbook->account == 0)
	{
		cout << "当前无联系人" << endl;
	}
	else
	{
		for (int i = 0; i < addressbook->account; i++)
		{
			cout << "姓名：" << addressbook->person[i].age << "\t";
			cout << "性别：" << (addressbook->person[i].sex==1?"男":"女") << "\t";
			cout << "年龄：" << addressbook->person[i].age << "\t";
			cout << "电话：" << addressbook->person[i].tel << "\t";
			cout << "住址：" << addressbook->person[i].add << endl;
		}
	}
	system("pause");
	system("cls");
}

void deleteperson(AddressBook * addressbook)
{
	//展示所有的联系人
	if (addressbook->account == 0)
	{
		cout << "当前无联系人" << endl;
		return;
	}
	else
	{
		for (int i = 0; i < addressbook->account; i++)
		{
			cout << "姓名：" << addressbook->person[i].age << "\t";
			cout << "性别：" << (addressbook->person[i].sex == 1 ? "男" : "女") << "\t";
			cout << "年龄：" << addressbook->person[i].age << "\t";
			cout << "电话：" << addressbook->person[i].tel << "\t";
			cout << "住址：" << addressbook->person[i].add << endl;
		}
	}
	//判断联系人是否存在
	string name;
	int yes = 0;
	int del;
	cout << "请输入需要删除联系人的姓名" << endl;
	cin >> name;
	while (true)
	{
		for (int i = 0; i < addressbook->account; i++)
		{
			if (addressbook->person[i].name == name)
			{
				cout << "找到此人，请问是否要删除（请输入代号）   1：确认   2：取消" << endl;
				cin >> del;
				if (del == 1)//删除操作
				{
					for (int j = i; j < addressbook->account; j++)
					{
						//后面的数据覆盖前面的数据
						addressbook->person[j] = addressbook->person[j + 1];
						addressbook->account--;
					}
				}
				yes = 1;
				break;
			}
		}
		if (yes == 0)
		{
			cout << "输入错误,请重新输入" << endl;
			cin >> name;
		}
		else
		{
			break;
		}
	}
	system("pause");
	system("cls");
}

void findperson(AddressBook * addressbook)
{
	cout << "请输入您需要查找的联系人" << endl;
	string name;
	int yes = 0;
	cin >> name;
	while (true)
	{
		for (int i = 0; i < addressbook->account; i++)
		{
			if (addressbook->person[i].name == name)
			{
				cout << "姓名：" << addressbook->person[i].age << "\t";
				cout << "性别：" << (addressbook->person[i].sex == 1 ? "男" : "女") << "\t";
				cout << "年龄：" << addressbook->person[i].age << "\t";
				cout << "电话：" << addressbook->person[i].tel << "\t";
				cout << "住址：" << addressbook->person[i].add << endl;

				yes = 1;
				break;
			}
		}
		if (yes == 0)
		{
			cout << "输入错误,请重新输入" << endl;
			cin >> name;
		}
		else
		{
			break;
		}
	}
	system("pause");
	system("cls");
}

void modifyperson(AddressBook * addressbook)
{
	cout << "请输入您需要修改的联系人" << endl;
	string name;
	int yes = 0;
	cin >> name;
	while (true)
	{
		for (int i = 0; i < addressbook->account; i++)
		{
			if (addressbook->person[i].name == name)
			{
				cout << "当前此联系人信息为" << endl;
				cout << "姓名：" << addressbook->person[i].age << "\t";
				cout << "性别：" << (addressbook->person[i].sex == 1 ? "男" : "女") << "\t";
				cout << "年龄：" << addressbook->person[i].age << "\t";
				cout << "电话：" << addressbook->person[i].tel << "\t";
				cout << "住址：" << addressbook->person[i].add << endl;

				//修改姓名
				cout << "请输入修改后的姓名" << endl;
				string name1;
				cin >> name1;
				addressbook->person[i].name == name1;

				//修改年龄
				cout << "请输入修改后的年龄" << endl;
				int age;
				cin >> age;
				addressbook->person[i].age = age;

				//修改性别
				cout << "请输入修改后的性别：1、男   2、女" << endl;
				while (true)
				{
					int sex = 0;
					cin >> sex;
					if (sex == 1 || sex == 2)
					{
						addressbook->person[i].sex == sex;
						break;
					}
					else
					{
						cout << "输入有误，请重新输入" << endl;
					}
				}

				//修改电话
				cout << "请输入修改后的电话" << endl;
				string tel;
				cin >> tel;
				addressbook->person[i].tel == tel;

				//修改地址
				cout << "请输入修改后的地址" << endl;
				string add;
				cin >> add;
				addressbook->person[i].add == add;

				cout << "修改成功" << endl;
				cout << "修改后的联系人信息为" << endl;

				cout << "姓名：" << addressbook->person[i].age << "\t";
				cout << "性别：" << (addressbook->person[i].sex == 1 ? "男" : "女") << "\t";
				cout << "年龄：" << addressbook->person[i].age << "\t";
				cout << "电话：" << addressbook->person[i].tel << "\t";
				cout << "住址：" << addressbook->person[i].add << endl;

				yes = 1;
				break;
			}
		}
		if (yes == 0)
		{
			cout << "输入错误,请重新输入" << endl;
			cin >> name;
		}
		else
		{
			break;
		}
	}
	system("pause");
	system("cls");
}

void cleanperson(AddressBook * addressbook)
{
	addressbook->account = 0;
	cout << "通讯录已清空" << endl;
	system("pause");
	system("cls");
}
int main()
{
	//创建通讯录
	AddressBook addressbook;

	addressbook.account = 0;
	//初始化通讯录中当前的人数


	//创建用户选择的变量
	int select = 0;

	while (true)
	{
		//菜单调用
		ShowMenu();

		//用户选择功能
		cin >> select;

		switch (select)
		{
		case 1://添加联系人
			addperson(&addressbook);
			break;
		case 2://显示联系人
			showperson(&addressbook);
			break;
		case 3://删除联系人
			deleteperson(&addressbook);
			break;
		case 4://查找联系人
			findperson(&addressbook);
			break;
		case 5://修改联系人
			modifyperson(&addressbook);
			break;
		case 6://清空联系人
			cleanperson(&addressbook);
			break;
		case 0://退出通讯录
			cout << "欢迎下次使用" << endl;
			return 0;
			break;
		}
	}
	
	return 0; 
}
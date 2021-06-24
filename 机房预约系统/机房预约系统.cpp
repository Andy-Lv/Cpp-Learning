#include<iostream>
#include"Identity.h"

using namespace std;

int main()
{
	//接收用户的选择
	int select = 0;

	while (true)
	{
		cout << "===================欢迎来到机房预约系统===================" << endl;
		cout << "请输入您的身份:" << endl;
		cout << "             ------------------------------               " << endl << endl;
		cout << "            |          1、学生代表         |              " << endl << endl;
		cout << "            |          2、老    师         |              " << endl << endl;
		cout << "            |          3、管 理 员         |              " << endl << endl;
		cout << "            |          0、退    出         |              " << endl << endl;
		cout << "             ------------------------------               " << endl << endl;
		cout << "==========================================================" << endl;


		cin >> select;

		switch (select)
		{
		case 1://学生
			LoginIn(STUDENT_FILE, 1);
			break;
		case 2://老师
			LoginIn(TEACHER_FILE, 2);
			break;
		case 3://管理员
			LoginIn(ADMIN_FILE, 3);
			break;
		case 0://退出
			cout << "欢迎下次使用" << endl;

			system("pause");
			system("cls");

			return 0;
			break;
		default:
			cout << "输入有误，请重新输入" << endl;

			system("pause");
			system("cls");
			break;
		}
	}


	system("pause");
	return 0;
}
#include<iostream>
#include"Identity.h"

using namespace std;

int main()
{
	//�����û���ѡ��
	int select = 0;

	while (true)
	{
		cout << "===================��ӭ��������ԤԼϵͳ===================" << endl;
		cout << "�������������:" << endl;
		cout << "             ------------------------------               " << endl << endl;
		cout << "            |          1��ѧ������         |              " << endl << endl;
		cout << "            |          2����    ʦ         |              " << endl << endl;
		cout << "            |          3���� �� Ա         |              " << endl << endl;
		cout << "            |          0����    ��         |              " << endl << endl;
		cout << "             ------------------------------               " << endl << endl;
		cout << "==========================================================" << endl;


		cin >> select;

		switch (select)
		{
		case 1://ѧ��
			LoginIn(STUDENT_FILE, 1);
			break;
		case 2://��ʦ
			LoginIn(TEACHER_FILE, 2);
			break;
		case 3://����Ա
			LoginIn(ADMIN_FILE, 3);
			break;
		case 0://�˳�
			cout << "��ӭ�´�ʹ��" << endl;

			system("pause");
			system("cls");

			return 0;
			break;
		default:
			cout << "������������������" << endl;

			system("pause");
			system("cls");
			break;
		}
	}


	system("pause");
	return 0;
}
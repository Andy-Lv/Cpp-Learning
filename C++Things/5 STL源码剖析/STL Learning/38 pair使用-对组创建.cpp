#include<iostream>
#include<string>
using namespace std;

void tset()
{
	//��һ�ַ���
	pair<string, int>p("Tom", 20);

	cout << "����" << p.first << "  ����" << p.second << endl;

	//�ڶ��ַ���
	pair<string, int>p2 = make_pair("Jerry", 10);

	cout << "����" << p.first << "  ����" << p.second << endl;
}
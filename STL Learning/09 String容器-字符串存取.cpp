#include <iostream>
#include<string>
using namespace std;


void test1()
{
	string str = "hello";
	
	//ͨ��[]���ʵ����ַ�
	for (int i = 0; i < str.size(); i++)
	{
		cout << str[i] << " ";
	}

	//ͨ��at����
	for (int i = 0; i < str.size(); i++)
	{
		cout << str.at(i) << " ";
	}

	//�޸ĵ����ַ�
	str[0] = 'x';
	str.at(1) = 'x';
}
#include <iostream>
#include<string>
using namespace std;

void test()
{
	string str = "abcdef";
	string subStr = str.substr(1, 3);//��str�ĵ�1���ַ���ʼ��ȡ3���ַ�����0��ʼ��

	//��email�л�ȡ����
	string email = "zhangsan@sina.com";

	int pos = email.find('@');

	string name = email.substr(0, pos);
}
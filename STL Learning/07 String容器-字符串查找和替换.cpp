#include <iostream>
#include<string>
using namespace std;

//����

void test()
{
	string str1 = "abcdefg";
	int pos = str1.find(str1);//��0��ʼ��������3�����û�з���-1��
	int pos = str1.rfind(str1);//��������飬��0��ʼ������3
}
//�滻

void test1()
{
	string str1 = "abcdefg";

	str1.replace(1, 3, "1111");//��1��3���ַ��滻Ϊ�����1111
}
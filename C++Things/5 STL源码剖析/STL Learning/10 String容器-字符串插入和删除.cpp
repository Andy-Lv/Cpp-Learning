#include <iostream>
#include<string>
using namespace std;

void test()
{
	string str = "hello";
	//����
	str.insert(1, "111");//�ӵ�1��λ�ú��濪ʼ���������ַ�
	//ɾ��
	str.erase(1, 3);//�ӵ�һ��λ�ú��濪ʼɾ������
}
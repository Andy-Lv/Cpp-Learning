/*
	����
		string��C++�����ַ�������string��������һ����
	string��char*������
		char*��һ��ָ��
		string��һ���࣬���ڲ���װ��char*����������ַ�������һ��char*�͵�����
	�ص�
		string���ڲ���װ�˺ܶ��Ա����
		���磺find��copy��delete��insert��
		string����char*��������ڴ棬���õ��ĸ���Խ�����ȡֵԽ��ȣ������ڲ����и���	
*/

#include <iostream>
#include<string>
using namespace std;

void test()
{
	string s1;//Ĭ�Ϲ���

	const char* str = "hello world";
	string s2(str);

	string s3(s2);
	string s4(10, 'a');

}
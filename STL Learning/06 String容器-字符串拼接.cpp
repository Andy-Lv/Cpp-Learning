#include <iostream>
#include<string>
using namespace std;

void test()
{
	string str1 = "��";
	str1 += "�Ұ�����Ϸ";
	str1 += ':';

	string str2 = "������ҫ";
	str1 += str2;

	string str3 = "I";
	str3.append(" love");

	str3.append("game abcde",4);

	str3.append(str2);

	str3.append("game abcde", 4,3);//�ӵ�4����ʼ��ȡ3�����ǵô�0��ʼ��
}
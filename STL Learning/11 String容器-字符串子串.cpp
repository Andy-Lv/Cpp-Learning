#include <iostream>
#include<string>
using namespace std;

void test()
{
	string str = "abcdef";
	string subStr = str.substr(1, 3);//从str的第1个字符开始截取3个字符，从0开始数

	//从email中获取姓名
	string email = "zhangsan@sina.com";

	int pos = email.find('@');

	string name = email.substr(0, pos);
}
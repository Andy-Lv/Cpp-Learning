#include <iostream>
#include<string>
using namespace std;


void test1()
{
	string str = "hello";
	
	//通过[]访问单个字符
	for (int i = 0; i < str.size(); i++)
	{
		cout << str[i] << " ";
	}

	//通过at方法
	for (int i = 0; i < str.size(); i++)
	{
		cout << str.at(i) << " ";
	}

	//修改单个字符
	str[0] = 'x';
	str.at(1) = 'x';
}
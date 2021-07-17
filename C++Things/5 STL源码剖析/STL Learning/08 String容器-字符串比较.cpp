#include <iostream>
#include<string>
using namespace std;

void test1()
{
	string str1 = "hello";
	string str2 = "hello";

	if (str1.compare(str2)==0)//一个一个字符用ascii码值比较
	{
		cout << "str1等于str2" << endl;
	}
	else if (str1.compare(str2) > 0)
	{
		cout << "str1大于str2" << endl;
	}
	else
	{
		cout << "str1小于str2" << endl;
	}
}
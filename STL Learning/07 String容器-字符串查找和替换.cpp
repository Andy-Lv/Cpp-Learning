#include <iostream>
#include<string>
using namespace std;

//查找

void test()
{
	string str1 = "abcdefg";
	int pos = str1.find(str1);//从0开始数，返回3，如果没有返回-1；
	int pos = str1.rfind(str1);//从右往左查，从0开始，返回3
}
//替换

void test1()
{
	string str1 = "abcdefg";

	str1.replace(1, 3, "1111");//将1到3的字符替换为后面的1111
}
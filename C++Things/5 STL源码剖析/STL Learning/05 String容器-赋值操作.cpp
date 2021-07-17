#include <iostream>
#include<string>
using namespace std;


void test()
{
	string str1;
	str1 = "hello world";

	string str2;
	str2 = str1;

	string str3;
	str3 = 'a';

	string str4;
	str4.assign("hello world");

	string str5;
	str5.assign("hello world",5);//str5.assign(a,n),把a的前n个字符串赋值给str5

	string str6;
	str5.assign(str5);

	string str7;
	str7.assign(10,'w');
}
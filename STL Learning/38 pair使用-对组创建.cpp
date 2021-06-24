#include<iostream>
#include<string>
using namespace std;

void tset()
{
	//第一种方法
	pair<string, int>p("Tom", 20);

	cout << "姓名" << p.first << "  年龄" << p.second << endl;

	//第二种方法
	pair<string, int>p2 = make_pair("Jerry", 10);

	cout << "姓名" << p.first << "  年龄" << p.second << endl;
}
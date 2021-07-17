#include <iostream>
#include<string>
#include<deque>
using namespace std;


void printdeque(const deque<int>& d)//添加const使容器中的数据不可被修改
{
	for (deque<int>::const_iterator it = d.begin(); it != d.end(); it++)
	{
		cout << *it << " ";
	}
	cout << endl;
}
void test()
{
	deque<int>d1;
	for (int i = 0; i < 10; i++)
	{
		d1.push_back(i);
	}
	printdeque(d1);

	if (d1.empty())
	{
		cout << "d1为空" << endl;
	}
	else
	{
		cout << "d1不为空" << endl;
		cout << "d1的大小" << d1.size() << endl;//没有容量概念
	}

	//重新指定大小
	d1.resize(15);//默认用0填充
	d1.resize(15, 1);//用1来填充
}
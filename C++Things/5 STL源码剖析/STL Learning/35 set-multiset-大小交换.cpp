#include<iostream>
#include<set>
using namespace std;

void printset(set<int>& L)
{
	for (set<int>::const_iterator it = L.begin(); it != L.end(); it++)
	{
		cout << *it << endl;
	}
}

void test()
{
	set<int>s1;//插入数据只有insert方式
	s1.insert(10);
	s1.insert(20);
	s1.insert(40);
	s1.insert(50);
	s1.insert(40);
	s1.insert(30);

	//遍历容器
	printset(s1);

	//判断是否为空
	if (s1.empty())
	{
		cout << "是为空" << endl;
	}
	else
	{
		cout << "不为空" << endl;
		cout << "s1的大小为：" << s1.size() << endl;//set容器不允许有重新指定大小的操作
	}

	//交换
	set<int>s2;
	s2.insert(100);
	s2.insert(200);
	s2.insert(300);
	s2.insert(400);
	s2.insert(500);

	s1.swap(s2);
}

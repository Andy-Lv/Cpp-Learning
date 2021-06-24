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

	set<int>::iterator pos = s1.find(30);//若存在，返回该元素的迭代器，若不存在，则返回s1.end()

	if (pos!=s1.end())
	{
		cout << "找到元素" << *pos << endl;
	}
	else
	{
		cout << "未找到元素" << endl;
	}

	//统计
	int num = s1.count(40);//输出2
}
#include<iostream>
#include<set>
using namespace std;

void test()
{
	set<int>s;

	pair<set<int>::iterator, bool> ret = s.insert(10);

	if (ret.second)
	{
		cout << "第一次插入成功" << endl;
	}
	else
	{
		cout << "第一次插入失败" << endl;
	}

	multiset<int>ms;

	//允许插入重复值
	ms.insert(10);
	ms.insert(10);

	for (multiset<int>::iterator it = ms.begin(); it != ms.end(); it++)
	{
		cout << *it << " ";
	}
}
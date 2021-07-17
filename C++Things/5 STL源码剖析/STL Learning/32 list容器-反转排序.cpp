#include<iostream>
#include<list>
#include<algorithm>
using namespace std;

void printlist(list<int>& L)
{
	for (list<int>::const_iterator it = L.begin(); it != L.end(); it++)
	{
		cout << *it << endl;
	}
}

bool mycompare(int v1, int v2)
{
	return v1 > v2;
}
void test()
{
	list<int>L1;

	L1.push_back(20);
	L1.push_back(40);
	L1.push_back(10);
	L1.push_back(30);
	L1.push_back(50);

	printlist(L1);

	//反转
	L1.reverse();

	//排序
	sort(L1.begin(), L1.end());//会报错，因为不能随机访问，不可以使用标准算法

	//不支持随机访问的迭代器的容器给i，内部会提供一些对应的算法
	L1.sort();

	//反排序
	L1.sort(mycompare);
}
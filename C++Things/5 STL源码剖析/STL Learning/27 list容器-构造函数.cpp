//链表
//组成：由一系列结点组成
//结点的组成：一个是储存数据的数据域，另一个是储存下一个节点地址的指针域
//优点：可以对任意位置进行快速进行插入和删除元素
//缺点：对容器遍历的速度没有数组快
//链表的存储方式并不是连续的内存空间，因此链表list中的迭代器只支持前移和后移，属于双向迭代器
#include<iostream>
#include<list>
using namespace std;

void printlist(list<int> &L)
{
	for (list<int>::const_iterator it = L.begin(); it != L.end(); it++)
	{
		cout << *it << endl;
	}
}
void test()
{
	list<int>L1;

	L1.push_back(10);
	L1.push_back(20);
	L1.push_back(30);
	L1.push_back(40);
	L1.push_back(50);

	printlist(L1);

	list<int>L2(L1.begin(), L1.end());

	list<int>L3(L2);

	list<int>L4(10, 1000);
}
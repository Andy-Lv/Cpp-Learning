#include<iostream>
#include<list>
using namespace std;

void printlist(list<int>& L)
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

	//不支持[]和at来访问list容器中的元素
	//list本质是链表，不是用连续的线性空间存储数据，迭代器也是不支持随机访问的

	cout << "第一个元素为" << L1.front() << endl;
	cout << "最后一个元素为" << L1.back() << endl;

	//验证迭代器是不支持随机访问的

	list<int>::iterator it = L1.begin();
	it++;//支持双向
	it--;
	//it=it+1  不支持随机访问

}
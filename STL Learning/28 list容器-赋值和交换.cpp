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

	list<int>L2;
	L2 = L1;

	list<int>L3;
	L3.assign(L1.begin(), L1.end());

	list<int>L4;
	L4.assign(10,100);

	//½»»»
	L1.swap(L4);
}

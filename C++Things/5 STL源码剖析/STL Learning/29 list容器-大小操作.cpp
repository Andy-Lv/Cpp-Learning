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

	//�ж������Ƿ�Ϊ��
	if (L1.empty())
	{
		cout << "L1Ϊ��" << endl;
	}
	else
	{
		cout << "L1��Ϊ��" << endl;
		cout << "L1�Ĵ�СΪ" << L1.size() << endl;
	}

	//����ָ����С
	L1.resize(10, 1000);

	L1.resize(2);
}
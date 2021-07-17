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

	//ͷ��
	L1.push_front(100);
	L1.push_front(200);
	L1.push_front(300);

	//βɾ
	L1.pop_back();

	//ͷɾ
	L1.pop_front();

	//insert����
	L1.insert(L1.begin(), 1000);

	list<int>::iterator it = L1.begin();
	L1.insert(++it, 1000);

	//ɾ��
	it = L1.begin();
	L1.erase(++it);

	L1.remove(1000);//������ƥ���ֵ��ɾ��
}

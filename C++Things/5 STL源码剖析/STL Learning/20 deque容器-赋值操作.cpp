#include <iostream>
#include<string>
#include<deque>
using namespace std;


void printdeque(const deque<int>& d)//���constʹ�����е����ݲ��ɱ��޸�
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

	//operator��ֵ
	deque<int>d2;
	d2 = d1;

	//assign��ֵ
	deque<int>d3;
	d3.assign(d1.begin(), d1.end());

	deque<int>d4;
	d4.assign(10, 100);
}
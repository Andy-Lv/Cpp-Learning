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

	if (d1.empty())
	{
		cout << "d1Ϊ��" << endl;
	}
	else
	{
		cout << "d1��Ϊ��" << endl;
		cout << "d1�Ĵ�С" << d1.size() << endl;//û����������
	}

	//����ָ����С
	d1.resize(15);//Ĭ����0���
	d1.resize(15, 1);//��1�����
}
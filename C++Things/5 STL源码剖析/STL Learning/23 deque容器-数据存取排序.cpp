#include <iostream>
#include<string>
#include<deque>
#include<algorithm>
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

	//ͨ��[]����
	for (int i = 0; i < d1.size(); i++)
	{
		cout << d1[i] << " ";
	}
	
	//ͨ��at����
	for (int i = 0; i < d1.size(); i++)
	{
		cout << d1.at(i) << " ";
	}

	cout << "��һ��Ԫ����" << d1.front() << endl;
	cout << "���һ��Ԫ����" << d1.back() << endl;

	//����
	deque<int>d2;
	d2.push_back(10);
	d2.push_back(20);
	d2.push_back(30);
	d2.push_front(100);
	d2.push_front(200);
	d2.push_front(300);//300��200��100��10��20��30
	
	sort(d2.begin(), d2.end());
	//���� Ĭ����������Ǵ�С��������
	//����֧��������ʵĵ�����������������������sory�㷨ֱ�Ӷ����������
	//vector����Ҳ��������sort��������
}
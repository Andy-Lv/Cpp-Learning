#include<iostream>
#include<set>
using namespace std;

void printset(set<int>& L)
{
	for (set<int>::const_iterator it = L.begin(); it != L.end(); it++)
	{
		cout << *it << endl;
	}
}

void test()
{
	set<int>s1;//��������ֻ��insert��ʽ
	s1.insert(10);
	s1.insert(20);
	s1.insert(40);
	s1.insert(50);
	s1.insert(40);
	s1.insert(30);

	//��������
	printset(s1);

	set<int>::iterator pos = s1.find(30);//�����ڣ����ظ�Ԫ�صĵ��������������ڣ��򷵻�s1.end()

	if (pos!=s1.end())
	{
		cout << "�ҵ�Ԫ��" << *pos << endl;
	}
	else
	{
		cout << "δ�ҵ�Ԫ��" << endl;
	}

	//ͳ��
	int num = s1.count(40);//���2
}
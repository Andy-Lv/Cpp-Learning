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

	//�ж��Ƿ�Ϊ��
	if (s1.empty())
	{
		cout << "��Ϊ��" << endl;
	}
	else
	{
		cout << "��Ϊ��" << endl;
		cout << "s1�Ĵ�СΪ��" << s1.size() << endl;//set����������������ָ����С�Ĳ���
	}

	//����
	set<int>s2;
	s2.insert(100);
	s2.insert(200);
	s2.insert(300);
	s2.insert(400);
	s2.insert(500);

	s1.swap(s2);
}

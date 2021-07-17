/*
set�Ļ������
	����Ԫ�ض����ڲ���ʱ�Զ�������
���ʣ�
	set/multiset���ڹ���ʽ�������ײ�ṹ�Ƕ�����ʵ��

	set���������������ظ���Ԫ��
	multiset�������������ظ���Ԫ��
*/
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
	printset(s1);//���10\20\30\40\50,set���Զ���������Ԫ�����򣬲��Ҳ���������ظ�Ԫ�أ��ظ���Ԫ��ֻ����һ��

	set<int>s2(s1);

	set<int>s3;
	s3 = s2;
}
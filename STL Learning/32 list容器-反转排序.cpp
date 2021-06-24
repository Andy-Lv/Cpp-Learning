#include<iostream>
#include<list>
#include<algorithm>
using namespace std;

void printlist(list<int>& L)
{
	for (list<int>::const_iterator it = L.begin(); it != L.end(); it++)
	{
		cout << *it << endl;
	}
}

bool mycompare(int v1, int v2)
{
	return v1 > v2;
}
void test()
{
	list<int>L1;

	L1.push_back(20);
	L1.push_back(40);
	L1.push_back(10);
	L1.push_back(30);
	L1.push_back(50);

	printlist(L1);

	//��ת
	L1.reverse();

	//����
	sort(L1.begin(), L1.end());//�ᱨ����Ϊ����������ʣ�������ʹ�ñ�׼�㷨

	//��֧��������ʵĵ�������������i���ڲ����ṩһЩ��Ӧ���㷨
	L1.sort();

	//������
	L1.sort(mycompare);
}
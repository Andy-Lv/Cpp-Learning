#include<iostream>
#include<set>
using namespace std;

void test()
{
	set<int>s;

	pair<set<int>::iterator, bool> ret = s.insert(10);

	if (ret.second)
	{
		cout << "��һ�β���ɹ�" << endl;
	}
	else
	{
		cout << "��һ�β���ʧ��" << endl;
	}

	multiset<int>ms;

	//��������ظ�ֵ
	ms.insert(10);
	ms.insert(10);

	for (multiset<int>::iterator it = ms.begin(); it != ms.end(); it++)
	{
		cout << *it << " ";
	}
}
#include<iostream>
#include<map>

using namespace std;

void printmap(map<int, int>& m)
{
	for (map<int, int>::iterator it = m.begin(); it != m.end(); it++)
	{
		cout << "Key=" << (*it).first << " value" << it->second << endl;
	}
}
void test()
{
	//����map
	map<int, int>m;

	m.insert(pair<int, int>(1, 10));
	m.insert(pair<int, int>(2, 20));
	m.insert(pair<int, int>(3, 30));
	m.insert(pair<int, int>(4, 40));
	m.insert(pair<int, int>(5, 50));

	printmap(m);

	if (m.empty())
	{
		cout << "mΪ��" << endl;
	}
	else
	{
		cout << "m��Ϊ��" << endl;
		cout << "m�Ĵ�СΪ��" << m.size() << endl;
	}

	map<int, int>m2;

	m2.insert(pair<int, int>(6, 100));
	m2.insert(pair<int, int>(7, 200));
	m2.insert(pair<int, int>(8, 300));
	m2.insert(pair<int, int>(9, 400));
	m2.insert(pair<int, int>(5, 500));

	//����
	m.swap(m2);
}
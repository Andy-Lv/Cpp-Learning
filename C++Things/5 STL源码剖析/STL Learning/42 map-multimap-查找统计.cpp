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


	//insert����
	m.insert(pair<int, int>(1, 10));
	m.insert(pair<int, int>(2, 20));
	m.insert(pair<int, int>(3, 30));
	m.insert(pair<int, int>(4, 40));
	m.insert(pair<int, int>(5, 50));

	map<int, int>::iterator pos = m.find(3);//����ҵ����򷵻ظõ����������δ�ҵ����򷵻�m.end()

	if (pos!=m.end())
	{
		cout << "�ҵ�Ԫ��key=" << pos->first << " value=" << pos->second << endl;
	}
	else
	{
		cout << "δ�ҵ�Ԫ��" << endl;
	}

	//ͳ��

	int num = m.count(3);//map��ͳ�Ƶ�ֵҪô0��Ҫô1����Ϊmao�в��������ظ���key��multimap��һ���������дӷ��key
}
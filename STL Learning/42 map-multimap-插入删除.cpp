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

	//
	m.insert(make_pair(2, 20));

	m.insert(map<int, int>::value_type(3, 30));
	
	m[4] = 40;

	//[]��������key������value
	cout << m[4] << endl;

	//ɾ��
	m.erase(m.begin());

	m.erase(3);//����key��ɾ��

	m.erase(m.begin(), m.end());
}
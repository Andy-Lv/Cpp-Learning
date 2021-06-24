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

class mycompare
{
public:
	bool operator()(int v1, int v2)
	{
		return v1 > v2;
	}
};

void test()
{
	//����map
	map<int, int, mycompare>m;


	//insert����,Ĭ����key����
	m.insert(pair<int, int>(1, 10));
	m.insert(pair<int, int>(2, 20));
	m.insert(pair<int, int>(3, 30));
	m.insert(pair<int, int>(4, 40));
	m.insert(pair<int, int>(5, 50));

	for (map<int,int, mycompare>::iterator it = m.begin(); it!=m.end(); it++)
	{
		cout << "Key=" << (*it).first << " value" << it->second << endl;
	}
}
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
	//创建map
	map<int, int>m;


	//insert插入
	m.insert(pair<int, int>(1, 10));
	m.insert(pair<int, int>(2, 20));
	m.insert(pair<int, int>(3, 30));
	m.insert(pair<int, int>(4, 40));
	m.insert(pair<int, int>(5, 50));

	map<int, int>::iterator pos = m.find(3);//如果找到，则返回该迭代器，如果未找到，则返回m.end()

	if (pos!=m.end())
	{
		cout << "找到元素key=" << pos->first << " value=" << pos->second << endl;
	}
	else
	{
		cout << "未找到元素" << endl;
	}

	//统计

	int num = m.count(3);//map中统计的值要么0，要么1，因为mao中不允许有重复的key，multimap不一样，允许有从夫的key
}
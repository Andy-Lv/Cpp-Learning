/*
map中所有元素都是pair
pair中第一个元素为键值key，起到索引作用，第二个元素为实值value
所有元素都会根据元素的key进行自动排序

map/multimap属于关联式容器，底层结构是用二叉树实现

可以根据key迅速找到value值

map不允许容器中有重复key值元素
multimap允许容器中有重复key值元素
*/

#include<iostream>
#include<map>

using namespace std;

void printmap(map<int, int>& m)
{
	for (map<int,int>::iterator it = m.begin(); it != m.end(); it++)
	{
		cout << "Key=" << (*it).first << " value" << it->second << endl;
	}
}
void test()
{
	//创建map
	map<int, int>m;

	m.insert(pair<int, int>(1, 10));
	m.insert(pair<int, int>(2, 20));
	m.insert(pair<int, int>(3, 30));
	m.insert(pair<int, int>(4, 40));
	m.insert(pair<int, int>(5, 50));
}
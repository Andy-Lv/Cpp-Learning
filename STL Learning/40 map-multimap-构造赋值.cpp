/*
map������Ԫ�ض���pair
pair�е�һ��Ԫ��Ϊ��ֵkey�����������ã��ڶ���Ԫ��Ϊʵֵvalue
����Ԫ�ض������Ԫ�ص�key�����Զ�����

map/multimap���ڹ���ʽ�������ײ�ṹ���ö�����ʵ��

���Ը���keyѸ���ҵ�valueֵ

map���������������ظ�keyֵԪ��
multimap�������������ظ�keyֵԪ��
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
	//����map
	map<int, int>m;

	m.insert(pair<int, int>(1, 10));
	m.insert(pair<int, int>(2, 20));
	m.insert(pair<int, int>(3, 30));
	m.insert(pair<int, int>(4, 40));
	m.insert(pair<int, int>(5, 50));
}
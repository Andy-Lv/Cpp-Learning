#include <iostream>
#include<string>
#include<vector>
using namespace std;

void printvector(vector<int>v)
{
	for (vector<int>::iterator it = v.begin(); it != v.end(); it++)
	{
		cout << *it << " ";
	}
	cout << endl;
}

void test()
{
	vector<int>v1;
	for (int i = 0; i < 10; i++)
	{
		v1.push_back(i);
	}

	vector<int>v2;
	for (int i = 10; i > 0; i--)
	{
		v2.push_back(i);
	}

	v1.swap(v2);//����vector����Ԫ�ػ���������Ԫ�ص�˳��
}

void test()
{
	vector<int>v1;
	for (int i = 0; i < 100000; i++)
	{
		v1.push_back(i);
	}

	cout << "v1������Ϊ��" << v1.capacity() << endl;//130000
	cout << "v1�Ĵ�СΪ��" << v1.size() << endl;//100000

	v1.resize(3);
	cout << "v1������Ϊ��" << v1.capacity() << endl;//130000
	cout << "v1�Ĵ�СΪ��" << v1.size() << endl;//3

	//����swap�����ڴ�
	vector<int>(v1).swap(v1);//vector<int>(v1)Ϊ�������󣬰���V1�Ĵ�С����ʼ���������Ȼ��swap������ָ�뽻������˾�ʵ���ڴ�����������һ�����ϵͳ���Զ�����
	cout << "v1������Ϊ��" << v1.capacity() << endl;//3
	cout << "v1�Ĵ�СΪ��" << v1.size() << endl;//3
}
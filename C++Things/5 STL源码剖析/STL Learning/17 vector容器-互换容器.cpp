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

	v1.swap(v2);//两个vector容器元素互换，包括元素的顺序
}

void test()
{
	vector<int>v1;
	for (int i = 0; i < 100000; i++)
	{
		v1.push_back(i);
	}

	cout << "v1的容量为：" << v1.capacity() << endl;//130000
	cout << "v1的大小为：" << v1.size() << endl;//100000

	v1.resize(3);
	cout << "v1的容量为：" << v1.capacity() << endl;//130000
	cout << "v1的大小为：" << v1.size() << endl;//3

	//巧用swap收缩内存
	vector<int>(v1).swap(v1);//vector<int>(v1)为匿名对象，按照V1的大小来初始化这个对象，然后swap来进行指针交换，因此就实现内存收缩，另外一个大的系统会自动回收
	cout << "v1的容量为：" << v1.capacity() << endl;//3
	cout << "v1的大小为：" << v1.size() << endl;//3
}
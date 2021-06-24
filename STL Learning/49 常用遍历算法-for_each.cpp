#include<iostream>
#include<functional>
#include<vector>
#include<algorithm>
using namespace std;

void print01(int val)
{
	cout << val << " ";
}

class print02
{
public:
	void operator()(int val)
	{
		cout << val << " ";
	}
};
void test()
{
	vector<int>v;
	for (int i = 0; i < 10; i++)
	{
		v.push_back(i);
	}

	//for_each 遍历操作
	for_each(v.begin(), v.end(), print01);//普通函数做遍历操作

	for_each(v.begin(), v.end(), print02());//仿函数做遍历操作
}
#include<iostream>
#include<functional>
#include<vector>
#include<algorithm>
#include<string>
using namespace std;

//二分查找法
void test()
{
	vector<int>v;
	for (int i = 0; i < 10; i++)
	{
		v.push_back(i);
	}

	//查找容器中是否有9元素

	//注意，容器必须是有序数列，如果是无序序列，则结果未知
	bool ret = binary_search(v.begin(), v.end(), 9);
}
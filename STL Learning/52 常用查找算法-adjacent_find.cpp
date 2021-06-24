#include<iostream>
#include<functional>
#include<vector>
#include<algorithm>
#include<string>
using namespace std;


//常用查找算法adjacent_find，寻找相邻重复元素
void test()
{
	vector<int>v;
	v.push_back(0);
	v.push_back(2);
	v.push_back(0);
	v.push_back(3);
	v.push_back(1);
	v.push_back(4);
	v.push_back(3);
	v.push_back(3);

	vector<int>::iterator pos = adjacent_find(v.begin(), v.end());
	if (pos == v.end())
	{
		cout << "没有找到" << endl;
	}
	else
	{
		cout << "找到" << *pos << endl;//输出3
	}
}
#include<iostream>
#include<functional>
#include<vector>
#include<algorithm>
#include<string>
using namespace std;

//merge 将两个容器合并到新的容器中

void test()
{
	vector<int>v1;
	vector<int>v2;
	for (int i = 0; i < 10; i++)
	{
		v1.push_back(i);
		v2.push_back(i + 1);
	}

	vector<int>vTarget;//目标容器

	vTarget.resize(v1.size() + v2.size());//提前分配空间

	merge(v1.begin(), v1.end(), v2.begin(), v2.end(), vTarget.begin());
}
#include<iostream>
#include<functional>
#include<vector>
#include<algorithm>
#include<string>
#include<numeric>
using namespace std;

//accumulate 计算容器内区间总和    #include<numeric>

void test()
{
	vector<int>v1;
	vector<int>v2;

	for (int i = 0; i < 10; i++)
	{
		v1.push_back(i);
		v2.push_back(i + 1);
	}

	int total = accumulate(v1.begin(), v1.end(), 0);//0为起始累加值，可以替换
}
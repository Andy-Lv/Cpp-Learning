#include<iostream>
#include<functional>
#include<vector>
#include<algorithm>
#include<string>
using namespace std;

void myPrint(int val)
{
	cout << val << " ";
}

void test()
{
	vector<int>v;
	for (int i = 0; i < 10; i++)
	{
		v.push_back(i);
	}

	//利用洗牌算法打乱顺序
	random_shuffle(v.begin(), v.end());

	for_each(v.begin(), v.end(),myPrint);
}
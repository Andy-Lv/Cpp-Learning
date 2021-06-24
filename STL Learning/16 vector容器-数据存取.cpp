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

	//利用[]访问元素
	for (int i = 0; i < v1.size(); i++)
	{
		cout << v1[i] << endl;
	}

	//利用at访问元素
	for (int i = 0; i < v1.size(); i++)
	{
		cout << v1.at(i) << endl;
	}

	//获取第一个元素
	cout << v1.front() << endl;
	//获取最后一个元素
	cout << v1.back() << endl;

}


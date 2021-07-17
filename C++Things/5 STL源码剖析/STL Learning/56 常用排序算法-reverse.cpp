#include<iostream>
#include<functional>
#include<vector>
#include<algorithm>
#include<string>
using namespace std;

//reverse，将容器中的元素反转

void test()
{
	vector<int>v1;
	for (int i = 0; i < 10; i++)
	{
		v1.push_back(i);
	}

	reverse(v1.begin(), v1.end());
}
#include<iostream>
#include<functional>
#include<vector>
#include<algorithm>
#include<string>
using namespace std;

//merge �����������ϲ����µ�������

void test()
{
	vector<int>v1;
	vector<int>v2;
	for (int i = 0; i < 10; i++)
	{
		v1.push_back(i);
		v2.push_back(i + 1);
	}

	vector<int>vTarget;//Ŀ������

	vTarget.resize(v1.size() + v2.size());//��ǰ����ռ�

	merge(v1.begin(), v1.end(), v2.begin(), v2.end(), vTarget.begin());
}
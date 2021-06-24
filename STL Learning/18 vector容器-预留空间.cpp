#include <iostream>
#include<string>
#include<vector>
using namespace std;

void test()
{
	vector<int>v;

	//使开辟次数为1
	v.reserve(100000);//预留空间，提示空间数量级很大，预留len个元素长度，预留空间不初始化，元素不可访问

	int num = 0;//统计开辟次数
	int* p = NULL;
	for (int i = 0; i < 100000; i++)
	{
		v.push_back(i);

		if (p!=&v[0])//验证为动态开辟，不是在原有基础上继续开辟空间
		{
			p = &v[0];
			num++;
		}
	}

}
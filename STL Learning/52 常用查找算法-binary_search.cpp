#include<iostream>
#include<functional>
#include<vector>
#include<algorithm>
#include<string>
using namespace std;

//���ֲ��ҷ�
void test()
{
	vector<int>v;
	for (int i = 0; i < 10; i++)
	{
		v.push_back(i);
	}

	//�����������Ƿ���9Ԫ��

	//ע�⣬�����������������У�������������У�����δ֪
	bool ret = binary_search(v.begin(), v.end(), 9);
}
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
		v1.push_back(1);
	}
	printvector(v1);

	//��ֵ
	vector<int>v2 = v1;

	vector<int>v3;
	v3.assign(v1.begin(), v1.end());
	printvector(v1);

	//n��element��ʽ��ֵ
	vector<int>v4;
	v4.assign(10, 100);//10��100
}
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

	//����[]����Ԫ��
	for (int i = 0; i < v1.size(); i++)
	{
		cout << v1[i] << endl;
	}

	//����at����Ԫ��
	for (int i = 0; i < v1.size(); i++)
	{
		cout << v1.at(i) << endl;
	}

	//��ȡ��һ��Ԫ��
	cout << v1.front() << endl;
	//��ȡ���һ��Ԫ��
	cout << v1.back() << endl;

}


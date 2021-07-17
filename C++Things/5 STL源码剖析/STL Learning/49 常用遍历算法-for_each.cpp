#include<iostream>
#include<functional>
#include<vector>
#include<algorithm>
using namespace std;

void print01(int val)
{
	cout << val << " ";
}

class print02
{
public:
	void operator()(int val)
	{
		cout << val << " ";
	}
};
void test()
{
	vector<int>v;
	for (int i = 0; i < 10; i++)
	{
		v.push_back(i);
	}

	//for_each ��������
	for_each(v.begin(), v.end(), print01);//��ͨ��������������

	for_each(v.begin(), v.end(), print02());//�º�������������
}
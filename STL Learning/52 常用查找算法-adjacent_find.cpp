#include<iostream>
#include<functional>
#include<vector>
#include<algorithm>
#include<string>
using namespace std;


//���ò����㷨adjacent_find��Ѱ�������ظ�Ԫ��
void test()
{
	vector<int>v;
	v.push_back(0);
	v.push_back(2);
	v.push_back(0);
	v.push_back(3);
	v.push_back(1);
	v.push_back(4);
	v.push_back(3);
	v.push_back(3);

	vector<int>::iterator pos = adjacent_find(v.begin(), v.end());
	if (pos == v.end())
	{
		cout << "û���ҵ�" << endl;
	}
	else
	{
		cout << "�ҵ�" << *pos << endl;//���3
	}
}
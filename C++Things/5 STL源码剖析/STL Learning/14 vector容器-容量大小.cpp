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

	if (v1.empty())//为真，代表容器为空
	{
		cout << "v1为空" << endl;
	}
	else
	{
		cout << "v1不为空" << endl;
		cout << "v1容量为" << v1.capacity() << endl;
		cout << "v1的大小是" << v1.size() << endl;
	}

	//重新指定大小
	v1.resize(15);
	printvector(v1);//指定空间过长，默认用0来填充位置指定长为resize（15，100）即为用100来填充
	v1.resize(5);//指定空间过短，则多余部分会被删除
}
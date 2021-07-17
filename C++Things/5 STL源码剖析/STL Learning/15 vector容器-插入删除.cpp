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

	printvector(v1);

	//尾插
	v1.pop_back();//删除最后一个元素
	printvector(v1);

	//插入
	v1.insert(v1.begin(), 100);//第一个元素前面插入100，即100在begin位置
	printvector(v1);

	v1.insert(v1.begin(),2, 100);//第一个元素前面插入2个100，即100在begin位置
	printvector(v1);

	//删除
	v1.erase(v1.begin());
	v1.erase(v1.begin(), v1.end());//相当于v1.clear（）
}
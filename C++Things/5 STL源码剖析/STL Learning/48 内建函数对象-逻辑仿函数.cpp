/*
	STL内建了一些函数对象

	分类：
	算数仿函数
	关系仿函数
	逻辑仿函数

	用法：
	这些仿函数所产生的对象，用法和一般函数完全相同
	使用内奸函数对象，需要引入头文件#include<functional>
*/

/*
	逻辑仿函数
	仿函数原型
	template<<class T> bool logical_and<T>             逻辑与
	template<<class T> bool logical_or<T>              逻辑或
	template<<class T> bool logical_not<T>             逻辑非
*/

#include<iostream>
#include<functional>
#include<vector>
#include<algorithm>
using namespace std;

void test()
{
	vector<bool>v;
	v.push_back(true);
	v.push_back(false);
	v.push_back(true);
	v.push_back(false);
	v.push_back(true);

	//利用逻辑非，将容器v搬运到v2中，并执行取反操作

	vector<bool>v2;
	v2.resize(v.size());

	transform(v.begin(), v.end(), v2.begin(), logical_not<bool>());//前两个参数是原来容器的起止点，第三个参数是目标容器的起点，最后一个参数是仿函数
}
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
	关系仿函数
	仿函数原型
	template<<class T> bool equal_to<T>             等于
	template<<class T> bool not_equal_to<T>         不等于
	template<<class T> bool greater<T>              大于
	template<<class T> bool greater_equal<T>        大于等于
	template<<class T> bool less<T>                 小于
	template<<class T> bool les_equal<T>            小于等于

*/

#include<iostream>
#include<functional>
#include<vector>
#include<algorithm>
using namespace std;

void test()
{
	vector<int>v;
	v.push_back(10);
	v.push_back(40);
	v.push_back(20);
	v.push_back(30);
	v.push_back(50);

	sort(v.begin(), v.end(), greater<int>());

}
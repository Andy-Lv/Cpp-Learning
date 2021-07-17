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
	算数仿函数
	实现四则运算
	其中negate是一元运算，其他都是二元运算
	仿函数原型
	template<<class T> T plus<T>             加法仿函数
	template<<class T> T minus<T>            减法仿函数
	template<<class T> T multiplies<T>       乘法仿函数
	template<<class T> T divides<T>          除法仿函数
	template<<class T> T modulus<T>          取模仿函数
	template<<class T> T negate<T>           取反仿函数

*/

#include<iostream>
#include<functional>
using namespace std;

void test()
{
	negate<int>n;//negate 一元仿函数 取反仿函数
	cout << n(50);//输出-50

	plus<int>p;//plus 二元仿函数 加法仿函数，只需写一个参数类型，plus只允许同种类型参数相加
	cout << p(10, 20);//输出30
}
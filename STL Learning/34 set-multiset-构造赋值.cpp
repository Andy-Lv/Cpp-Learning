/*
set的基本概念：
	所有元素都会在插入时自动被排序
本质：
	set/multiset属于关联式容器，底层结构是二叉树实现

	set不允许容器中有重复的元素
	multiset允许容器中有重复的元素
*/
#include<iostream>
#include<set>
using namespace std;

void printset(set<int>& L)
{
	for (set<int>::const_iterator it = L.begin(); it != L.end(); it++)
	{
		cout << *it << endl;
	}
}

void test()
{
	set<int>s1;//插入数据只有insert方式
	s1.insert(10);
	s1.insert(20);
	s1.insert(40);
	s1.insert(50);
	s1.insert(40);
	s1.insert(30);

	//遍历容器
	printset(s1);//输出10\20\30\40\50,set会自动将容器中元素排序，并且不允许存在重复元素，重复的元素只出现一次

	set<int>s2(s1);

	set<int>s3;
	s3 = s2;
}
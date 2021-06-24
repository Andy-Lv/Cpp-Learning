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
	printset(s1);

	//删除
	s1.erase(s1.begin());

	//删除重载版本
	s1.erase(30);

	//清除
	s1.erase(s1.begin(), s1.end());
	s1.clear();//两者作用相同

}
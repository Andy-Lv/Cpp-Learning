/*
	常用查找算法
	find			查找元素  找到返回指定元素迭代器，找不到返回end
	find_if			按条件查找元素
	adjacent_find   查找相邻重复元素
	binary_search   二分查找法
	count			统计元素个数
	count_if		按条件统计元素个数
*/

#include<iostream>
#include<functional>
#include<vector>
#include<algorithm>
#include<string>
using namespace std;

//查找内置数据类型
void find_test()
{
	vector<int>v;
	for (int i = 0; i < 10; i++)
	{
		v.push_back(i);
	}

	vector<int>::iterator it = find(v.begin(), v.end(), 5);
	if (it==v.end())
	{
		cout << "没有找到" << endl;
	}
	else
	{
		cout << "找到" << *it << endl;
	}
}

class Person
{
public:
	Person(string name, int age)
	{
		this->m_name = name;
		this->m_age = age;
	}
	
	bool operator==(const Person& p1)
	{
		if (this->m_name==p1.m_name&&this->m_age==p1.m_age)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	string m_name;
	int m_age;
};

//查找自定义数据类型
void find_test02()
{
	vector<Person>v;
	Person p1("one", 1);
	Person p2("two", 2);
	Person p3("three", 3);
	Person p4("four", 4);
	Person p5("five", 5);

	v.push_back(p1);
	v.push_back(p2);
	v.push_back(p3);
	v.push_back(p4);
	v.push_back(p5);

	Person p("one", 1);

	vector<Person>::iterator it = find(v.begin(), v.end(), p);//需要重载一下，使底层知道如何对比
	if (it == v.end())
	{
		cout << "没有找到" << endl;
	}
	else
	{
		cout << "找到"  << endl;
	}
}

class CreateFive
{
public:
	bool operator()(int val)
	{
		return val > 5;
	}
};

void find_if_test01()
{
	vector<int>v;
	for (int i = 0; i < 10; i++)
	{
		v.push_back(i);
	}

	vector<int>::iterator it = find_if(v.begin(), v.end(), CreateFive());
	if (it == v.end())
	{
		cout << "没有找到" << endl;
	}
	else
	{
		cout << "找到" << endl;
	}
}

class Find2
{
public:
	bool operator()(Person p)
	{
		return p.m_age > 2;
	}
};

void find_if_test02()
{
	vector<Person>v;
	Person p1("one", 1);
	Person p2("two", 2);
	Person p3("three", 3);
	Person p4("four", 4);
	Person p5("five", 5);

	v.push_back(p1);
	v.push_back(p2);
	v.push_back(p3);
	v.push_back(p4);
	v.push_back(p5);

	//找年龄大于2的人
	vector<Person>::iterator it = find_if(v.begin(), v.end(), Find2());
	if (it == v.end())
	{
		cout << "没有找到" << endl;
	}
	else
	{
		cout << "找到" << endl;
	}
}
#include<iostream>
#include<functional>
#include<vector>
#include<algorithm>
#include<string>
using namespace std;

class MyCompare
{
public:
	bool operator()(int p1, int p2)
	{
		return p1 > p2;
	}
};

void test01()
{
	vector<int>v;
	v.push_back(10);
	v.push_back(30);
	v.push_back(20);
	v.push_back(50); 
	v.push_back(40);

	//利用sort实现元素升序排列
	sort(v.begin(), v.end());
	//利用sort和二元谓词进行降序排列
	sort(v.begin(), v.end(),MyCompare());

	sort(v.begin(), v.end(), greater<int>());
}

class Person
{
public:
	Person(string name,int age)
	{
		this->m_name = name;
		this->m_age = age;
	}
	string m_name;
	int m_age;
};

class Compare
{
public:
	bool operator()(const Person& p1, const Person& p2)
	{
		return p1.m_age > p2.m_age;
	}
};
void test02()
{
	vector<Person>p;

	Person p1("刘备", 35);
	Person p2("关羽", 35);
	Person p3("张飞", 35);
	Person p4("赵云", 35);
	Person p5("曹操", 35);

	p.push_back(p1);
	p.push_back(p2);
	p.push_back(p3);
	p.push_back(p4);
	p.push_back(p5);

	sort(p.begin(), p.end(), Compare());
}
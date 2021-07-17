#include<iostream>
#include<set>
#include<string>
using namespace std;

class MyCompare
{
public:
	bool operator()(int v1, int v2)
	{
		return v1 > v2;
	}
};

class Person
{
public:
	Person(string name, int age)
	{
		this->m_Age = age;
		this->m_Name = name;
	}
	string m_Name;
	int m_Age;
};
void test()//内置数据类型
{
	set<int,MyCompare>s1;//默认升序，想要降序需要加反函数

	s1.insert(30);
	s1.insert(50);
	s1.insert(40);
	s1.insert(60);
	s1.insert(20);
	s1.insert(10);

	for (set<int, MyCompare>::iterator it = s1.begin(); it != s1.end(); it++)
	{
		cout << *it << " ";
	}
}

class compareperson
{
public:
	bool operator()(const Person& p1, const Person& p2)
	{
		return p1.m_Age > p2.m_Age;
	}
};

void test01()//自定义数据类型,需要指定排序规则
{
	set<Person,compareperson>s;

	Person p1("刘备", 35);
	Person p2("曹操", 45);
	Person p3("孙权", 40);
	Person p4("赵云", 25);
	Person p5("张飞", 55);
	Person p6("关羽", 35);

	s.insert(p1);
	s.insert(p2);
	s.insert(p3);
	s.insert(p4);
	s.insert(p5);
	s.insert(p6);

	for (set<Person,compareperson>::iterator it = s.begin(); it != s.end(); it++)
	{
		cout << "姓名" << it->m_Name << " 年龄" << it->m_Age << endl;
	}
}

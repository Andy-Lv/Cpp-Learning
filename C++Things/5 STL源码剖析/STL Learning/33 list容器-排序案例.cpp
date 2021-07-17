#include<iostream>
using namespace std;
#include<string>
#include<list>

class Person
{
public:
	Person(string name,int age, int height)
	{
		this->m_Name = name;
		this->m_Height = height;
		this->m_age = age;
	}
	string m_Name;
	int m_age;
	int m_Height;
};

bool compareperson(Person& p1, Person& p2)
{
	if (p1.m_age==p2.m_age)
	{
		return p1.m_Height > p2.m_Height;
	}
	return p1.m_age < p2.m_age;
}

void test()
{
	list<Person>L;

	Person p1("刘备", 35, 185);
	Person p2("曹操", 45, 175);
	Person p3("孙权", 40, 165);
	Person p4("赵云", 25, 155);
	Person p5("张飞", 55, 145);
	Person p6("关羽", 35, 135);

	//拆入数据
	L.push_back(p1);
	L.push_back(p2);
	L.push_back(p3);
	L.push_back(p4);
	L.push_back(p5);
	L.push_back(p6);

	for (list<Person>::iterator it = L.begin(); it != L.end(); it++)
	{
		cout << it->m_Name << " " << it->m_age << " " << it->m_Height << endl;
	}

	//排序
	L.sort(compareperson);//如果不加参数会报错，因为person有很多属性，不知道按照那个来排序，因此需要写反函数
	for (list<Person>::iterator it = L.begin(); it != L.end(); it++)
	{
		cout << it->m_Name << " " << it->m_age << " " << it->m_Height << endl;
	}
}
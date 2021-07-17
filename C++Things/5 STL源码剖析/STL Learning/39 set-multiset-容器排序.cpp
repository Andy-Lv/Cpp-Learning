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
void test()//������������
{
	set<int,MyCompare>s1;//Ĭ��������Ҫ������Ҫ�ӷ�����

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

void test01()//�Զ�����������,��Ҫָ���������
{
	set<Person,compareperson>s;

	Person p1("����", 35);
	Person p2("�ܲ�", 45);
	Person p3("��Ȩ", 40);
	Person p4("����", 25);
	Person p5("�ŷ�", 55);
	Person p6("����", 35);

	s.insert(p1);
	s.insert(p2);
	s.insert(p3);
	s.insert(p4);
	s.insert(p5);
	s.insert(p6);

	for (set<Person,compareperson>::iterator it = s.begin(); it != s.end(); it++)
	{
		cout << "����" << it->m_Name << " ����" << it->m_Age << endl;
	}
}

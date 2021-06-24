#include <iostream>
#include<vector>
#include<algorithm>
#include<string>
using namespace std;

class Person
{
public:
	Person(string name, int age)
	{
		this->m_Name = name;
		this->m_Age = age;
	}

	string m_Name;
	int m_Age;
};
void test()
{
	vector<Person>v;
	Person p1("a", 1);
	Person p2("a", 2);
	Person p3("a", 3);
	Person p4("a", 4);
	Person p5("a", 5);

	v.push_back(p1);
	v.push_back(p2);
	v.push_back(p3);
	v.push_back(p4);
	v.push_back(p5);

	//±éÀú
	for (vector<Person>::iterator it = v.begin(); it != v.end(); it++)
	{
		cout<<(*it).m_Name<< (*it).m_Age<<endl;
	}
}

void test02()
{
	vector<Person*>v;
	Person p1("a", 1);
	Person p2("a", 2);
	Person p3("a", 3);
	Person p4("a", 4);
	Person p5("a", 5);

	v.push_back(&p1);
	v.push_back(&p2);
	v.push_back(&p3);
	v.push_back(&p4);
	v.push_back(&p5);

	for (vector<Person*>::iterator it = v.begin(); it != v.end(); it++)
	{
		cout << (*it)->m_Name << (*it)->m_Age << endl;
	}
}
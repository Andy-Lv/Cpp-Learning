#include<iostream>
#include<functional>
#include<vector>
#include<algorithm>
#include<string>
using namespace std;

class person
{
public:
	person(string name, int age)
	{
		this->m_name = name;
		this->m_age;
	}
	string m_name;
	int m_age;

	bool operator == (const person &p)
	{
		if (this->m_age==p.m_age)
		{
			return true;
		}
		else
		{
			return false;
		}
	}

};

void test()
{
	vector<int>v;
	v.push_back(10);
	v.push_back(20);
	v.push_back(30);
	v.push_back(40);
	v.push_back(40);
	v.push_back(40);

	int num = count(v.begin(), v.end(), 40);//���3

	//ͳ���Զ�����������
	vector<person>p;
	person p1("����",35);
	person p2("����", 35);
	person p3("�ŷ�", 35);
	person p4("����", 35);
	person p5("�ܲ�", 35);

	p.push_back(p1);
	p.push_back(p2);
	p.push_back(p3);
	p.push_back(p4);
	p.push_back(p5);

	person pp("�����", 35);

	int num = count(v.begin(), v.end(), p);

	cout << "�������������ͬ������" << num << "��" << endl;


}

class Greater20
{
public:
	bool operator()(int val)
	{
		return val > 20;
	}
};

class AddGreater20
{
public:
	bool operator()(const person& p)
	{
		return p.m_age > 20;
	}
};
void test01()
{
	vector<int>v;
	v.push_back(10);
	v.push_back(20);
	v.push_back(30);
	v.push_back(40);
	v.push_back(40);
	v.push_back(40);

	int num = count(v.begin(), v.end(), Greater20());//���4

	//ͳ���Զ�����������
	vector<person>p;
	person p1("����", 35);
	person p2("����", 35);
	person p3("�ŷ�", 35);
	person p4("����", 35);
	person p5("�ܲ�", 35);

	int num1 = count_if(v.begin(), v.end(), AddGreater20());//���5
}
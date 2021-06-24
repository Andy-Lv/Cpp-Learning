/*
	���ò����㷨
	find			����Ԫ��  �ҵ�����ָ��Ԫ�ص��������Ҳ�������end
	find_if			����������Ԫ��
	adjacent_find   ���������ظ�Ԫ��
	binary_search   ���ֲ��ҷ�
	count			ͳ��Ԫ�ظ���
	count_if		������ͳ��Ԫ�ظ���
*/

#include<iostream>
#include<functional>
#include<vector>
#include<algorithm>
#include<string>
using namespace std;

//����������������
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
		cout << "û���ҵ�" << endl;
	}
	else
	{
		cout << "�ҵ�" << *it << endl;
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

//�����Զ�����������
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

	vector<Person>::iterator it = find(v.begin(), v.end(), p);//��Ҫ����һ�£�ʹ�ײ�֪����ζԱ�
	if (it == v.end())
	{
		cout << "û���ҵ�" << endl;
	}
	else
	{
		cout << "�ҵ�"  << endl;
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
		cout << "û���ҵ�" << endl;
	}
	else
	{
		cout << "�ҵ�" << endl;
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

	//���������2����
	vector<Person>::iterator it = find_if(v.begin(), v.end(), Find2());
	if (it == v.end())
	{
		cout << "û���ҵ�" << endl;
	}
	else
	{
		cout << "�ҵ�" << endl;
	}
}
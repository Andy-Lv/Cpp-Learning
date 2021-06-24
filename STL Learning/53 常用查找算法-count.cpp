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

	int num = count(v.begin(), v.end(), 40);//输出3

	//统计自定义数据类型
	vector<person>p;
	person p1("刘备",35);
	person p2("关羽", 35);
	person p3("张飞", 35);
	person p4("赵云", 35);
	person p5("曹操", 35);

	p.push_back(p1);
	p.push_back(p2);
	p.push_back(p3);
	p.push_back(p4);
	p.push_back(p5);

	person pp("诸葛亮", 35);

	int num = count(v.begin(), v.end(), p);

	cout << "与诸葛亮岁数相同的人有" << num << "个" << endl;


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

	int num = count(v.begin(), v.end(), Greater20());//输出4

	//统计自定义数据类型
	vector<person>p;
	person p1("刘备", 35);
	person p2("关羽", 35);
	person p3("张飞", 35);
	person p4("赵云", 35);
	person p5("曹操", 35);

	int num1 = count_if(v.begin(), v.end(), AddGreater20());//输出5
}
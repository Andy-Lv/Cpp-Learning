#include <iostream>
#include<string>
using namespace std;

//template<class T1, class T2>
//class Person;
//template<class T1, class T2>
//void printperson2(Person<T1, T2> p)
//{
//	cout << p.m_Name << " " << p.m_Age << endl;
//}

template<class T1, class T2>
class Person
{
	//全局函数，类内实现
	friend void printperson(Person<T1,T2> p)
	{
		cout << m_Name << " " << m_Age << endl;
	}
	//全局函数，类外实现
	//出现无法解析的外部命令，因此需要加上模板参数列表
	//如果全局函数是类外实现，需要让编译器提前知道这个函数的存在
	//需要将函数的实现写道最上方，又由于函数中用那个Person类，因此需要在前面加一个person类的声明，且加上模板
	friend void printperson2<>(Person<T1, T2> p);

public:
	Person(T1 name, T2 age)
	{
		this->m_Name = name;
		this->m_Age = age;
	}
private:
	T1 m_Name;
	T2 m_Age;
};

//类外实现
template<class T1, class T2>
void printperson2(Person<T1, T2> p)
{
	cout << p.m_Name << " " << p.m_Age << endl;
}

void test()
{
	Person<string, int>p("Tom", 10);
	printperson(p);
}
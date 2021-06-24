#include <iostream>
#include<string>
using namespace std;

template<class T1, class T2>
class Person
{
public:
	Person(T1 name, T2 age);
	//{
	//	this->m_Name = name;
	//	this->m_Age = age;
	//}

	void showperson();
	//{
	//	cout << m_Name << " " << m_Age << endl;
	//}
	T1 m_Name;
	T2 m_Age;
};

template<class T1,class T2>
Person<T1, T2>::Person(T1 name, T2 age)
{
	this->m_Name = name;
	this->m_Age = age;
}

template<class T1, class T2>
void Person<T1, T2>::showperson()
{
	cout << m_Name << " " << m_Age << endl;
}

void test()
{
	Person<string, int>s("孙悟空",1000);
	s.showperson();
}

//分文件编写，在h文件中写函数声明，cpp文件中写函数实现，hpp文件中写声明和实现
//但是模板的分文件编写，将h文件包含后，编译器并不会生成对应的cpp文件，因此可以生成，但是不能成功运行
//因此需要将模板函数的声明和实现都写在hpp文件中并包含hpp文件
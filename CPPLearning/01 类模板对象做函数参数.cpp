#include <iostream>
#include<string>
using namespace std;

//类模板对象做函数参数

template<class T1 ,class T2>
class Person
{
public:
    Person(T1 name,T2 age)
    {
        this->m_name = name;
        this->m_age = age;
    }

    void showperosn()
    {
        cout << this->m_name << " " << this->m_age << endl;
    }
    T1 m_name;
    T2 m_age;
    void showperson();
};
//指定传入类型

void printPerson1(Person<string, int>&p)//引用传参
{
    p.showperosn();
}
void test1()
{
    Person<string, int>p("孙悟空", 1000);
    printPerson1(p);
}

//参数模板化
template<class T1, class T2>
void printPerson2(Person<T1, T2>& p)//引用传参
{
    p.showperosn();
}

void test2()
{
    Person<string, int>p("猪八戒", 1000);
    printPerson1(p);
}

//整个类模板化
template<class T>
void printPerson3(T p)//引用传参
{
    p.showperosn();
}

void test2()
{
    Person<string, int>p("唐僧", 1000);
    printPerson1(p);
}


int main()
{
    std::cout << "Hello World!\n";
}
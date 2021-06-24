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
	//ȫ�ֺ���������ʵ��
	friend void printperson(Person<T1,T2> p)
	{
		cout << m_Name << " " << m_Age << endl;
	}
	//ȫ�ֺ���������ʵ��
	//�����޷��������ⲿ��������Ҫ����ģ������б�
	//���ȫ�ֺ���������ʵ�֣���Ҫ�ñ�������ǰ֪����������Ĵ���
	//��Ҫ��������ʵ��д�����Ϸ��������ں��������Ǹ�Person�࣬�����Ҫ��ǰ���һ��person����������Ҽ���ģ��
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

//����ʵ��
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
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
	Person<string, int>s("�����",1000);
	s.showperson();
}

//���ļ���д����h�ļ���д����������cpp�ļ���д����ʵ�֣�hpp�ļ���д������ʵ��
//����ģ��ķ��ļ���д����h�ļ������󣬱��������������ɶ�Ӧ��cpp�ļ�����˿������ɣ����ǲ��ܳɹ�����
//�����Ҫ��ģ�庯����������ʵ�ֶ�д��hpp�ļ��в�����hpp�ļ�
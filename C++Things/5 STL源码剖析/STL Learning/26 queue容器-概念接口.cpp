//queue���Ƚ��ȳ������ݽṹ������������
//�������������һ������Ԫ�أ�����һ���Ƴ�Ԫ��
//������ֻ�ж�ͷ�Ͷ�β�ſ��Ա����ʹ�ã���˶��в������б�����Ϊ
//�Ŷ�

#include<iostream>
#include<queue>
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
	queue <Person>q;

    Person p1("������", 1);
    Person p2("�����", 2);
    Person p3("��˽�", 3);
    Person p4("ɳ����", 4);

    q.push(p1);
    q.push(p2);
    q.push(p3);
    q.push(p4);

    //�ж�ֻҪ���в�Ϊ�գ��鿴��ͷ���β������

    while (!q.empty())
    {
        //�鿴��ͷ
        cout << "��ͷԪ��" << q.front().m_Name << " " << q.front().m_Age << endl;

        //�鿴��β
        cout<< "��βԪ��" << q.back().m_Name << " " << q.back().m_Age << endl;

        //����
        q.pop();
    }

    cout << q.size() << endl;//0
}
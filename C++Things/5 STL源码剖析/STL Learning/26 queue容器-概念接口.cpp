//queue是先进先出的数据结构，有两个出口
//队列容器允许从一端新增元素，从另一端移除元素
//队列中只有对头和队尾才可以被外界使用，因此队列不允许有遍历行为
//排队

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

    Person p1("唐三藏", 1);
    Person p2("孙悟空", 2);
    Person p3("猪八戒", 3);
    Person p4("沙和尚", 4);

    q.push(p1);
    q.push(p2);
    q.push(p3);
    q.push(p4);

    //判断只要队列不为空，查看队头与队尾，出队

    while (!q.empty())
    {
        //查看队头
        cout << "对头元素" << q.front().m_Name << " " << q.front().m_Age << endl;

        //查看队尾
        cout<< "对尾元素" << q.back().m_Name << " " << q.back().m_Age << endl;

        //出队
        q.pop();
    }

    cout << q.size() << endl;//0
}
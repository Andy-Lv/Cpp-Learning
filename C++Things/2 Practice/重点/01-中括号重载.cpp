//
// Created by andy on 2021/7/3.
//

#include <iostream
#include <cstring>

using namespace std;

struct Person
{
    //职工基本信息结构
    double salary;
    char *name;
};

class SalaryManaege
{
    Person *employ;//存放职工信息的数组
    int max;//数组下标上界
    int n;//数组的实际职工数
public:
    SalaryManaege(int Max = 0)
    {
        max = Max;
        n = 0;
        employ = new Person[max];
    }

    //返回引用特性是可以直接放在左值直接使用
    double &operator[](char *Name)
    {
        Person *p;
        for (p = employ; p < employ + n; p++)
        {
            //如果存在
            if (strcmp(p->name, Name) == 0)
                return p->salary;
            else
            {
                //如果不存在
                p = employ + n++;
                p->name = new char[strlen(Name) + 1];
                strcpy(p->name, Name);
                p->salary = 0;
                return p->salary;
            }
        }
    }

    void display()
    {
        for (int i = 0; i < n; ++i)
        {
            cout<<employ[i].name<<"  "<<employ[i].salary<<endl;
        }
    }

    ~SalaryManaege()
    {
        delete employ;
    }
};

int main()
{
    SalaryManaege s(3);
    s["张三"]=2188.88;
    s["李四"]=2188.88;
    s["王五"]=2188.88;

    cout<<"张三\t"<<s["张三"]<<endl;
    cout<<"李四\t"<<s["李四"]<<endl;
    cout<<"王五\t"<<s["王五"]<<endl;
}
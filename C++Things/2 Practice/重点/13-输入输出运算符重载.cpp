//
// Created by andy on 2021/7/4.
//

#include<iostream.h>
#include<string.h>

using namespace std;

class Sales
{
private:
    char name[10];
    char id[18];
    int age;
public:
    Sales(char *Name, char *ID, int Age);

    friend Sales &operator<<(ostream &os, Sales &s);    //重载输出运算符
    friend Sales &operator>>(istream &is, Sales &s);    //重载输入运算符
}

Sales::Sales(char *Name, char *ID, int Age)
{
    strcpy(name, Name);
    strcpy(id, ID);
    age = Age;
}

Sales &operator<<(ostream &os, Sales &s)
{
    os << s.name << "\t";                            //输出姓名
    os << s.id << "\t";                                //输出身份证号
    os << s.age << endl;                            //输出年龄
    return s;
}

Sales &operator>>(istream &is, Sales &s)
{
    cout << "输入雇员的姓名，身份证号，年龄" << endl;
    is >> s.name >> s.id >> s.age;
    return s;
}

void main(){
    Sales s1("杜康","214198012111711",40);   		//L1
    cout<<s1;                             			//L2
    cout<<endl;                           				//L3
    cin>>s1;                              				//L4
    cout<<s1;                             				//L5
}
//
// Created by andy on 2021/6/30.
//

#include <iostream>

using namespace std;

void display(const double &r)
{
    cout << r << endl;
    //常引用用作形参,在函数中不能更新r所引用的对象
}

class A
{
public:
    A(int i, int j)
    {
        x = i;
        y = j;
    }

private:
    int x, y;

};

class R
{
public:
    R(int r1,int r2)
    {
        R1=r1;
        R2=r2;
    }
    void print();
    void print() const;

private:
    int R1,R2;
};

//常成员函数说明格式:类型说明符 函数名(参数表) const;
//const是函数类型的一个组成部分,因此实现部分也需要带上const关键字
//const关键字可以被用于参与对重载函数的区分
//通过常对象只能调用他的常成员函数

void R::print() {
    cout<<"普通调用"<<endl;
    cout<<R1<<";"<<R2<<endl;
}

void R::print() const{
    cout<<"常对象调用"<<endl;
    cout<<R1<<";"<<R2<<endl;
}

int main()
{
    double d(9.5);
    display(d);
    A const a(3, 4);//a是常对象,不能被更新

    R a(5,4);
    a.print();
    //通过常对象只能调用他的常成员函数
    const R b(20,52);
    b.print();

    return 0;
}
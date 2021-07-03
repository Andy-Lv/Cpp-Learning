//
// Created by andy on 2021/7/3.
//

#include <iostream>

using namespace std;

class Time
{
private:
    int hh,mm,ss;
public:
    Time(int h=0,int m=0,int s=0):hh(0),mm(m),ss(s){}

    void operator()(int h,int m,int s)
    {
        hh=h;
        mm=m;
        ss=s;
    }

    void ShowTime()
    {
        cout<<hh<<":"<<mm<<":"<<ss<<endl;
    }
};

int main()
{
    Time t1(12,10,11);
    t1.ShowTime();
    t1.operator()(23,20,34);
    t1.ShowTime();
    t1(10,10,10);
    t1.ShowTime();
}
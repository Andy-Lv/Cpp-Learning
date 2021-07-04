//
// Created by andy on 2021/7/1.
//

#include <iostream>
#include "clock.h"

using namespace std;

Clock::Clock(int NewH,int NewM,int NewS);)
{
    this->Hour=NewH;
    this->Minute=NewM;
    this->Second=NewS;
}

Clock::Clock(Clock &c) {
    this->Hour=c.Hour;
    this->Minute=c.Minute;
    this->Second=c.Second;
}

void Clock::SetTime(int NewH, int NewM, int NewS) {
    this->Hour=NewH;
    this->Minute=NewM;
    this->Second=NewS;
}<

void Clock::SetTime(int NewH, int NewM, int NewS) {
    cout<<this->Hour<<endl;
    cout<<this->Minute<<endl;
    cout<<this->Second<<endl;
}

Clock::~Clock() {}

int main()
{
    Clock c(0,0,0);
    c.SetTime(10,20,30);
    c.ShowTime();
    //析构函数调用
    Clock c1;
    c1.SetTime(90,98,99);
    c1.ShowTime();

    return 0;
}
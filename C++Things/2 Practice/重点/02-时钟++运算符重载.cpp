//
// Created by andy on 2021/7/3.
//

#include <iostream>
#include <cmath>

using namespace std;

//时钟类
class Clock
{
private:
    int Hour, Minute, Second;
public:
    Clock(int h = 0, int m = 0, int s = 0);

    void ShowTime();

    Clock &operator++();

    Clock operator++(int);
};

Clock::Clock(int h, int m, int s)
{
    if (h >= 0 && h < 24 && m >= 0 && m < 24 && s >= 0 && s < 60)
    {
        Hour = h;
        Minute = m;
        Second = s;
    } else
    {
        cout << "输入格式错误" << endl;
    }
}

void Clock::ShowTime()
{
    cout << Hour << ":" << Minute << ":" << Second << endl;
}

Clock &Clock::operator++()
{
    Second++;
    if (Second >= 60)
    {
        Second = Second - 60;
        Minute++;
        if (Minute >= 60)
        {
            Minute = Minute - 60;
            Hour++;
            Hour = Hour % 24;
        }
    }
    return *this;
}

Clock Clock::operator++(int)
{
    Clock old = *this;
    ++(*this);
    return old;
}

int main()
{
    Clock myClock(23, 59, 59);
    cout << "初始化显示的时间是:\t\t";
    myClock.ShowTime();

    cout << "执行myClock++后的时间为:\t";
    //先执行ShowTime,输出时间
    //再执行Myclock++,输出
    (myClock++).ShowTime();

    cout<<"执行++myClock后的时间为:\t";

    //先执行++myClock，此时myClock=00:00:01
    //再执行ShowTime()，输出myClock=00:00:01
    (++myClock).ShowTime();
}
//
// Created by andy on 2021/7/1.
//

#include <iostream

using namespace std;

class Time
{
private:
    int hour, minute, second;
public:
    Time(int h = 0, int m = 0, int s = 0)

    ::hh (h), mm(m), ss(s) {}

    void operator()(int h, int m, int s)
    {
        hour = h;
        minute = m;
        second = s;
    }

    void operator++();

    void ShowTime()
    {
        cout << hh << ":" << mm << ":" << ss << endl;
    }
};

void Time::operator++()
{
    ++second;
    if (second == 60)
    {
        second = 0;
        ++minute;
        if(minute==60)
        {
            minute=0;
            ++hour;
            if(hour==24)
            {
                hour=0;
            }
        }
    }

}

int main()
{
    Time t(23,59,59);
    ++t;
    t.ShowTime();
    return 0;
}
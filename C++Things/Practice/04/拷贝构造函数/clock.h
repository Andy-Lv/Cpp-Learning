//
// Created by andy on 2021/7/1.
//

#ifndef C_LEARNING_CLOCK_H
#define C_LEARNING_CLOCK_H

#endif //C_LEARNING_CLOCK_H

class Clock
{
public:
    Clock(int NewH,int NewM,int NewS);
    Clock(Clock &c);//拷贝构造函数,如果不加,编译器会自动生成一个拷贝构造函数,因此加不加都可使用
    void SetTime(int NewH,int NewM,int NewS);
    void ShowTime();
    ~Clock();//析构函数,编译器会自动产生一个默认的析构函数
private:
    int Hour,Minute,Second;
};
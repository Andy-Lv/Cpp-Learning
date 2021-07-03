//
// Created by andy on 2021/7/3.
//

//有一个类Circle,设计该类的类型转换函数,
// 当将Circle对象转换成int型时,返回圆的半径,
// 当将它转换成double型时,就返回圆的周长,
// 当将它转换为float型时,返回圆的面积

//类型转换函数没有参数
//类型转换函数没有返回类型
//类型转换函数必须返回将要转换成type类型数据

#include <iostream>

using namespace std;

class Circle
{
private:
    double x, y, r;
public:
    Circle(double x1, double y1, double r1)
    {
        x = x1;
        y = y1;
        r = r1;
    }

    operator int()
    {
        return int(r);
    }

    operator double()
    {
        return double(2 * 3.14 * r);
    }

    operator float()
    {
        return float(3.14 * r * r);
    }
};

int main()
{
    Circle c(2.3,3.4,2.5);

    int r=c;//调用operator int(),将Circle类型转换为int

    double length=c;

    float area=c;

    double len=(double) c;//将Circle类型对象强制转换为double
}
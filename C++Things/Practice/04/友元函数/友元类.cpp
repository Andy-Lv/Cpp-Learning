//
// Created by andy on 2021/6/30.
//

//若一个类为另一个类的友元,则此类所有成员都能访问对方类的私有成员
//声明语法:将友元类名在另一个类中使用friend修饰说明

//如果声明B类是A类的友元,B类的成员函数就可以访问A类的私有和保护数据,但反过来不行

class A
{
    friend class B;

public:
    void Display()
    {
        cout << x << endl;

    }

private:
    int x;
};

class B
{
public:
    void Set(int i);

    void Display();

private:
    A a;
};

void B::Display()
{
    a.Display();
}

void B::Set(int i)
{
    a.x = i;
}

int main()
{
    B b;
    b.Set(10);
    b.Display();

    return 0;
}
#include <iostream>
#include<string>
using namespace std;

template<class T>
class Base
{
	T m;
};

class Son:public Base//错误，必须知道父类中T的类型才能继承给子类
{

};

class Son:public Base<int>
{

};

void test()
{
	Son s;
}
//想灵活的指定父类中T类型，子类也需要变类模板

template<class T1,class T2>
class Son2 :public Base<T2>//T1给对象obj，T2给父类Base中的类型
{
	T1 obj;
};

void test()
{
	Son2<int, char>S2;//int为T1，给obj。char为T2，给父类中m。
}

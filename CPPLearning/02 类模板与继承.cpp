#include <iostream>
#include<string>
using namespace std;

template<class T>
class Base
{
	T m;
};

class Son:public Base//���󣬱���֪��������T�����Ͳ��ܼ̳и�����
{

};

class Son:public Base<int>
{

};

void test()
{
	Son s;
}
//������ָ��������T���ͣ�����Ҳ��Ҫ����ģ��

template<class T1,class T2>
class Son2 :public Base<T2>//T1������obj��T2������Base�е�����
{
	T1 obj;
};

void test()
{
	Son2<int, char>S2;//intΪT1����obj��charΪT2����������m��
}

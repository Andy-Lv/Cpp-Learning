#include<iostream>
#include<string>
using namespace std;


//�º���
class MyAdd
{
public:
	int operator()(int v1, int v2)
	{
		return v1 + v2;
	}
};
//����������ʹ��ʹ����������ͨ�����������ã������в����������з���ֵ
void test01()
{
	MyAdd myAdd;
	cout << myAdd(10,10) << endl;
}

//�������󳬳���ͨ�����ĸ����������������Լ���״̬
class MyPrint
{
public:
	MyPrint()
	{
		this->count = 0;
	}
	void operator()(string test)
	{
		cout << test << endl;
		this->count++;
	}
	int count;//�ڲ���״̬
};

void test02()
{
	MyPrint myPrint;
	myPrint("hello world");

	cout << "���õĴ���Ϊ" << myPrint.count << endl;
}

//�������������Ϊ�������д���
void doPrint(MyPrint& mp, string test)
{
	mp(test);
}

void test03()
{
	MyPrint myPrint;
	doPrint(myPrint, "hello world");
}
//stack��һ���Ƚ���������ݽṹ����ֻ��һ������
//ջ�������������б�������Ϊ
//����

#include<iostream>
#include<stack>
using namespace std;

void test()
{
	stack<int>s;
	s.push(10);
	s.push(20);
	s.push(30);
	s.push(40);
	s.push(50);

	cout << "ջ�Ĵ�С" << s.size() << endl;

	//ֻҪջ��Ϊ�գ��Ͳ鿴ջ������ִ�г�ջ����

	while (s.empty())
	{
		//�鿴ջ��Ԫ��
		cout << "ջ��Ԫ��Ϊ��" << s.top() << endl;//���ȳ�������50

		//��ջ
		s.pop();
	}

	cout << "ջ�Ĵ�С" << s.size() << endl;

}
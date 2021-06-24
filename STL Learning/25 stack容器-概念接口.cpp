//stack是一种先进后出的数据结构，它只有一个出口
//栈容器，不允许有遍历的行为
//弹夹

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

	cout << "栈的大小" << s.size() << endl;

	//只要栈不为空，就查看栈顶，并执行出栈操作

	while (s.empty())
	{
		//查看栈顶元素
		cout << "栈顶元素为：" << s.top() << endl;//最先出来的是50

		//出栈
		s.pop();
	}

	cout << "栈的大小" << s.size() << endl;

}
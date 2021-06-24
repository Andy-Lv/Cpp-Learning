#include <iostream>
#include<string>
using namespace std;

void test()
{
	string str = "hello";
	//插入
	str.insert(1, "111");//从第1个位置后面开始插入后面的字符
	//删除
	str.erase(1, 3);//从第一个位置后面开始删除三个
}
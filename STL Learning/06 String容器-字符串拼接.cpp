#include <iostream>
#include<string>
using namespace std;

void test()
{
	string str1 = "我";
	str1 += "我爱玩游戏";
	str1 += ':';

	string str2 = "王者荣耀";
	str1 += str2;

	string str3 = "I";
	str3.append(" love");

	str3.append("game abcde",4);

	str3.append(str2);

	str3.append("game abcde", 4,3);//从第4个开始截取3个，记得从0开始数
}
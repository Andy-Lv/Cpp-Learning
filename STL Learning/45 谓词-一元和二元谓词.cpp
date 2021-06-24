//返回值类型为bool类型的仿函数为谓词

//一元谓词
#include<iostream>
using namespace std;
#include<vector>
#include<algorithm>

class GreaterFive
{
public:
	bool operator()(int val)//一个参数，为一元谓词
	{
		return val > 5;
	}
};


void test01()
{
	vector<int>v;
	for (int i = 0; i < 10; i++)
	{
		v.push_back(i);
	}

	//查找容器中有没有大于5的数字
	//GreaterFive()匿名对象函数
	vector<int>::iterator it = find_if(v.begin(), v.end(), GreaterFive());//找到了就返回目标迭代器，如果没找到就返回end
	if (it==v.end())
	{
		cout << "未找到" << endl;
	}
	else
	{
		cout << "找到大于5的数字为" << *it << endl;
	}
}

class MyCompare
{
public:
	bool operator()(int v1, int v2)//两个参数二元谓词
	{
		return v1 > v2;
	}
};

void test02()
{
	vector<int>v;
	v.push_back(10);
	v.push_back(40);
	v.push_back(20);
	v.push_back(30);
	v.push_back(50);

	sort(v.begin(), v.end());

	//使用函数对象改变排序规则为从大到小
	sort(v.begin(), v.end(), MyCompare());
}
#include<iostream>
#include<functional>
#include<vector>
#include<algorithm>
using namespace std;

class Transform
{
public:
	bool operator()(int v)
	{
		//return v + 1000;
		return v;
	}
};
void test()
{
	vector<int>v;
	for (int i = 0; i < 10; i++)
	{
		v.push_back(i);
	}


	//transform 将一个元素中的元素搬运到另一个容器中
	vector<int>vTarget;//必须先申请空间
	vTarget.resize(v.size());//
	transform(v.begin(), v.end(), vTarget.begin(), Transform());//前两个参数是原来容器的起止点，第三个参数是目标容器的起点，最后一个参数是仿函数
}
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


	//transform ��һ��Ԫ���е�Ԫ�ذ��˵���һ��������
	vector<int>vTarget;//����������ռ�
	vTarget.resize(v.size());//
	transform(v.begin(), v.end(), vTarget.begin(), Transform());//ǰ����������ԭ����������ֹ�㣬������������Ŀ����������㣬���һ�������Ƿº���
}
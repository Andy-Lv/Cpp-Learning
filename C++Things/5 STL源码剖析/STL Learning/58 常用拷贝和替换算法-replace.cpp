#include<iostream>
#include<functional>
#include<vector>
#include<algorithm>
#include<string>
using namespace std;

//replace ��һ�������Ԫ���滻Ϊ��Ԫ��

class Greater30
{
public:
	bool operator()(int val)
	{
		return val >= 30;
	}
};
void test()
{
	vector<int>v;
	v.push_back(20);
	v.push_back(30);
	v.push_back(50);
	v.push_back(30);
	v.push_back(40);
	v.push_back(10);
	v.push_back(20);

	replace(v.begin(), v.end(), 20, 2000);//ֻҪ��20���滻��2000

	replace_if(v.begin(), v.end(), Greater30(), 3000);//��30�滻Ϊ3000

}
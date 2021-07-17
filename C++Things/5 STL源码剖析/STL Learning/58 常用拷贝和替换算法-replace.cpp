#include<iostream>
#include<functional>
#include<vector>
#include<algorithm>
#include<string>
using namespace std;

//replace 将一个区间的元素替换为新元素

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

	replace(v.begin(), v.end(), 20, 2000);//只要是20都替换成2000

	replace_if(v.begin(), v.end(), Greater30(), 3000);//将30替换为3000

}
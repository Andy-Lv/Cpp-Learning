#include<iostream>
#include<functional>
#include<vector>
#include<algorithm>
#include<string>
#include<numeric>
using namespace std;

//fill 填充容器元素内容    #include<numeric>

void test()
{
	vector<int>v1;

	v1.resize(10);

	fill(v1.begin(), v1.end(), 1000);//目前容器中为10个100

}
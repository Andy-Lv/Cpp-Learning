#include<iostream>
#include<functional>
#include<vector>
#include<algorithm>
#include<string>
#include<numeric>
using namespace std;

//fill �������Ԫ������    #include<numeric>

void test()
{
	vector<int>v1;

	v1.resize(10);

	fill(v1.begin(), v1.end(), 1000);//Ŀǰ������Ϊ10��100

}
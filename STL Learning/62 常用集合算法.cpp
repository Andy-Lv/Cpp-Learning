/*
	set_intersection   求两个元素交集  原容器必须是有序的
	set_union          求两个元素并集
	set_difference     求两个容器差集
*/

#include<iostream>
#include<functional>
#include<vector>
#include<algorithm>
#include<string>
#include<numeric>
using namespace std;

void myprint(int val)
{
	cout << val << " ";
}

void test()
{
	vector<int>v1;
	vector<int>v2;

	for (int i = 0; i < 10; i++)
	{
		v1.push_back(i);
		v2.push_back(i + 5);
	}
	//交集
	vector<int>vTarget;
	//最特殊的情况为大容器包括小容器，开辟空间，取小容器的size即可

	vTarget.resize(min(v1.size(), v2.size()));//开辟的大小有可能比最终的交集大，这里开辟了最大的情况

	vector<int>::iterator itEnd = set_intersection(v1.begin(), v1.end(), v2.begin(), v2.end(), vTarget.begin());//返回vTarget的end

	for_each(vTarget.begin(), itEnd, myprint);//这里不用end是因为vTarget.size比这个交集大，如果用end，则后面的参数会用0来补齐
	//输出 5 6 7 8 9 

	//交集
	vector<int>vTarget1;
	vTarget1.resize(v1.size() + v2.size());

	vector<int>::iterator itEnd1 = set_union(v1.begin(), v1.end(), v2.begin(), v2.end(), vTarget1.begin());

	for_each(vTarget.begin(), itEnd1, myprint);

	//差集
	vector<int>vTarget2;
	vTarget2.resize(max(v1.size(), v2.size()));

	vector<int>::iterator itEnd2 = set_difference(v1.begin(), v1.end(), v2.begin(), v2.end(), vTarget1.begin());//v1和v2的差集：0 1 2 3 4 

	vector<int>::iterator itEnd2 = set_difference(v2.begin(), v2.end(), v1.begin(), v1.end(), vTarget1.begin());//v2和v1的差集：11 12 13 14


	for_each(vTarget.begin(), itEnd2, myprint);       
}
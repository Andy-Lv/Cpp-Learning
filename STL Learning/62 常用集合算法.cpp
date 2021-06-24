/*
	set_intersection   ������Ԫ�ؽ���  ԭ���������������
	set_union          ������Ԫ�ز���
	set_difference     �����������
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
	//����
	vector<int>vTarget;
	//����������Ϊ����������С���������ٿռ䣬ȡС������size����

	vTarget.resize(min(v1.size(), v2.size()));//���ٵĴ�С�п��ܱ����յĽ��������￪�����������

	vector<int>::iterator itEnd = set_intersection(v1.begin(), v1.end(), v2.begin(), v2.end(), vTarget.begin());//����vTarget��end

	for_each(vTarget.begin(), itEnd, myprint);//���ﲻ��end����ΪvTarget.size����������������end�������Ĳ�������0������
	//��� 5 6 7 8 9 

	//����
	vector<int>vTarget1;
	vTarget1.resize(v1.size() + v2.size());

	vector<int>::iterator itEnd1 = set_union(v1.begin(), v1.end(), v2.begin(), v2.end(), vTarget1.begin());

	for_each(vTarget.begin(), itEnd1, myprint);

	//�
	vector<int>vTarget2;
	vTarget2.resize(max(v1.size(), v2.size()));

	vector<int>::iterator itEnd2 = set_difference(v1.begin(), v1.end(), v2.begin(), v2.end(), vTarget1.begin());//v1��v2�Ĳ��0 1 2 3 4 

	vector<int>::iterator itEnd2 = set_difference(v2.begin(), v2.end(), v1.begin(), v1.end(), vTarget1.begin());//v2��v1�Ĳ��11 12 13 14


	for_each(vTarget.begin(), itEnd2, myprint);       
}
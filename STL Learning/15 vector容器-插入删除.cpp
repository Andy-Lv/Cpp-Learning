#include <iostream>
#include<string>
#include<vector>
using namespace std;

void printvector(vector<int>v)
{
	for (vector<int>::iterator it = v.begin(); it != v.end(); it++)
	{
		cout << *it << " ";
	}
	cout << endl;
}

void test()
{
	vector<int>v1;
	for (int i = 0; i < 10; i++)
	{
		v1.push_back(i);
	}

	printvector(v1);

	//β��
	v1.pop_back();//ɾ�����һ��Ԫ��
	printvector(v1);

	//����
	v1.insert(v1.begin(), 100);//��һ��Ԫ��ǰ�����100����100��beginλ��
	printvector(v1);

	v1.insert(v1.begin(),2, 100);//��һ��Ԫ��ǰ�����2��100����100��beginλ��
	printvector(v1);

	//ɾ��
	v1.erase(v1.begin());
	v1.erase(v1.begin(), v1.end());//�൱��v1.clear����
}
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
		v1.push_back(1);
	}
	printvector(v1);

	if (v1.empty())//Ϊ�棬��������Ϊ��
	{
		cout << "v1Ϊ��" << endl;
	}
	else
	{
		cout << "v1��Ϊ��" << endl;
		cout << "v1����Ϊ" << v1.capacity() << endl;
		cout << "v1�Ĵ�С��" << v1.size() << endl;
	}

	//����ָ����С
	v1.resize(15);
	printvector(v1);//ָ���ռ������Ĭ����0�����λ��ָ����Ϊresize��15��100����Ϊ��100�����
	v1.resize(5);//ָ���ռ���̣�����ಿ�ֻᱻɾ��
}
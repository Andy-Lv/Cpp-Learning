//vector���ݽṹ������ǳ����ƣ�Ҳ��Ϊ��������
//��֮ͬ�����������Ǿ�̬�ؼ���vector�Ƕ�̬��չ
//��������ԭ�еĿռ䣬�����ҵ�������ڴ�ռ䣬��Դ���ݿ������¿ռ䣬�ͷ�ԭ�ռ�

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
	//Ĭ�Ϲ��죬�޲ι���
	vector<int>v1;
	for (int i = 0; i < 10; i++)
	{
		v1.push_back(i);
	}
	printvector(v1);

	//ͨ������ķ�ʽ���й���
	vector<int>v2(v1.begin(), v1.end());
	printvector(v2);

	//n��element��ʽ����
	vector<int>v3(10, 100);//10��100
	printvector(v3);

	//��������
	vector<int>v4(v3);
	printvector(v4);
}
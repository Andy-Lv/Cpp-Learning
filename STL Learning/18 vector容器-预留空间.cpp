#include <iostream>
#include<string>
#include<vector>
using namespace std;

void test()
{
	vector<int>v;

	//ʹ���ٴ���Ϊ1
	v.reserve(100000);//Ԥ���ռ䣬��ʾ�ռ��������ܴ�Ԥ��len��Ԫ�س��ȣ�Ԥ���ռ䲻��ʼ����Ԫ�ز��ɷ���

	int num = 0;//ͳ�ƿ��ٴ���
	int* p = NULL;
	for (int i = 0; i < 100000; i++)
	{
		v.push_back(i);

		if (p!=&v[0])//��֤Ϊ��̬���٣�������ԭ�л����ϼ������ٿռ�
		{
			p = &v[0];
			num++;
		}
	}

}
//����ֵ����Ϊbool���͵ķº���Ϊν��

//һԪν��
#include<iostream>
using namespace std;
#include<vector>
#include<algorithm>

class GreaterFive
{
public:
	bool operator()(int val)//һ��������ΪһԪν��
	{
		return val > 5;
	}
};


void test01()
{
	vector<int>v;
	for (int i = 0; i < 10; i++)
	{
		v.push_back(i);
	}

	//������������û�д���5������
	//GreaterFive()����������
	vector<int>::iterator it = find_if(v.begin(), v.end(), GreaterFive());//�ҵ��˾ͷ���Ŀ������������û�ҵ��ͷ���end
	if (it==v.end())
	{
		cout << "δ�ҵ�" << endl;
	}
	else
	{
		cout << "�ҵ�����5������Ϊ" << *it << endl;
	}
}

class MyCompare
{
public:
	bool operator()(int v1, int v2)//����������Ԫν��
	{
		return v1 > v2;
	}
};

void test02()
{
	vector<int>v;
	v.push_back(10);
	v.push_back(40);
	v.push_back(20);
	v.push_back(30);
	v.push_back(50);

	sort(v.begin(), v.end());

	//ʹ�ú�������ı��������Ϊ�Ӵ�С
	sort(v.begin(), v.end(), MyCompare());
}
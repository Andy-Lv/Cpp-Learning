#include<iostream>
#include<set>
using namespace std;

void printset(set<int>& L)
{
	for (set<int>::const_iterator it = L.begin(); it != L.end(); it++)
	{
		cout << *it << endl;
	}
}

void test()
{
	set<int>s1;//��������ֻ��insert��ʽ
	s1.insert(10);
	s1.insert(20);
	s1.insert(40);
	s1.insert(50);
	s1.insert(40);
	s1.insert(30);

	//��������
	printset(s1);

	//ɾ��
	s1.erase(s1.begin());

	//ɾ�����ذ汾
	s1.erase(30);

	//���
	s1.erase(s1.begin(), s1.end());
	s1.clear();//����������ͬ

}
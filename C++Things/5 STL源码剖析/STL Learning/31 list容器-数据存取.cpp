#include<iostream>
#include<list>
using namespace std;

void printlist(list<int>& L)
{
	for (list<int>::const_iterator it = L.begin(); it != L.end(); it++)
	{
		cout << *it << endl;
	}
}
void test()
{
	list<int>L1;

	L1.push_back(10);
	L1.push_back(20);
	L1.push_back(30);
	L1.push_back(40);
	L1.push_back(50);

	printlist(L1);

	//��֧��[]��at������list�����е�Ԫ��
	//list�������������������������Կռ�洢���ݣ�������Ҳ�ǲ�֧��������ʵ�

	cout << "��һ��Ԫ��Ϊ" << L1.front() << endl;
	cout << "���һ��Ԫ��Ϊ" << L1.back() << endl;

	//��֤�������ǲ�֧��������ʵ�

	list<int>::iterator it = L1.begin();
	it++;//֧��˫��
	it--;
	//it=it+1  ��֧���������

}
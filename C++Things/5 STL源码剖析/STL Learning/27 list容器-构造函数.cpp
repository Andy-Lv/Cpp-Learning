//����
//��ɣ���һϵ�н�����
//������ɣ�һ���Ǵ������ݵ���������һ���Ǵ�����һ���ڵ��ַ��ָ����
//�ŵ㣺���Զ�����λ�ý��п��ٽ��в����ɾ��Ԫ��
//ȱ�㣺�������������ٶ�û�������
//����Ĵ洢��ʽ�������������ڴ�ռ䣬�������list�еĵ�����ֻ֧��ǰ�ƺͺ��ƣ�����˫�������
#include<iostream>
#include<list>
using namespace std;

void printlist(list<int> &L)
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

	list<int>L2(L1.begin(), L1.end());

	list<int>L3(L2);

	list<int>L4(10, 1000);
}
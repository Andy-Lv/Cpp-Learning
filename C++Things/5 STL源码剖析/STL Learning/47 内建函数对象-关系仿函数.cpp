/*
	STL�ڽ���һЩ��������

	���ࣺ
	�����º���
	��ϵ�º���
	�߼��º���

	�÷���
	��Щ�º����������Ķ����÷���һ�㺯����ȫ��ͬ
	ʹ���ڼ麯��������Ҫ����ͷ�ļ�#include<functional>
*/

/*
	��ϵ�º���
	�º���ԭ��
	template<<class T> bool equal_to<T>             ����
	template<<class T> bool not_equal_to<T>         ������
	template<<class T> bool greater<T>              ����
	template<<class T> bool greater_equal<T>        ���ڵ���
	template<<class T> bool less<T>                 С��
	template<<class T> bool les_equal<T>            С�ڵ���

*/

#include<iostream>
#include<functional>
#include<vector>
#include<algorithm>
using namespace std;

void test()
{
	vector<int>v;
	v.push_back(10);
	v.push_back(40);
	v.push_back(20);
	v.push_back(30);
	v.push_back(50);

	sort(v.begin(), v.end(), greater<int>());

}
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
	�߼��º���
	�º���ԭ��
	template<<class T> bool logical_and<T>             �߼���
	template<<class T> bool logical_or<T>              �߼���
	template<<class T> bool logical_not<T>             �߼���
*/

#include<iostream>
#include<functional>
#include<vector>
#include<algorithm>
using namespace std;

void test()
{
	vector<bool>v;
	v.push_back(true);
	v.push_back(false);
	v.push_back(true);
	v.push_back(false);
	v.push_back(true);

	//�����߼��ǣ�������v���˵�v2�У���ִ��ȡ������

	vector<bool>v2;
	v2.resize(v.size());

	transform(v.begin(), v.end(), v2.begin(), logical_not<bool>());//ǰ����������ԭ����������ֹ�㣬������������Ŀ����������㣬���һ�������Ƿº���
}
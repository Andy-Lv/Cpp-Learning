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
	�����º���
	ʵ����������
	����negate��һԪ���㣬�������Ƕ�Ԫ����
	�º���ԭ��
	template<<class T> T plus<T>             �ӷ��º���
	template<<class T> T minus<T>            �����º���
	template<<class T> T multiplies<T>       �˷��º���
	template<<class T> T divides<T>          �����º���
	template<<class T> T modulus<T>          ȡģ�º���
	template<<class T> T negate<T>           ȡ���º���

*/

#include<iostream>
#include<functional>
using namespace std;

void test()
{
	negate<int>n;//negate һԪ�º��� ȡ���º���
	cout << n(50);//���-50

	plus<int>p;//plus ��Ԫ�º��� �ӷ��º�����ֻ��дһ���������ͣ�plusֻ����ͬ�����Ͳ������
	cout << p(10, 20);//���30
}
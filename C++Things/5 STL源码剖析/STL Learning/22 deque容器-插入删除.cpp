#include <iostream>
#include<string>
#include<deque>
using namespace std;


void printdeque(const deque<int>& d)//添加const使容器中的数据不可被修改
{
	for (deque<int>::const_iterator it = d.begin(); it != d.end(); it++)
	{
		cout << *it << " ";
	}
	cout << endl;
}
void test()
{
	deque<int>d1;
	for (int i = 0; i < 10; i++)
	{
		d1.push_back(i);
	}
	printdeque(d1);

	//尾插
	d1.push_back(10);
	d1.push_back(20);

	//头插
	d1.push_front(100);
	d1.push_front(200);

	//尾删
	d1.pop_back();

	//头删
	d1.pop_front();

	//insert插入
	//初始为200、100、10、20
	d1.insert(d1.begin(), 1000);//1000、200、100、10、20

	d1.insert(d1.begin(), 2, 10000);//10000、10000、1000、200、100、10、20

	//按照区间插入
	deque<int>d2;
	d2.push_back(1);
	d2.push_back(2);
	d2.push_back(3);

	d1.insert(d1.begin(), d2.begin(), d2.end());//1、2、3、10000、10000、1000、200、100、10、20

	//删除
	d1.erase(d1.begin());//2、3、10000、10000、1000、200、100、10、20
	deque<int>::iterator it = d1.begin();
	it++;
	d1.erase(it);//2、10000、10000、1000、200、100、10、20

	d1.erase(d1.begin(), d1.end());

}
#include <iostream>
#include<string>
#include<deque>
#include<algorithm>
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

	//通过[]访问
	for (int i = 0; i < d1.size(); i++)
	{
		cout << d1[i] << " ";
	}
	
	//通过at访问
	for (int i = 0; i < d1.size(); i++)
	{
		cout << d1.at(i) << " ";
	}

	cout << "第一个元素是" << d1.front() << endl;
	cout << "最后一个元素是" << d1.back() << endl;

	//排序
	deque<int>d2;
	d2.push_back(10);
	d2.push_back(20);
	d2.push_back(30);
	d2.push_front(100);
	d2.push_front(200);
	d2.push_front(300);//300、200、100、10、20、30
	
	sort(d2.begin(), d2.end());
	//排序 默认排序规则是从小到大，升序
	//对于支持随机访问的迭代器的容器，都可以利用sory算法直接对其进行排序
	//vector容器也可以利用sort进行排序
}
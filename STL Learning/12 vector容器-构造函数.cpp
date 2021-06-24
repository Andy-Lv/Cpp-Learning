//vector数据结构和数组非常相似，也成为单端数组
//不同之处在于数组是静态控件，vector是动态扩展
//并不是在原有的空间，而是找到更大的内存空间，将源数据拷贝到新空间，释放原空间

#include <iostream>
#include<string>
#include<vector>
using namespace std;

void printvector(vector<int>v)
{
	for (vector<int>::iterator it = v.begin(); it != v.end(); it++)
	{
		cout << *it << " ";
	}
	cout << endl;
}

void test()
{
	//默认构造，无参构造
	vector<int>v1;
	for (int i = 0; i < 10; i++)
	{
		v1.push_back(i);
	}
	printvector(v1);

	//通过区间的方式进行构造
	vector<int>v2(v1.begin(), v1.end());
	printvector(v2);

	//n个element方式构造
	vector<int>v3(10, 100);//10个100
	printvector(v3);

	//拷贝构造
	vector<int>v4(v3);
	printvector(v4);
}
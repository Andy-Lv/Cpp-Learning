#include <iostream>
#include<string>
using namespace std;

template<class T>
class MyArray
{
public:
	//有参构造 参数 容量
	MyArray(int Capacity)
	{
		this->m_Capacity = Capacity;
		this->m_Size = 0; 
		this->pAddress = new T[this->m_Capacity];
	}
	//尾插法
	void PushBack(const T & val)
	{
		if (this->m_Capacity == this->m_Size)
		{
			return;
		}
		this->pAddress[this->m_Size] = val;
		this->m_Size++;
	}
	//尾删法
	void PopBack()
	{
		//让用户访问不到最后一个元素，即为尾删，逻辑删除
		if (this->m_Capacity == this->m_Size)
		{
			return;
		}
		this->m_Size--;
	}
	//通过下标访问数组中的数据
	T& operator[](int index)//传入下标
	{
		return this->pAddress[index];
	}
	//返回数组的容量
	int getCapacity()
	{
		return this->m_Capacity;
	}
	//
	int getSize()
	{
		return this->m_Size;
	}
	~MyArray()
	{
		if (this->m_Capacity!=NULL)
		{
			delete[] this->pAddress;
			this->pAddress = NULL;
		}
	}
	//拷贝构造
	MyArray(const MyArray& arr)
	{
		this->m_Capacity = arr.m_Capacity;
		this->m_Size = arr.m_Size;
		//深拷贝
		this->pAddress = new T[arr.m_Capacity];
		//将arr中的数据拷贝过来
		for (int i = 0; i < this->m_Size; i++)
		{
			this->pAddress[i] = arr.pAddress[i];
		}
	}

	//operator=防止浅拷贝问题
	MyArray& operator=(const MyArray& arr)
	{
		if (this-> != NULL)
		{
			delete[] this->pAddress;
			this->pAddress = NULL;
			this->m_Capacity = 0;
			this->m_Size = 0;
		}
		//深拷贝,防止地址重复释放 
		this->m_Capacity = arr.m_Capacity;
		this->m_Size = arr.m_Size;
		this->pAddress = new T[arr.m_Capacity];
		for (int i = 0; i < this->m_Size; i++)
		{
			this->pAddress[i] = arr.pAddress[i];
		}
		return *this;
	}
private:
	T* pAddress;//指针指向堆区开辟的真实数组
	int m_Capacity;//数组容量
	int m_Size;//元素个数
};


class Person
{
public:
	Person() {};//默认构造函数
	Person(string name, int age)//有参构造
	{
		this->m_name = name;
		this->m_age = age;
	}

	string m_name;
	int m_age;
};

void printIntArray(MyArray <int> &arr1)
{
	for (int i = 0; i < arr1.getSize(); i++)
	{
		cout << arr1[i] << endl;
	}
}
void test()
{
	MyArray <int>arr1(5);

	for (int i = 0; i < 5; i++)
	{
		//利用尾插法增加数据
		arr1.PushBack(i);
	}
	printIntArray(arr1);
	cout << "arr的容量为" << arr1.getCapacity() << endl;
	cout << "arr的容量为" << arr1.getSize() << endl;

	MyArray <int>arr2(arr1);//拷贝
	cout << "arr2打印输出为：" << endl; 
	printIntArray(arr2);
	arr2.PopBack();
	cout << "arr2尾删后：" << endl;
	cout << "arr的容量为" << arr1.getCapacity() << endl;
	cout << "arr的容量为" << arr1.getSize() << endl;
}

void pringpersonarr(MyArray<Person> &arr)
{
	for (int i = 0; i < arr.getSize(); i++)
	{
		cout << arr[i].m_name << " " << arr[i].m_age << endl;
	}
	
}

void test02()
{

	MyArray<Person>arr(10);

	Person p1("孙悟空", 999);
	Person p2("猪八戒", 999);
	Person p3("沙悟净", 999);
	Person p4("唐三藏", 999);

	arr.PushBack(p1);
	arr.PushBack(p2);
	arr.PushBack(p3);
	arr.PushBack(p4);

	pringpersonarr(arr);
	
	cout << "arr的容量为" << arr.getCapacity() << endl;
	cout << "arr的容量为" << arr.getSize() << endl;
}
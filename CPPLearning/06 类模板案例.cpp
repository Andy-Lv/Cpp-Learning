#include <iostream>
#include<string>
using namespace std;

template<class T>
class MyArray
{
public:
	//�вι��� ���� ����
	MyArray(int Capacity)
	{
		this->m_Capacity = Capacity;
		this->m_Size = 0; 
		this->pAddress = new T[this->m_Capacity];
	}
	//β�巨
	void PushBack(const T & val)
	{
		if (this->m_Capacity == this->m_Size)
		{
			return;
		}
		this->pAddress[this->m_Size] = val;
		this->m_Size++;
	}
	//βɾ��
	void PopBack()
	{
		//���û����ʲ������һ��Ԫ�أ���Ϊβɾ���߼�ɾ��
		if (this->m_Capacity == this->m_Size)
		{
			return;
		}
		this->m_Size--;
	}
	//ͨ���±���������е�����
	T& operator[](int index)//�����±�
	{
		return this->pAddress[index];
	}
	//�������������
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
	//��������
	MyArray(const MyArray& arr)
	{
		this->m_Capacity = arr.m_Capacity;
		this->m_Size = arr.m_Size;
		//���
		this->pAddress = new T[arr.m_Capacity];
		//��arr�е����ݿ�������
		for (int i = 0; i < this->m_Size; i++)
		{
			this->pAddress[i] = arr.pAddress[i];
		}
	}

	//operator=��ֹǳ��������
	MyArray& operator=(const MyArray& arr)
	{
		if (this-> != NULL)
		{
			delete[] this->pAddress;
			this->pAddress = NULL;
			this->m_Capacity = 0;
			this->m_Size = 0;
		}
		//���,��ֹ��ַ�ظ��ͷ� 
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
	T* pAddress;//ָ��ָ��������ٵ���ʵ����
	int m_Capacity;//��������
	int m_Size;//Ԫ�ظ���
};


class Person
{
public:
	Person() {};//Ĭ�Ϲ��캯��
	Person(string name, int age)//�вι���
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
		//����β�巨��������
		arr1.PushBack(i);
	}
	printIntArray(arr1);
	cout << "arr������Ϊ" << arr1.getCapacity() << endl;
	cout << "arr������Ϊ" << arr1.getSize() << endl;

	MyArray <int>arr2(arr1);//����
	cout << "arr2��ӡ���Ϊ��" << endl; 
	printIntArray(arr2);
	arr2.PopBack();
	cout << "arr2βɾ��" << endl;
	cout << "arr������Ϊ" << arr1.getCapacity() << endl;
	cout << "arr������Ϊ" << arr1.getSize() << endl;
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

	Person p1("�����", 999);
	Person p2("��˽�", 999);
	Person p3("ɳ��", 999);
	Person p4("������", 999);

	arr.PushBack(p1);
	arr.PushBack(p2);
	arr.PushBack(p3);
	arr.PushBack(p4);

	pringpersonarr(arr);
	
	cout << "arr������Ϊ" << arr.getCapacity() << endl;
	cout << "arr������Ϊ" << arr.getSize() << endl;
}
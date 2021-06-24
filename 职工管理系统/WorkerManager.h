#pragma once//防止同文件重复包含
#include<iostream>
#include<fstream>
using namespace std;
#define FILENAME "公司人员.txt"

class WorkerManager
{
public:
	WorkerManager();

	void ShowMenu();

	void ExitSystem();

	int m_EmpNum;//记录职工人数

	Worker** m_EmpArray;//职工数组指针
	
	void AddEmployor();

	void Save();

	bool FileIsEmpty;//判断文件是否为空

	int GetNum();//获取当前员工人数

	void InitEmp();//初始化员工

	void ShowEmployor();

	void DeleteEmployor();

	void ModifyEmployor();

	void SeekEmployor();

	void SortEmployor();

	void CleanEmployor();

	~WorkerManager();
};

class Worker//职工抽象基类
{
public:
	virtual void ShowInformation() = 0;//显示个人信息

	virtual string GetDeptName() = 0;//获取职工部门名称

	int m_ID;//职工编号
	string m_Name;//职工姓名
	int m_DeptID;//职工所在部门编号
};

class Employee :public Worker
{
public:
	Employee(int ID, string name, int DeptID);

	virtual void ShowInformation();

	virtual string GetDeptName();
};

class Employor :public Worker
{
public:
	Employor(int ID, string name, int DeptID);

	virtual void ShowInformation();

	virtual string GetDeptName();
};

class Manager :public Worker
{
public:
	Manager(int ID, string name, int DeptID);

	virtual void ShowInformation();

	virtual string GetDeptName();
};
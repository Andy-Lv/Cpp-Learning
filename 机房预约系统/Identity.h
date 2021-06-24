#pragma once
#include<iostream>
#include<fstream>
#include<string>
#include<vector>
#include<algorithm>
#include<map>
#include"GloableFile.h"

using namespace std;

class Identity
{
public:
	//操作菜单，纯虚函数
	virtual void OpenMenu() = 0;

	//用户名和密码
	string m_Name;
	string m_Password;
};

class Student :public Identity
{
public:
	//默认构造
	Student();

	//有参构造
	Student(int ID, string name, string password);

	//菜单界面
	virtual void OpenMenu();

	//申请预约
	void ApplyOrder();

	//查看自身预约
	void ShowOrder();

	//查看所有预约
	void ShowAllOrder();

	//取消预约
	void CancelOrder();

	//学生学号
	int ID;

	//机房容器
	vector<ComputerRoom>vCom;
};

class Teacher :public Identity
{
public:
	Teacher();

	//有参构造
	Teacher(int empID, string name, string password);

	//打开菜单
	virtual void OpenMenu();

	//查看所有预约
	void ShowAllOrder();

	//审核预约
	void ValidOrder();

	int ID;
};

class Manager :public Student
{
public:
	Manager();

	//有参构造
	Manager(string name, string password);

	//打开菜单
	virtual void OpenMenu();

	//添加人员
	void AddPerson();

	//查看账号
	void ShowPerson();

	//查看机房
	void ShowComputer();

	//清空预约记录
	void CleanFile();

	//初始化容器
	void InitVector();

	//检测重复
	bool CheckRepeat(int id, int type);

	//学生容器
	vector<Student>vStu;

	//老师容器
	vector<Teacher>vTea;

	vector<ComputerRoom>vCom;
};

class ComputerRoom
{
public:
	int ID;//机房编号

	int m_MaxNumber;//机房最大容量
};

class OrderFile
{
public:
	OrderFile();

	//更新预约记录
	void updateOrder();

	//记录预约条数
	int m_Size;

	//记录所有预约信息的容器
	map<int, map<string, string>>m_OrderData;
};

void LoginIn(string filename, int type);

void ManagerMenu(Identity*& manager);

void StudentMenu(Identity*& student);

void TeacherMenu(Identity*& teacher);
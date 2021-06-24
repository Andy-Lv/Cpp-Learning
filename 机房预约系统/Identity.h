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
	//�����˵������麯��
	virtual void OpenMenu() = 0;

	//�û���������
	string m_Name;
	string m_Password;
};

class Student :public Identity
{
public:
	//Ĭ�Ϲ���
	Student();

	//�вι���
	Student(int ID, string name, string password);

	//�˵�����
	virtual void OpenMenu();

	//����ԤԼ
	void ApplyOrder();

	//�鿴����ԤԼ
	void ShowOrder();

	//�鿴����ԤԼ
	void ShowAllOrder();

	//ȡ��ԤԼ
	void CancelOrder();

	//ѧ��ѧ��
	int ID;

	//��������
	vector<ComputerRoom>vCom;
};

class Teacher :public Identity
{
public:
	Teacher();

	//�вι���
	Teacher(int empID, string name, string password);

	//�򿪲˵�
	virtual void OpenMenu();

	//�鿴����ԤԼ
	void ShowAllOrder();

	//���ԤԼ
	void ValidOrder();

	int ID;
};

class Manager :public Student
{
public:
	Manager();

	//�вι���
	Manager(string name, string password);

	//�򿪲˵�
	virtual void OpenMenu();

	//�����Ա
	void AddPerson();

	//�鿴�˺�
	void ShowPerson();

	//�鿴����
	void ShowComputer();

	//���ԤԼ��¼
	void CleanFile();

	//��ʼ������
	void InitVector();

	//����ظ�
	bool CheckRepeat(int id, int type);

	//ѧ������
	vector<Student>vStu;

	//��ʦ����
	vector<Teacher>vTea;

	vector<ComputerRoom>vCom;
};

class ComputerRoom
{
public:
	int ID;//�������

	int m_MaxNumber;//�����������
};

class OrderFile
{
public:
	OrderFile();

	//����ԤԼ��¼
	void updateOrder();

	//��¼ԤԼ����
	int m_Size;

	//��¼����ԤԼ��Ϣ������
	map<int, map<string, string>>m_OrderData;
};

void LoginIn(string filename, int type);

void ManagerMenu(Identity*& manager);

void StudentMenu(Identity*& student);

void TeacherMenu(Identity*& teacher);
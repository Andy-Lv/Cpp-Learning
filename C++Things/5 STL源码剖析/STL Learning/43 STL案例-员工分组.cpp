#include<iostream>
#include<map>
#include<string>
#include<vector>
#include<ctime>

using namespace std;

#define CEHUA 0
#define MEISHU 1
#define YANFA 2


class Worker
{
public:
	string m_Name;
	int m_Salary;
};

void CreateWorker(vector<Worker>&w)
{
	string nameseed = "ABCDEFGHIJ";
	for (int i = 0; i < 10; i++)
	{
		Worker worker;
		worker.m_Name = "员工";
		worker.m_Name += nameseed[i];

		worker.m_Salary = rand() % 10000 + 10000;

		w.push_back(worker);
	}
}

void SetGroup(vector<Worker>&w, multimap<int, Worker>&m)
{
	for (vector<Worker>::iterator it = w.begin(); it!=w.end(); it++)
	{
		//产生随机部门编号
		int deptID = rand() % 3;
		m.insert(make_pair(deptID, *it));
	}
}

void ShowWorkerGroup(multimap<int, Worker>& m)
{
	cout << "策划部门" << endl;
	multimap<int, Worker>::iterator pos = m.find(CEHUA);
	int count = m.count(CEHUA);
	int index = 0;
	for (; pos != m.end()&&index<count;index++, pos++)
	{
		cout << "姓名:" << pos->second.m_Name << " 薪水：" << pos->second.m_Salary << endl;
	}

	cout << "美术部门" << endl;
	multimap<int, Worker>::iterator pos = m.find(MEISHU);
	int count = m.count(MEISHU);
	int index = 0;
	for (; pos != m.end() && index < count; index++, pos++)
	{
		cout << "姓名:" << pos->second.m_Name << " 薪水：" << pos->second.m_Salary << endl;
	}

	cout << "研发部门" << endl;
	multimap<int, Worker>::iterator pos = m.find(YANFA);
	int count = m.count(YANFA);
	int index = 0;
	for (; pos != m.end() && index < count; index++, pos++)
	{
		cout << "姓名:" << pos->second.m_Name << " 薪水：" << pos->second.m_Salary << endl;
	}
}
int main()
{
	srand((unsigned int)time(NULL));
	vector<Worker>w;

	CreateWorker(w);

	//员工分组
	multimap<int, Worker>m;

	SetGroup(w, m);

	ShowWorkerGroup(m);
}
#include"SpeechManager.h"

SpeechManager::SpeechManager()
{
	//初始化程序
	this->InitSpeech();

	this->CreateSpeaker();
}

void SpeechManager::ShowMenu()
{
	cout << "*************************************" << endl;
	cout << "**********欢迎参加演讲比赛***********" << endl;
	cout << "**********1、开始演讲比赛************" << endl;
	cout << "**********2、查看往届记录************" << endl;
	cout << "**********3、清空比赛记录************" << endl;
	cout << "**********0、退出比赛程序************" << endl;
	cout << "*************************************" << endl;
	cout << endl;
}

void SpeechManager::ExitSystem()
{
	cout << "欢迎下次使用" << endl;
	system("pause");

	exit(0);//此函数可以直接退出系统
}

void SpeechManager::InitSpeech()
{
	//容器都是空
	this->V1.clear();
	this->V2.clear();
	this->vVictory.clear();
	this->m_Speaker.clear();

	this->m_index = 1;

}

void SpeechManager::CreateSpeaker()
{
	string nameSeed = "ABCDEFGHIJKL";

	for (int i = 0; i < nameSeed.size(); i++)
	{
		string name = "选手";
		name += nameSeed[i];

		Speaker sp;
		sp.m_name = name;
		for (int j = 0; j < 2; j++)
		{
			sp.m_Score[j] = 0;
		}

		//选手编号
		this->V1.push_back(i + 1001);

		this->m_Speaker.insert(make_pair(i + 1001, sp));
	}
}

void SpeechManager::SpeechDraw()
{
	cout << "第" << this->m_index << "轮选手正在抽签" << endl;
	cout << "--------------------------------------------" << endl;

	if (this->m_index==1)
	{
		random_shuffle(V1.begin(), V1.end());
		for (vector<int>::iterator it = V1.begin(); it != V1.end(); it++)
		{
			cout << *it << " ";
		}
		cout << endl;
	}

	if (this->m_index == 2)
	{
		random_shuffle(V2.begin(), V2.end());
		for (vector<int>::iterator it = V2.begin(); it != V2.end(); it++)
		{
			cout << *it << " ";
		}
		cout << endl;
	}
	cout << "--------------------------------------------" << endl;
	system("pause");
	cout << endl;
}

void SpeechManager::SpeechContest()
{
	cout << "第" << this->m_index << "轮比赛正式开始" << endl;

	//存放小组成绩
	multimap<double, int, greater<double>>groupScore;

	int num = 0;//记录人员个数,6人一组

	vector<int>v_Src;//比赛人员容器

	if (m_index==1)
	{
		v_Src = V1;
	}
	if (m_index == 2)
	{
		v_Src = V2;
	}

	for (vector<int>::iterator it = v_Src.begin(); it != v_Src.end(); it++)
	{
		num++;
		//评委打分
		deque<double>d;
		for (int i = 0; i < 10; i++)
		{
			double score = (rand() % 401 + 600) / 10.f;
			d.push_back(score);
		}
		cout << endl;

		//去掉最低分和最高分
		sort(d.begin(), d.end());
		d.pop_back();
		d.pop_front();

		double sum = accumulate(d.begin(), d.end(), 0.0f);//0为起始总分，该函数为累加
		double avg = sum / (double)d.size();//平均分

		//输出每人成绩
		cout << "编号：" << *it << " 姓名" << this->m_Speaker[*it].m_name << " 平均分:" << avg << endl;

		//将平均分放入map容器中
		this->m_Speaker[*it].m_Score[this->m_index] = avg;

		//将数据放入小组容器中
		groupScore.insert(make_pair(avg, *it));
		if (num%6==0)
		{
			cout << "第" << num / 6 << "小组比赛名次：" << endl;
			for (multimap<double,int,greater<double>>::iterator it =groupScore.begin() ;it !=groupScore.end(); it++)
			{

				cout << "编号" << it->second << " 姓名" << this->m_Speaker[it->second].m_name << " 成绩" << this->m_Speaker[it->second].m_Score[this->m_index - 1] << endl;
				groupScore.clear();
			}
			//取前三名
			int count = 0;
			for (multimap<double, int, greater<double>>::iterator it = groupScore.begin(); it != groupScore.end(); it++)
			{
				if (this->m_index==1)
				{
					V2.push_back(it->second);
				}
				else
				{
					vVictory.push_back(it->second);
				}
			}
		}
	}
	cout << "第" << this->m_index << "轮比赛完毕" << endl;
	system("pause");
}

void SpeechManager::ShowScore()
{
	cout << "第" << this->m_index << "轮晋级选手信息如下" << endl;

	vector<int>v;
	if (this->m_index==1)
	{
		v = V2;
	}
	else
	{
		v = vVictory;
	}

	for (vector<int>::iterator it = v.begin(); it != v.end(); it++)
	{
		cout<<"选手编号为:"<<*it<<" 姓名："<<this->m_Speaker[*it].m_name << " 成绩" << this->m_Speaker[*it].m_Score[this->m_index - 1] << endl;
	}
	cout << endl;

	system("pause");
	system("cls");
	this->ShowMenu();
}

void SpeechManager::StartSpeech()
{
	//第一轮开始比赛
	//抽签
	this->SpeechDraw();
	//比赛
	this->SpeechContest();
	//比赛晋级结果
	this->ShowScore();
	//第二轮开始比赛
	this->m_index++;
	//开始比赛
	this->SpeechDraw();
	//比赛
	this->SpeechContest();
	//比赛晋级结果
	this->ShowScore();
}

void SpeechManager::SaveRecord()
{
	ofstream ofs;
	ofs.open("speech.csv", ios::out | ios::app);//app为追加的方法打开文件
	//将每个人的数据写到文件中
}

SpeechManager::~SpeechManager()
{

}
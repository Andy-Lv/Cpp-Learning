#pragma once
#include<iostream>
#include<vector>
#include<map>
#include<string>
#include<algorithm>
#include<deque>
#include<functional>
#include<numeric>
#include<fstream>
#include"Speaker.h"

using namespace std;

class SpeechManager//演讲管理类
{
public:
	SpeechManager();

	void ShowMenu();//显示菜单

	void ExitSystem();//推出程序

	void InitSpeech();//初始化容器

	void CreateSpeaker();//初始化12个参赛人员

	void StartSpeech();//开始比赛

	void SpeechDraw();//抽签

	void SpeechContest();//比赛

	void ShowScore();//显示得分

	void SaveRecord();

	~SpeechManager();

	//保存第一轮选手编号的容器
	vector<int>V1;

	//保存到第二轮的选手的编号容器
	vector<int>V2;

	//保存胜出的前三名
	vector<int>vVictory;

	//存放编号以及对应的人的容器
	map<int, Speaker>m_Speaker;

	//存放比赛轮数
	int m_index;
};

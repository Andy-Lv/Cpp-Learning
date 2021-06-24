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

class SpeechManager//�ݽ�������
{
public:
	SpeechManager();

	void ShowMenu();//��ʾ�˵�

	void ExitSystem();//�Ƴ�����

	void InitSpeech();//��ʼ������

	void CreateSpeaker();//��ʼ��12��������Ա

	void StartSpeech();//��ʼ����

	void SpeechDraw();//��ǩ

	void SpeechContest();//����

	void ShowScore();//��ʾ�÷�

	void SaveRecord();

	~SpeechManager();

	//�����һ��ѡ�ֱ�ŵ�����
	vector<int>V1;

	//���浽�ڶ��ֵ�ѡ�ֵı������
	vector<int>V2;

	//����ʤ����ǰ����
	vector<int>vVictory;

	//��ű���Լ���Ӧ���˵�����
	map<int, Speaker>m_Speaker;

	//��ű�������
	int m_index;
};

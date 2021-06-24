#include"SpeechManager.h"

SpeechManager::SpeechManager()
{
	//��ʼ������
	this->InitSpeech();

	this->CreateSpeaker();
}

void SpeechManager::ShowMenu()
{
	cout << "*************************************" << endl;
	cout << "**********��ӭ�μ��ݽ�����***********" << endl;
	cout << "**********1����ʼ�ݽ�����************" << endl;
	cout << "**********2���鿴�����¼************" << endl;
	cout << "**********3����ձ�����¼************" << endl;
	cout << "**********0���˳���������************" << endl;
	cout << "*************************************" << endl;
	cout << endl;
}

void SpeechManager::ExitSystem()
{
	cout << "��ӭ�´�ʹ��" << endl;
	system("pause");

	exit(0);//�˺�������ֱ���˳�ϵͳ
}

void SpeechManager::InitSpeech()
{
	//�������ǿ�
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
		string name = "ѡ��";
		name += nameSeed[i];

		Speaker sp;
		sp.m_name = name;
		for (int j = 0; j < 2; j++)
		{
			sp.m_Score[j] = 0;
		}

		//ѡ�ֱ��
		this->V1.push_back(i + 1001);

		this->m_Speaker.insert(make_pair(i + 1001, sp));
	}
}

void SpeechManager::SpeechDraw()
{
	cout << "��" << this->m_index << "��ѡ�����ڳ�ǩ" << endl;
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
	cout << "��" << this->m_index << "�ֱ�����ʽ��ʼ" << endl;

	//���С��ɼ�
	multimap<double, int, greater<double>>groupScore;

	int num = 0;//��¼��Ա����,6��һ��

	vector<int>v_Src;//������Ա����

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
		//��ί���
		deque<double>d;
		for (int i = 0; i < 10; i++)
		{
			double score = (rand() % 401 + 600) / 10.f;
			d.push_back(score);
		}
		cout << endl;

		//ȥ����ͷֺ���߷�
		sort(d.begin(), d.end());
		d.pop_back();
		d.pop_front();

		double sum = accumulate(d.begin(), d.end(), 0.0f);//0Ϊ��ʼ�ܷ֣��ú���Ϊ�ۼ�
		double avg = sum / (double)d.size();//ƽ����

		//���ÿ�˳ɼ�
		cout << "��ţ�" << *it << " ����" << this->m_Speaker[*it].m_name << " ƽ����:" << avg << endl;

		//��ƽ���ַ���map������
		this->m_Speaker[*it].m_Score[this->m_index] = avg;

		//�����ݷ���С��������
		groupScore.insert(make_pair(avg, *it));
		if (num%6==0)
		{
			cout << "��" << num / 6 << "С��������Σ�" << endl;
			for (multimap<double,int,greater<double>>::iterator it =groupScore.begin() ;it !=groupScore.end(); it++)
			{

				cout << "���" << it->second << " ����" << this->m_Speaker[it->second].m_name << " �ɼ�" << this->m_Speaker[it->second].m_Score[this->m_index - 1] << endl;
				groupScore.clear();
			}
			//ȡǰ����
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
	cout << "��" << this->m_index << "�ֱ������" << endl;
	system("pause");
}

void SpeechManager::ShowScore()
{
	cout << "��" << this->m_index << "�ֽ���ѡ����Ϣ����" << endl;

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
		cout<<"ѡ�ֱ��Ϊ:"<<*it<<" ������"<<this->m_Speaker[*it].m_name << " �ɼ�" << this->m_Speaker[*it].m_Score[this->m_index - 1] << endl;
	}
	cout << endl;

	system("pause");
	system("cls");
	this->ShowMenu();
}

void SpeechManager::StartSpeech()
{
	//��һ�ֿ�ʼ����
	//��ǩ
	this->SpeechDraw();
	//����
	this->SpeechContest();
	//�����������
	this->ShowScore();
	//�ڶ��ֿ�ʼ����
	this->m_index++;
	//��ʼ����
	this->SpeechDraw();
	//����
	this->SpeechContest();
	//�����������
	this->ShowScore();
}

void SpeechManager::SaveRecord()
{
	ofstream ofs;
	ofs.open("speech.csv", ios::out | ios::app);//appΪ׷�ӵķ������ļ�
	//��ÿ���˵�����д���ļ���
}

SpeechManager::~SpeechManager()
{

}
#include <iostream>
#include<string>
#include<deque>
#include<algorithm>
#include<vector>
#include<ctime>
using namespace std;

class Person
{
public:
    Person(string name, int score)
    {
        this->m_Name = name;
        this->m_Score = score;
    }
    string m_Name;
    int m_Score;
};


void creatperson(vector<Person>&v)
{
    string nameseed = "ABCDE";
    for (int i = 0; i < 5; i++)
    {
        string name = "ѡ��";
        name += nameseed[i];

        int score = 0;

        Person p(name, score);
        v.push_back(p);
    }
}

void setscore(vector<Person>& v)
{
    for (vector<Person>::iterator i = v.begin(); i != v.end(); i++)
    {
        cout << "��ί��" << i->m_Name << "��ķ���Ϊ";
        deque<int>d;
        for (int j = 0; j < 10; j++)
        {
            int score = rand() % 41 + 60;//60��100
            d.push_back(score);

            cout << score << " ";
        }

        cout << endl;

        //����
        sort(d.begin(), d.end());
        //ȥ����ͷֺ���߷�
        d.pop_back();
        d.pop_front();

        cout << "ȥ����ͷֺ���߷ֵõ��ķ���Ϊ";
        //ȡƽ����
        int avg = 0;
        for (deque<int>::iterator dit = d.begin(); dit !=d.end(); i++)
        {
            cout << *dit << " ";
            avg += *dit;
        }

        i->m_Score = avg / d.size();
        cout << i->m_Name << "���շ���Ϊ" << i->m_Score;
        cout << "**********************************************************" << endl;
    }
}
int main()
{
    //���������
    srand((unsigned int)time(NULL));
    //����ѡ��
    vector<Person>v;
    creatperson(v);
    //�����ѡ�ִ��
    setscore(v);
}
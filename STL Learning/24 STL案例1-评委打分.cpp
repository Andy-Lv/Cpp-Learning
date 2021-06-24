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
        string name = "选手";
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
        cout << "评委给" << i->m_Name << "打的分数为";
        deque<int>d;
        for (int j = 0; j < 10; j++)
        {
            int score = rand() % 41 + 60;//60到100
            d.push_back(score);

            cout << score << " ";
        }

        cout << endl;

        //排序
        sort(d.begin(), d.end());
        //去除最低分和最高分
        d.pop_back();
        d.pop_front();

        cout << "去掉最低分和最高分得到的分数为";
        //取平均分
        int avg = 0;
        for (deque<int>::iterator dit = d.begin(); dit !=d.end(); i++)
        {
            cout << *dit << " ";
            avg += *dit;
        }

        i->m_Score = avg / d.size();
        cout << i->m_Name << "最终分数为" << i->m_Score;
        cout << "**********************************************************" << endl;
    }
}
int main()
{
    //随机数种子
    srand((unsigned int)time(NULL));
    //创建选手
    vector<Person>v;
    creatperson(v);
    //给五个选手打分
    setscore(v);
}
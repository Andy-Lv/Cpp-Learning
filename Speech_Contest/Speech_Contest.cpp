#include <iostream>
#include"SpeechManager.h"


int main()
{
    //创建演讲者对象
    SpeechManager SM;

    int choice;
    
    while (true)
    {
        SM.ShowMenu();
        cin >> choice;

        switch (choice)
        {
        case 1://开始演讲比赛
            SM.StartSpeech();
            break;
        case 2://查看往届记录
            break;
        case 3://清空比赛记录
            break;
        case 0://退出比赛程序
            SM.ExitSystem();
            break;
        default:
            system("cls");//清屏
            break;
        }
    }
}


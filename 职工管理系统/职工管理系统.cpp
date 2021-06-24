#include <iostream>
#include<string>
#include"WorkerManager.h"

using namespace std;

int main()
{
    //实例化管理者对象
    WorkerManager wm;

    int choice;
    
    cout << "请输入选择的功能" << endl;

    while (true)
    {
        //显示菜单
        wm.ShowMenu();

        cin >> choice;

        switch (choice)
        {
        case 1://添加职工
            wm.AddEmployor();
            break;
        case 2://显示职工
            wm.ShowEmployor();
            break;
        case 3://删除职工
            wm.DeleteEmployor();
            break;
        case 4://修改职工
            wm.ModifyEmployor();
            break;
        case 5://查找职工
            wm.SeekEmployor();
            break;
        case 6://排序职工
            wm.SortEmployor();
            break;
        case 7://清空文档
            wm.CleanEmployor();
            break;
        case 0://退出系统
            wm.ExitSystem();
            break;
        default:
            system("cls");
        }
    }

    system("pause");

    return 0;
}
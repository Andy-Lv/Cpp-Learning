//
// Created by andy on 2021/6/30.
//

#include<iostream>
#include<cstdlib>
using namespace std;

int rolldice()//两个色子点数之和
{
    int sum=0;
    int dim1 = rand()%6+1;//0到6的随机数
    int dim2 = rand()%6+1;
    sum = dim1+dim2;
    cout<<"sum="<<dim1<<"+"<<dim2<<endl;
    return sum;
}

int main()
{
    int flag;
    unsigned seed;
    cout<<"请输入随机数种子"<<endl;
    cin>>seed;
    srand(seed);
    int sum = rolldice();
    int selfdim;
    switch(sum)
    {
        case 7:
        case 11:
            flag=1;
            break;
        case 2:
        case 3:
        case 12:
            flag=2;
            break;
        default:
            flag=0;
            selfdim=sum;
            break;
    }
    while(flag==0)
    {
        sum=rolldice();
        if(sum==selfdim)
        {
            flag=1;
        }
        else if(sum==7)
        {
            flag=2;
        }
    }
    if(flag==1)
    {
        cout<<"player win\n";
    }
    else
    {
        cout<<"player loses\n";
    }

    system("pause");
    return 0;
}


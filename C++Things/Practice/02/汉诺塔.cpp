//
// Created by andy on 2021/6/30.
//

#include<iostream>
using namespace std;

void move(char A, char B)//显示棋子移动方向
{
    cout<<A<<"->"<<B<<endl;
}

void hanoi(int n, char A, char B, char C)
{
    if (n==1)
    {
        move(A,C);
    }
    else
    {
        hanoi(n-1,A,C,B);
        move(A,C);
        hanoi(n-1,B,A,C);
    }
}

int main(int argc, char const *argv[])
{
    cout<<"输入汉诺塔的个数";
    int disks;
    cin>>disks;
    hanoi(disks,'A','B','C');

    return 0;
}



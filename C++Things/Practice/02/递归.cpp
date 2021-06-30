//
// Created by andy on 2021/6/30.
//

#include<iostream>
using namespace std;

int f(int n)//实现 阶乘
{
    if(n==0)
    {
        return 1;
    }
    else
    {
        return n*f(n-1);
    }
}

int f(int n, int k)
{
    if ((n==k)||(k==0))
    {
        return 1;
    }
    else
    {
        return f(n-1,k-1)+f(n-1,k);
    }
}

int main(int argc, char const *argv[])
{
    cout<<"input x:";
    int x;
    cin>>x;
    cout<<f(x)<<endl;//实现 阶乘

    cout<<"ÇëÊäÈënÓëk"<<endl;
    int n,k;
    cin>>n;
    cin>>k;
    cout<<f(n,k)<<endl;

    return 0;
}


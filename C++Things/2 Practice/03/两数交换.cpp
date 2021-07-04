//
// Created by andy on 2021/6/30.
//

#include<iostream>
using namespace std;
void swap(int & a, int & b);
int main()
{
    int x1(5);
    int x2(7);
    swap(x1,x2);
    cout<<x1<<" "<<x2<<endl;

    return 0;
}

void swap(int & a, int & b)
{
    int t;
    t = a;
    a = b;
    b = t;

}
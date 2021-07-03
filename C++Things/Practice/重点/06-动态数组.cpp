//
// Created by andy on 2021/7/3.
//

#include <iostream>
#include <cstring>

using namespace std;

int main()
{
    char *sPtr;
    const char *s="hello";
    sPtr=new char[strlen(s)+1];
    strncpy(sPtr,s, strlen(s));
    cout<<sPtr<<endl;
    delete sPtr;
}
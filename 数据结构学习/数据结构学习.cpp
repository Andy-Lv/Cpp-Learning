#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string>
#include<stdlib.h>
#include <iostream>

struct dynamicArray
{
    void** pAddr;//维护在堆区的真实数组指针

    int m_capacity;//数组容量

    int m_size;//数组大小
};

//

int main()
{
    std::cout << "Hello World!\n";
}


//
// Created by andy on 2021/7/4.
//

#include <iostream>

using namespace std;

template<typename T,int MAXSIZE>

class Stack{
public:
    Stack(){};
    void init()
    {
        top=-1;
    }

    bool isFull()
    {
        if (top>=MAXSIZE-1)
            return true;
        else
            return false;
    }

    bool isEmpty()
    {
        if (top==-1)
            return true;
        else
            return false;
    }

    void push (T e);
    T pop();

private:
    T elems[MAXSIZE];
    int top;
};

template<typename T,int MAXSIZE>void Stack<T,maxsize>::push(T e)
{
    if(!isFull())
    {
        elems[++top]=e;
    }
    else
    {
        cout<<"栈已满,请不要再加入元素";
        return;
    }
}

template<typename T,int Maxsize>T Stack<T,MAXSIZE>::pop()
{
    if(!isEmpty())
    {
        elems[top--]=e;
    }
    else
    {
        cout<<"栈已空,请不要再弹出元素";
        return 0;
    }
}

int main()
{
    Stack<int,10>s1;
    s1.init();
    int i;
    for(i=1;i<11;i++)
        cout<<s1.pop()<<"\t";
    cout<<endl;

    return 0;
}
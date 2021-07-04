//
// Created by andy on 2021/7/3.
//

#include <cstring
#include <iostream>

using namespace std;

template<class T>
T compareMax(T t1, T t2)
{
    return t1 > t2 ? t1 : t2;
}

template<>
const char *compareMax<const char *>(const char *s1, const char *s2)
{
    cout << "[for debug]" << "call compareMax template" << endl;
    return strcmp(s1, s2) >= 0 ? s1 : s2;
}

int main()
{
    cout << compareMax(1, 2) << endl;
    cout << compareMax("abcd", "efgh") << endl;
    return 0;
}
//
// Created by andy on 2021/6/30.
//

#include <iostream>

using namespace std;

int main()
{
    int i, k, j, f;
    for (int i = 0; i < 4; ++i)
    {
        for (int j = 0; j <= 30; ++j)
        {
            cout << " ";
        }
        for (int k = 0; k < 8 - 2 * i; ++k)
        {
            cout << " ";
        }
        for (int f = 0; f < 2 * i; ++f)
        {
            cout << " ";
        }
    }
    for (i = 1; i <= 3; i++)
    {
        for (j = 1; j <= 30; j++)
            cout << " ";
        for (f = 1; f <= 7 - 2 * i; f++)
            cout << '*';
        cout << endl;
    }
    return 0;
}
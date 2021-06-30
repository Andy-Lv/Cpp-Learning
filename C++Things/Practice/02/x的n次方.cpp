//
// Created by andy on 2021/6/30.
//

#include <iostream>

using namespace std;

double power(double x, int n);

int main()
{
    int x;
    cin >> x;
    int wei = 0;
    int sum = 0;
    int each, chu;
    for (int i = 0; i < 8; i++)
    {
        each = x % 10;
        chu = x / 10;
        sum += each * power(2, wei);
        x = chu;
        wei++;
    }
    cout << sum << endl;
    return 0;
}

double power(double x, int n)
{
    double val = 1.0;
    while (n--)
    {
        val *= x;
    }
    return val;
}
/*
Author  : zsl
Problem : p1212 easy recursive problem
*/
//f(n) = f(0) + f(1) + f(2) + ... + f(n/2)
#include <iostream>
using namespace std;

int fun(int n)
{
    int sum = 0;
    if (n == 1 || n == 0)
    {
        return 1;
    }
    else
    {
        for (int i = 0; i <= n / 2; ++i)
        {
            sum += fun(i);
        }
    }
    return sum;
}

int main(int argc, char const *argv[])
{
    int n;
    cin >> n;
    cout << fun(n);
    return 0;
}
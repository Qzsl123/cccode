/*
Author  : zsl
Problem : p1212 汉诺塔问题
*/
#include <iostream>
#include <math.h>
using namespace std;
void mov(int x, char from, char to)
{
    cout << x << " from " << from << " to " << to << endl;
}

void hanoi(int n, char from, char depend_on, char to)
{
    if (n == 1)
    {
        mov(n, from, to);
    }
    else
    {
        hanoi(n - 1, from, to, depend_on);
        mov(n, from, to);
        hanoi(n - 1, depend_on, from, to);
    }

}

int main(int argc, char const *argv[])
{
    int n;
    cin >> n;
    cout << pow(2, n) - 1 << endl;
    hanoi(n, 'A', 'B', 'C');


    return 0;
}


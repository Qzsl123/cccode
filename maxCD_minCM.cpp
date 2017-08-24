/************************************************
* 作者:zsl
* 题目:p3038 max common divisor and min common multiple problem
**************************************************/
#include <iostream>
using namespace std;

int MinCM(int x, int y);
int MaxCD(int x, int y);

int main(int argc, char const *argv[])
{
    int input1, input2, sum = 0;
    cin >> input1 >> input2;

    cout << MaxCD(input1, input2) << " " << MinCM(input1, input2) << endl;
    return 0;
}

int MaxCD(int x, int y)
{
    int tmp;
    if(x > y)
    {
        tmp = x;
        x = y;
        y = tmp;
    }
    int r = x;
    while(r != 0)
    {
        r = y % x;
        y = x;
        x = r;
    }
    return y;
}
int MinCM(int x, int y)
{
    return x * y / (MaxCD(x, y));
}
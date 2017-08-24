/*
Author  : zsl
Problem : p1098 aver card --greed problem N堆纸牌，要求均分，求最小移动次数
Solution: 从最左边的纸牌堆开始，若等于aver，跳过，否则从右边相邻堆增补
*/
#include <iostream>
#include <math.h>
using namespace std;

int main(int argc, char const *argv[])
{
    int n, aver, count = 0;
    int a[100], offset[100];
    cin >> n;
    for (int i = 0; i < n; ++i)
    {
        cin >> a[i];
    }
    for (int i = 0; i < n; ++i)
    {
        aver += a[i];
    }
    aver /= n;
    for (int i = 0; i < n; ++i)
    {
        offset[i] = a[i] - aver;
    }
    for (int i = 0; i < n; ++i)
    {
        if (offset[i] == 0)
        {
            continue;
        }
        else
        {
            offset[i + 1] += offset[i];
            count++;
        }
    }
    cout << count << endl;
    return 0;
}
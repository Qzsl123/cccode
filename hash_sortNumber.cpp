/*
* 输入： 给定n个数（-500000,500000），从大到小输出前m大的数（m,n < 100000）
*/
#include <iostream>
using namespace std;
#define max 1000000
#define offset 500000
int buf[max];
int main()
{
    int n, m, a[n];

    cin >> n >> m;
    for(int i = 0; i < max; i++)
    buf[i] = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        buf[a[i] + offset] = 1;
    }

    for (int i = max - 1; i >= 0; i--)
    {
        if (buf[i] == 1)
        {
            cout << i - offset;
            m--;
            if (m != 0)
                cout << " ";
            else
            {
                cout << endl;
                break;
            }
        }
    }
    return 0;
}
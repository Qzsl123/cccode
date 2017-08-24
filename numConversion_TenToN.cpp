/*
Author  : zsl
Problem : p1212 进制转换 10进制 to n进制
*/
#include <iostream>
#include <string>
using namespace std;

int main(int argc, char const *argv[])
{
    int n, m;
     cin >> n >> m;
    char array[] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'A', 'B', 'C', 'D', 'E', 'F'};
    string ans;
    while(n)
    {
        ans = array[n % m] + ans;
        n = n / m;
    }
    cout << ans;

    return 0;
}


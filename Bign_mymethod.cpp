#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
#define max 500

void add(char s1[], char s2[], int lenth1, int lenth2)
{
    
    int lenth3 = (lenth1 > lenth2 ? lenth1 : lenth2);
    int num1[lenth1], num2[lenth2], res[lenth3];

    for (int i = 0; i < lenth1; ++i)
    {
        num1[lenth1 - i - 1] = s1[i] - '0';
    }

    for (int i = 0; i < lenth2; ++i)
    {
        num2[lenth2 - i - 1] = s2[i] - '0';
    }
    for (int i = 0, g = 0; g ||  i < lenth3 ; ++i)
    {
        int x = g;
        if(i < lenth1) x += num1[i];
        if(i < lenth2) x += num2[i];
        res[i] = x % 10;
        g = x / 10;
    }
    for (int i = 0; i < lenth3; ++i)
    {
        cout << res[lenth3 - i -1];
    }

}

int getLen(char *p)
{
    int count = 0;
    while(*p++) count++;
    return count;
}

int main(int argc, char const *argv[])
{
    int c1_len, c2_len;
    char c1[max], c2[max];
    cin >> c1 >> c2;

    c1_len = getLen(c1);
    c2_len = getLen(c2);
    //cout << c1_len << " " << c2_len << endl;
    add(c1, c2, c1_len, c2_len);

    return 0;
}
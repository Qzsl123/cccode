/*
*括号匹配问题
*无法匹配的左括号输出‘$’  无法匹配的右括号输出‘?’
*/
#include <iostream>
#include <stdio.h>
#include <stack>
using namespace std;
stack<int> s;
char str[100];
char ans[100];
int main()
{

    while (scanf("%s", str) != EOF)
    {
        int i;
        for (i = 0; str[i] != '\0'; i++)
        {
            if (str[i] == '(')
            {
                s.push(i);
                ans[i] = ' ';
            }
            else if (str[i] == ')')
            {
                if (s.empty() == false)
                {
                    s.pop();
                    ans[i] = ' ';
                }
                else
                {
                    ans[i] = '?';
                }
            }
            else
            {
                ans[i] = ' ';
            }
        }
        while (s.empty() == false)
        {
            ans[s.top()] = '$';
            s.pop();
        }
        ans[i] = '\0';
        puts(str);
        puts(ans);
    }
    return 0;
}

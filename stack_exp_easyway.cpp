/*
*输入表达式 + - * / 和非负整数  4 + 2 * 5 - 7 / 11
*输出运算结果 保留两位小数      13.36
*/
#include <iostream>
#include <stdio.h>
#include <stack>
using namespace std;
int main()
{
    int a;
    char b, c;
    double d;
    while (scanf("%d ", &a) && a != 0) //读取格式很关键，注意%d后面有空格，用于读取空格
    {
        stack<double> s;
        s.push(a);
        while (scanf("%c %d%c", &b, &a, &c) != EOF) //%c %d%c分别读取 符号空格数字及数字后的空格，如果数字后面没有空格，说明表达式结束
        {
            if (b == '+')
            {
                s.push(a);
            }
            else if (b == '-')
            {
                s.push(-1.0 * a);
            }
            else if (b == '*')
            {
                d = s.top() * a;
                s.pop();
                s.push(d);
            }
            else if (b == '/')
            {
                d = s.top() / a;
                s.pop();
                s.push(d);
            }

            if (c != ' ') //数字后无空格，不再录入，退出while循环
            {
                break;
            }
        }
        while (!s.empty())
        {
            if (s.size() == 1)
            {
                printf("%.2lf\n", s.top());
                break;
            }
            double d1 = s.top();
            s.pop();
            double d2 = s.top();
            s.pop();
            s.push(d1 + d2);
        }
    }
    return 0;
}
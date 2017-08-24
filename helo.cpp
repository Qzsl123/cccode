#include <stdio.h>
#include <string>
#include <cmath>
#include <iostream>
using namespace std;
int main()
{
        string s;
        while (cin >> s)
        {
                int base1 = 1, base2 = 1, count = 1, index = 0;
                float a = 0, b = 0, c = 0;
                while (index != s.length())
                {
                        if (s[index] == 'x')
                        {
                                if (index == s.length() - 1 || s[index + 1] != '^')
                                {
                                        b += (count * base1 * base2);
                                        index++;
                                }
                                else
                                {
                                        a += (count * base1 * base2);
                                        index += 3;
                                }
                                base2 = 1;
                                count = 1;
                        }
                        else if (s[index] == '=')
                        {
                                base1 = -1;
                                index++;
                        }
                        else if (s[index] == '+')
                                index++;
                        else if (s[index] == '-')
                        {
                                base2 = -1;
                                index++;
                        }
                        else if (s[index] >= '0' && s[index] <= '9')
                        {
                                int temp = s[index] - '0';
                                index++;
                                while (index != s.length() && s[index] >= '0' && s[index] <= '9')
                                {
                                        temp *= 10;
                                        temp += (s[index] - '0');
                                        index++;
                                }
                                if (index == s.length() || s[index] != 'x')
                                {
                                        c += (temp * base1 * base2);
                                        base2 = 1;
                                }
                                else
                                {
                                        count = temp;
                                }
                        }
                }
                if (b * b - a * c * 4 < 0)
                        printf("No Solution\n");
                else
                        printf("%.2f %.2f\n", (-b - sqrt(b * b - a * c * 4)) / (2 * a), (-b + sqrt(b * b - a * c * 4)) / (2 * a));
        }
        return 0;
}

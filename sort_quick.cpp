/*
*快速排序
*输入 4  
*     1 3 2 4
*输出  1 2 3 4
*
*/
#include <stdio.h>
#include <algorithm>
using namespace std;
bool cmp(int a, int b){
    return a > b;
}
int main(int argc, char const *argv[])
{
    int n;
    int buf[100];
    while(scanf("%d", &n) != EOF){
            for (int i = 0; i < n; ++i)
            {
                scanf("%d", &buf[i]);
            }
        
    sort(buf, buf+n, cmp);

        for (int i = 0; i < n; ++i)
        {
            printf("%d ", buf[i]);
        }
            printf("\n");
    }
    return 0;
}
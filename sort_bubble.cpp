/*
*简单冒泡排序
*输入 4  
*     1 3 2 4
*输出  1 2 3 4
*
*/
#include <stdio.h>

int main(int argc, char const *argv[])
{
    int n;
    int buf[100];
    while(scanf("%d", &n) != EOF){
            for (int i = 0; i < n; ++i)
            {
                scanf("%d", &buf[i]);
            }
        
        for (int i = 0; i < n; ++i)
        {
            for (int j = 0; j < n-1; ++j)
            {
                if (buf[j] > buf[j+1])
                {
                    int temp;
                    temp = buf[j];
                    buf[j] = buf[j+1];
                    buf[j+1] = temp;
                }
            }
        }
        for (int i = 0; i < n; ++i)
        {
            printf("%d ", buf[i]);
        }
            printf("\n");
    }
    return 0;
}
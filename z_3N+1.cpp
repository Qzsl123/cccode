
#include <stdio.h>
int main()
{
        int n, i, a, count = 0;
        int num[1001];
        for (i = 0; i <= 1000; i++) num[i] = 0;
        scanf("%d", &n);
        for (i = 0; i <= n - 1; i++)
    
    {
                scanf("%d", &a);
                num[a]++;
            
    }
        for (i = 1; i <= 1000; i++) if (num[i] > 0) count++;
        printf("%d\n", count);
        for (i = 1; i <= 1000; i++)
    if (num[i] > 0) printf("%d ", i);
        return 0;
}
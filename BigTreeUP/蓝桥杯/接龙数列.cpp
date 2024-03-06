#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_N 100005

int main()
{
    int n;
    int a[MAX_N], dp[10];
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &a[i]);
    }
    
    for (int i = 1; i <= n; i++)
    {s
        int tail = a[i] % 10;
        int head;
        int t = a[i];
        while (t)
        {
            head = t % 10;
            t = t / 10;
        }
        dp[tail] = (dp[tail] > dp[head] + 1) ? dp[tail] : dp[head] + 1;
    }
    
    int len = 0;
    for (int i = 0; i < 10; i++)
    {
        len = (len > dp[i]) ? len : dp[i];
    }
    
    printf("%d\n", n - len);
    return 0;
}

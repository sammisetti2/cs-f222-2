#include <stdio.h>

#define N 5005
int g[N][N], vis[N], n, ap;

void dfs(int i)
{
    if(i == ap)
        return;
    vis[i] = 1;
    int j;
    for(j = 0; j < n; j++)
        if(g[i][j] && !vis[j])
            dfs(j);
}

int main()
{
    int m, p, q, i, flag = 1;
    scanf("%d %d", &n, &m);
    for(i = 0; i < m; i++)
    {
        scanf("%d %d", &p, &q);
        g[p][q] = g[q][p] = 1;
    }
    if(n < 3)
        return 0 * printf("-1\n");
    for(ap = 0; ap < n; ap++)
    {
        for(i = 0; i < n; i++)
            vis[i] = 0;
        dfs(ap == 0);
        for(i = 0; i < n; i++)
            if(!vis[i] && i != ap)
            {
                printf("%d ", ap);
                flag = 0;
                break;
            }
    }
    printf(flag ? "-1\n" : "\n");
    return 0;
}
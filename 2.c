#include <stdio.h>
#include <limits.h>

#define N 8
int n, ans = INT_MAX, g[N][N], path[N], ans_path[N];

void swap(int* x, int* y)
{
    int tmp = *x;
    *x = *y;
    *y = tmp;
}

int cost(int* path)
{
    int i, out = 0;
    for(i = 0; i < n; i++)
    {
        int a = path[i], b = path[i+1];
        if(g[a][b] == -1)
            return INT_MAX;
        out += g[a][b];
    }
    return out;
}

void permute(int* path, int i)
{
    int j, sz = n-1;
    if(i == sz-1)
    {
        int cur = cost(path-1);
        if(cur < ans)
        {
            ans = cur;
            for(j = 0; j < sz; j++)
                ans_path[j+1] = path[j];
        }
    }
    else
    {
        for(j = i; j < n; j++)
        {
            swap(path+i, path+j);
            permute(path, i+1);
            swap(path+i, path+j);
        }
    }
}

int main()
{
    int m, a, b, c, i, j;
    for(i = 0; i < N; i++)
    {
        path[i] = i;
        for(j = 0; j < N; j++)
            g[i][j] = -1;
    }
    scanf("%d %d", &n, &m);
    path[n] = 0;
    for(i = 0; i < m; i++)
    {
        scanf("%d %d %d", &a, &b, &c);
        g[a][b] = g[b][a] = c;
    }
    permute(path+1, 0);
    for(i = 0; i < n; i++)
        printf("%c => ", ans_path[i]+'A');
    printf("A\nCost: %d\n", ans);
    return 0;
}
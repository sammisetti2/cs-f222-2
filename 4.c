#include <stdio.h>

#define N 8
int n, ans, idx[N], g1[N][N], g2[N][N];

void swap(int* x, int* y)
{
    int tmp = *x;
    *x = *y;
    *y = tmp;
}

int check(int* idx)
{
    int i, j;
    for(i = 0; i < n; i++)
        for(j = 0; j < n; j++)
            if(g1[i][j] != g2[idx[i]][idx[j]])
                return 0;
    return 1;
}

void permute(int* idx, int i)
{
    int j;
    if(i == n-1 && check(idx))
        ans = 1;
    else
    {
        for(j = i; j < n; j++)
        {
            swap(idx+i, idx+j);
            permute(idx, i+1);
            swap(idx+i, idx+j);
        }
    }
}

int main()
{
    int m, i, p, q;
    for(i = 0; i < N; i++)
        idx[i] = i;
    scanf("%d %d", &n, &m);
    for(i = 0; i < m; i++)
    {
        scanf("%d %d", &p, &q);
        g1[p][q] = 1;
    }
    scanf("%d %d", &p, &q);
    if(p != n || q != m)
        return 0 * printf("No\n");
    for(i = 0; i < m; i++)
    {
        scanf("%d %d", &p, &q);
        g2[p][q] = 1;
    }
    permute(idx, 0);
    printf("%s\n", (ans ? "Yes" : "No"));
}
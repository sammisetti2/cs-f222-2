#include <stdio.h>

#define N 3005
int set[N], idx[N], edge[N*N-N], cost[N];

void swap(int* x, int* y)
{
    int tmp = *x;
    *x = *y;
    *y = tmp;
}

void quick_sort(int* A, int n, int* idx)
{
    if(n < 2)
        return;

    int p = A[n-1], i = 0, k;
    for(k = 0; k < n; k++)
    {
        if(A[k] <= p)
        {
            swap(idx+k, idx+i);
            swap(A+k, A+i++);
        }
    }
    quick_sort(A, i-1, idx);
    quick_sort(A+i, n-i, idx+i);
}

int main()
{
    int n, m, i, j, ans = 0;
    for(i = 0; i < N; i++)
        idx[i] = set[i] = i;
    scanf("%d %d", &n, &m);
    for(i = 0; i < m; i++)
        scanf("%d %d %d", edge+i+i, edge+i+i+1, cost+i);
    quick_sort(cost, m, idx);

    for(i = 0; i < m; i++)
    {
        int a = edge[2*idx[i]], b = edge[2*idx[i]+1];
        if(set[a] == set[b])
            continue;
        int tmp = set[b];
        for(j = 0; j < n; j++)
            if(set[j] == tmp)
                set[j] = set[a];
        ans += cost[i];
    }
    printf("%d\n", ans);
    return 0;
}
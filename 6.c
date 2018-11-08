#include <stdio.h>
#define long long long

int reach(long x, long y, long steps)
{
    steps++;
    if(x > y)
        return 0;
    if(x == y)
        return steps;
    if(y % 2)
        return ((y-1) % 10 ? 0 : reach(x, (y-1)/10, steps));
    else
        return reach(x, y/2, steps);
}

int main()
{
    long t, x, y, z;
    scanf("%lld", &t);
    while(t--)
    {
        scanf("%lld %lld %lld", &x, &y, &z);
        printf("%s\n", (reach(x, y, 0) <= z+1  ? "Yes" : "No"));
    }
    return 0;
}
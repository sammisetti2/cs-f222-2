#include <stdio.h>
#define long long long

int reach(long x, long y, long steps)
{
    if(x > y)
        return 0;
    if(x == y)
        return steps+1;
     return reach(2*x, y, steps+1) | reach(10*x+1, y, steps+1);
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
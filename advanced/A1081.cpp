#include<cstdio>
#include<algorithm>
#include<math.h>

using namespace std;

long long gys(long long a,long long b)
{
    a = abs(a);
    b = abs(b);
    if(b==0)
    {
        return a;
    }
    else
    {
        return gys(b, a % b);
    }
};

struct fen
{
    long long son = 0;
    long long mother = 0;
} num;

fen add(fen a,fen b)
{
    fen result;
    long long up, down;
    up = a.son * b.mother + b.son * a.mother;
    down = a.mother * b.mother;
    if(up==0)
    {
        down = 1;
        result.son = up;
        result.mother = down;
        return result;
    }
    long long k = gys(up,down);
    up = up / k;
    down = down / k;
    result.son = up;
    result.mother = down;
    return result;
};

int main(void)
{
    int n;
    scanf("%d", &n);

    fen total;
    total.son = 0;
    total.mother = 1;

    for (int i = 0; i < n;++i)
    {
        scanf("%lld/%lld", &num.son, &num.mother);
        total = add(total, num);
        //printf("%lld/%lld", total.son, total.mother);
    }

    if(total.son==0)
    {
        printf("0\n");
        return 0;
    }

    long long leader = 0;
    if(total.son>=total.mother)
    {
        leader = total.son / total.mother;
        total.son = total.son % total.mother;
    }

    if(leader!=0)
    {
        printf("%lld", leader);
    }
    if(total.son!=0)
    {
        if(leader!=0)
        {
            printf(" ");
        }
        printf("%lld/%lld\n", total.son, total.mother);
    }
    else
    {
        //printf("0\n");
        return 0;
    }
    return 0;
}
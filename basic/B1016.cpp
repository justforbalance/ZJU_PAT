#include<cstdio>
#include<algorithm>

using namespace std;

long long Get_DA_part(long long a,long long da)
{
    long long pa = 0;
    while(a!=0)
    {
        if(a%10==da)
        {
            pa = da+10*pa;
        }
        a = a/10;
    }
    return pa;
}

int main(void)
{
    long long a,b,da,db;
    scanf("%lld%lld%lld%lld",&a,&da,&b,&db);
    long long result;
    result = Get_DA_part(a,da)+Get_DA_part(b,db);
    printf("%lld\n",result);
    return 0;
}
                                       
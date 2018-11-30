#include<cstdio>
#include<algorithm>

using namespace std;

int main(void)
{
    long long a,b,c;
    int T;
    scanf("%d",&T);
    for(int i=1;i<T+1;++i)
    {
        scanf("%lld%lld%lld",&a,&b,&c);
        if(a+b>c)
        {
            printf("Case #%d: true\n",i);
        }
        else
        {
            printf("Case #%d: false\n",i);
        }
    }
    return 0;
}
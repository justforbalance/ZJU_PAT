#include<cstdio>
#include<algorithm>

using namespace std;

int main(void)
{
    long long N;
    long long b;
    int count=0;
    long long tem[1000] = {0};
    scanf("%lld %lld",&N,&b);
    bool flag=true;
    for(int i=0;N!=0;++i)
    {
        tem[i]=N%b;
        ++count;
        N=N/b;
    }

    
    for(int i=0;i<count/2;++i)
    {
        if(tem[i]!=tem[count-1-i])
        {
            flag=false;
        }
    }
    if(flag)
    {
        printf("Yes\n");
        if(count==1)
        {
            printf("%lld",tem[count-1]);
        }
        else
        {
            printf("%lld",tem[count-1]);
            for(int i=count-2;i>=0;--i)
            {
                printf(" %lld",tem[i]);
            }
        }
    }
    else
    {
        printf("No\n");
        if(count==1)
        {
            printf("%lld",tem[count-1]);
        }
        else
        {
            printf("%lld",tem[count-1]);
            for(int i=count-2;i>=0;--i)
            {
                printf(" %lld",tem[i]);
            }
        }
        
    }
    return 0;

}
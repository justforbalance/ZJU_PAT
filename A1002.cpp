#include<cstdio>
using namespace std;

int main(void)
{
    int K;
    int n;
    double coff[1112];
    double a;
    int count=0;
    for(int i=0;i<1112;++i)
    {
        coff[i]=0;
    }

    scanf("%d", &K);
    for(int i=1;i<=K;++i)
    {
        scanf("%d %lf",&n,&a);
        //scanf("%lf",&temp_coff);
        coff[n]+=a;
    }

    scanf("%d", &K);
    for(int i=1;i<=K;++i)
    {
        scanf("%d %lf",&n,&a);
        //scanf("%lf",&temp_coff);
        coff[n]+=a;
    }

    for(int i=0;i<1112;++i)
    {
        if(coff[i]!=0)
            {count++;}
    }
    printf("%d",count);
    for(int i=1111;i>=0;--i)
    {
        if(coff[i]!=0)
        {
            printf(" %d %.1f",i,coff[i]);
        }
    }
    return 0;
}
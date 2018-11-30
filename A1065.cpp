#include<cstdio>
#include<algorithm>

using namespace std;

int main(void)
{
    long long A,B,C;
    int T;
    long long res;
    scanf("%d",&T);
    bool flag;
    for(int i=0;i<T;++i)
    {
        scanf("%lld%lld%lld",&A,&B,&C);
        res = A+B;
        if(A>0&&B>0&&res<0)
        {
            flag=true;
        }
        else if(A<0&&B<0&&res>=0)
        {
            flag=false;
        }
        else if(res>C)
        {
            flag=true;
        }
        else 
        {
            flag=false;
        }
        if(flag)
        {
            printf("Case #%d: true\n",i+1);
        }
        else
        {
            printf("Case #%d: false\n",i+1);
        }
    }
    return 0;

}
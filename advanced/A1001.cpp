#include<cstdio>
#include<algorithm>

using namespace std;

//在for循环中，第一次也会执行判断语句，如果第一次判定不通过，循环不进行
int main(void)
{
    int a,b,sum;
    scanf("%d%d",&a,&b);
    sum = a+b;
    if(sum<0)
    {
        printf("-");
        sum=-sum;
    }
    int len=0;
    int digit[12] ={0};
    for(int i=0;sum!=0;++i)
    {
        digit[i]=sum%10;
        sum=sum/10;
        len++;
    }

    if(a+b==0)
    {
        len=1;
        digit[0]=0;
    }

    //printf("%d\n",len);
    for(int i=len-1;i>=0;--i)
    {
        printf("%d",digit[i]);
        if(i%3==0&&i!=0)
        {
            printf(",");
        }
    }
    return 0;
}
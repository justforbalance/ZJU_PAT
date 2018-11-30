#include<cstdio>
#include<algorithm>
using namespace std;

int main(void)
{
    int a[10];
    for(int i = 0;i<10;++i)
    {
        scanf("%d",&a[i]);
    }
    for(int j=1;j<10;++j)
    {
        if(a[j]!=0)
        {
            printf("%d",j);
            --a[j];
            break;
        }
    }

    for(int i=0;i<10;++i)
    {
        for(int j=0;j<a[i];++j)
        {
            printf("%d",i);
        }
    }
    return 0;
}




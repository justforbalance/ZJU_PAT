#include<cstdio>
#include<algorithm>

using namespace std;

int hashtable[100010]={0};
int num[100010]={0};

int main(void)
{
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;++i)
    {
        scanf("%d",&num[i]);
        ++hashtable[num[i]];
    }

    int k=0;
    for(int i=0;i<n;++i)
    {
        if(hashtable[num[i]]==1)
        {
            ++k;
            printf("%d",num[i]);
            break;
        }
    }

    if(k==0)
    {
        printf("None");
    }

    return 0;
}
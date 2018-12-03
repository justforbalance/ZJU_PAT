#include<cstdio>
#include<algorithm>

using namespace std;

int main(void)
{
    int n,m;
    //int value[10010];
    int temp;
    int hashtable[10010]={0};

    scanf("%d %d",&n,&m);

    for(int i=0;i<n;++i)
    {
        scanf("%d",&temp);
        ++hashtable[temp];
    }

    for(int i=0;i<=m;++i)
    {
        if(hashtable[i]>0&&hashtable[m-i]>0)
        {
            if(i==m-i&&hashtable[i]>1)
            {
                printf("%d %d",i,m-i);
                return 0;  
            }
            if(i!=m-i)
            {
                printf("%d %d",i,m-i);
                return 0;
            }    
        }
    }
    printf("No Solution");

    return 0;


}
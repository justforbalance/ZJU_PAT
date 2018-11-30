#include<cstdio>
using namespace std;

int main(void)
{
    int K;
    int order[55];
    int start[55];
    int temp[55];

    scanf("%d", &K);
    for(int i=1;i<55;++i)
    {
        scanf("%d", order+i);
    }

    char hs[6]={'S','H','C','D','J'};
    
    for(int i=1;i<55;++i)
    {
        start[i]=i;
        temp[i]=i;
    }

    for(int i=0;i<K;++i)
    {
        for(int j=1;j<55;++j)
        {
            start[order[j]]=temp[j];
        }
        for(int k=1;k<55;++k)
        {
            temp[k]=start[k];
        }
    }

    for(int i=1;i<55;++i)
    {
        if(i!=1)
        {
            printf(" ");
        }
        printf("%c%d",hs[ (start[i]-1) /13],(start[i]-1)%13+1);
    }
    return 0;
}


#include<cstdio>

using namespace std;

int hashtable[101]={0};
int main(void)
{
    int  n,k;
    scanf("%d",&n);
    int input_score;
    for(int i=0;i<n;++i)
    {
        scanf("%d",&input_score);
        hashtable[input_score]++;
    }

    scanf("%d",&k);
    for(int i=0;i<k;++i)
    {
        scanf("%d",&input_score);
        printf("%d",hashtable[input_score]);
        if(i<k-1)
        {
            printf(" ");
        }
    }

    return 0;
}
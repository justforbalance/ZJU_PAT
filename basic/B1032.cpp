#include<cstdio>
using namespace std;

int main(void)
{
    int N;
    int score[100002] = {0};
    scanf("%d",&N);
    int sco,schid;
    int k=1;
    for(int i=1;i<=N;++i)
    {
        scanf("%d%d",&schid,&sco);
        score[schid]+=sco;
        if(score[schid]>score[k])
        {
            k=schid;
        }
    }

    printf("%d %d\n",k,score[k]);
    return 0;

}
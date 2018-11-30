#include<cstdio>
#include<algorithm>
using namespace std;

const int MAXN = 100005;
int main(void)
{
    int N;
    int dis[MAXN];
    int M;
    int p1,p2;
    scanf("%d",&N);
    int sum=0;
    int dis_1[MAXN];
    dis_1[1]=0;
    for(int i=1;i<=N;++i)
    {
        scanf("%d",&dis[i]);
        dis_1[i+1]=dis_1[i]+dis[i];
    }

    scanf("%d",&M);

    int total_dist=dis_1[N+1];

    int dist_1=0;
    int dist_2=0;
    for(int i=1;i<=M;++i)
    {
        scanf("%d%d",&p1,&p2);
        if(p1>p2)
        {
            swap(p1,p2);
        }
        dist_1 = dis_1[p2]-dis_1[p1];
        dist_2 = total_dist-dist_1;
        printf("%d\n",min(dist_1,dist_2));
    }

    return 0;
}
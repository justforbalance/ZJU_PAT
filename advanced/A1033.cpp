#include<cstdio>
#include<algorithm>
#include<math.h>

using namespace std;

struct Node
{
    double price;
    double distance;
}stations[510];//表示油价以及距离杭州的距离

bool cmp(Node a,Node b)
{
    return a.distance<b.distance;
};

int main(void)
{
    double c,Dmax,Dave;
    int n;//c表示油箱总容量，Dmax代表总距离，Dave代表每单位油支持的距离，n代表加油站数量
    
    scanf("%lf%lf%lf%d",&c,&Dmax,&Dave,&n);
    for(int i=0;i<n;++i)
    {
        scanf("%lf%lf",&stations[i].price,&stations[i].distance);
    }
    sort(stations,stations+n,cmp);
    stations[n].price=0;
    stations[n].distance=Dmax;

    double total_price=0.00;
    double adding[510]={0};//表示每一个加油站的加油数量；
    double left_gas=0;//表示当前剩余油的数量
    double passed_dis=0;//表示已经跑的距离
    double next_dist=0;//表示距离下一站的距离
    double max_gas_dis = c*Dave;

    int next_st=0;
    int pass_node = 0;
    
    // 整体策略为，首先确认在加满油的时候可以到达哪些站点，如果不能达到下一个站点，直接结束
    //             其次，如果可以到达下一站，则在下面可以到达的站点选择 第一个油价比自己便宜的，加油到刚好可以跑到那个站点
    //             否则没有任意一个站点比自己油价便宜，那就加满油，然后跑到这几站点中最便宜的站点
    //             注意更新剩余油量left_gas以及passed_dis;
    if(stations[0].distance!=0)
    {
        printf("The maximum travel distance = %.2f",passed_dis);
        return 0;
    }
    for(int i=0;i<n;i=next_st)
    {
        pass_node=0;
        passed_dis=stations[i].distance;

        for(int j=i;j<n+1&&(stations[j].distance-stations[i].distance)<=max_gas_dis;++j)
        {
            pass_node=j-i;
        }

        if(pass_node==0)
        {
            printf("The maximum travel distance = %.2f",passed_dis+max_gas_dis);
            return 0;
        }

        next_st=i+1;
        adding[i]=c-left_gas;
        for(int k=1;k<=pass_node;++k)
        {
            next_dist=stations[i+k].distance-stations[i].distance;
            if(stations[i+k].price<stations[i].price)
            {
                next_st=i+k;
                adding[i]=next_dist/Dave-left_gas;
                break;
            }

            if(stations[i+k].price<stations[next_st].price)
            {
                next_st=i+k;
                adding[i]=c-left_gas;
            }  
        }
        left_gas+=adding[i];
        left_gas-=(stations[next_st].distance-stations[i].distance)/Dave;

    }

    for(int i=0;i<n;++i)
    {
        total_price=total_price+adding[i]*stations[i].price;
    }

    printf("%.2f\n",total_price);
    return 0;
}
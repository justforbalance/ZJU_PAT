#include<iostream>
#include<cstdio>
#include<algorithm>
#include<map>
#include<string>
#include<cstring>
using namespace std;
struct plate_max
{
	char plate[15];
}car_plate[10010];
struct record
{
	char plate[10];
	int ntime;
	char staues[5];
}allrec[10010], valid_rec[10010];

bool cmp1(record a, record b)//sort by plate firstly and time secondly
{
	int s = strcmp(a.plate, b.plate);
	if (s == 0)
	{
		return a.ntime<b.ntime;
	}
	else
	{
		return s<0;
	}   
};

bool cmp2(record a, record b)
{
	return a.ntime<b.ntime;
};
map<string, int> car_time;//string 表示车牌号，int 表示停车最大时间；
int main(void)
{
	int n, k;
	scanf("%d%d", &n, &k);
	int hh,mm,ss=0;
	for (int i = 0; i<n; ++i)
	{
		scanf("%s %d:%d:%d %s", allrec[i].plate, &hh, &mm, &ss, allrec[i].staues);
		allrec[i].ntime=3600*hh+60*mm+ss;
	}

	sort(allrec, allrec + n, cmp1);//将输入的n个记录按照时间排序
	int valid_num = 0;//有效记录数量
	int max_time = 0;//最长停车时间
	int max_num = 1;//最长停车时间车子的数量
	for (int i = 0; i<n - 1; ++i)
	{
		if ((!strcmp(allrec[i].staues, "in")) && (!strcmp(allrec[i + 1].staues, "out"))&&(!strcmp(allrec[i].plate, allrec[i + 1].plate)))
		{
			valid_rec[valid_num].ntime = allrec[i].ntime;
			strcpy(valid_rec[valid_num].plate, allrec[i].plate);
			strcpy(valid_rec[valid_num].staues, allrec[i].staues);
			valid_rec[valid_num + 1].ntime = allrec[i + 1].ntime;
			strcpy(valid_rec[valid_num + 1].plate, allrec[i + 1].plate);
			strcpy(valid_rec[valid_num + 1].staues, allrec[i + 1].staues);
			int temp_park_time = allrec[i + 1].ntime-allrec[i].ntime;
            if (car_time.count(allrec[i].plate) == 0)
			{
				car_time[allrec[i].plate] = temp_park_time;
			}
            else
			{
				car_time[allrec[i].plate]+=temp_park_time;
			}//更新car_time；
            temp_park_time = car_time[allrec[i].plate];
			if (max_time <= temp_park_time)
			{
                if(max_time==temp_park_time)
                {
                    ++max_num;
                    strcpy(car_plate[max_num].plate,allrec[i].plate);
                }
                else 
                if (max_time<temp_park_time)
                {
                    max_time = temp_park_time;
                    max_num = 1;
                    strcpy(car_plate[max_num].plate,allrec[i].plate);
                }	
			}
			valid_num += 2;
			++i;
		}
    }
    sort(valid_rec,valid_rec+valid_num,cmp2);
    int query_time;
	int last_query_rec=0;
	int j;
	int now_num=0;
    for(int i=0;i<k;++i)
    {
        scanf("%d:%d:%d",&hh,&mm,&ss);
		query_time=3600*hh+60*mm+ss;
        for(j=last_query_rec;query_time>=valid_rec[j].ntime&&j<valid_num;++j)
        {
            int s=strcmp(valid_rec[j].staues,"in");
            if(s==0)
            {
                ++now_num;
            }

            s=strcmp(valid_rec[j].staues,"out");
            if(s==0)
            {
            	--now_num;
            }
        }
        printf("%d\n",now_num);
		last_query_rec=j;
    }//由于输入的查询时间是有序的，因此可以利用上一时刻的查询结果，大大提高查询效率；
    for(int i=1;i<max_num+1;++i)
    {
        printf("%s ",car_plate[i].plate);
    }
	hh=max_time/3600;
	max_time=max_time%3600;
	mm=max_time/60;
	max_time=max_time%60;
	ss=max_time;
    printf("%02d:%02d:%02d\n",hh,mm,ss);
    return 0;
}
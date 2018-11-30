#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

bool is_early(int a[],int b[])
{
    bool flag=false;
    for( int k=1;k<4;++k)
    {
        if(a[k]<b[k])
        {
            flag=true;
        }
    }
    return flag;
};

int main(void)
{
    int M;
    char input_id[16];
    char earliest_id[16];
    char latest_id[16];

    int start_time[4];
    int end_time[4];
    int earliest_time[4];
    int latest_time[4];

    scanf("%d",&M);

    scanf("%s %d:%d:%d%d:%d:%d",input_id,&start_time[1],&start_time[2],&start_time[3],&end_time[1],&end_time[2],&end_time[3]);
    //earliest_id=input_id;
    //latest_id=input_id;
    strcpy(earliest_id,input_id);
    strcpy(latest_id,input_id);
    for(int i=1;i<4;++i)
    {
        earliest_time[i]=start_time[i];
        latest_time[i]=end_time[i];
    }

    for(int i=1;i<M;++i)
    {
        scanf("%s %d:%d:%d%d:%d:%d",input_id,&start_time[1],&start_time[2],&start_time[3],&end_time[1],&end_time[2],&end_time[3]);

        if(is_early(start_time,earliest_time))
        {
            strcpy(earliest_id,input_id);
            for(int j=1;j<4;++j)
            {
                earliest_time[j]=start_time[j];
            }
        }

        if(is_early(latest_time,end_time))
        {
            strcpy(latest_id,input_id);
            for(int j=1;j<4;++j)
            {
                latest_time[j]=end_time[j];
            }
        }

    }

    printf("%s %s\n",earliest_id,latest_id);

    return 0;
}
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>


using namespace std;

struct Student
{
    int ID;
    int grade[4];
}stu[2010];

int com_item;

int Rank[1000000][4]={0};

bool cmp(Student one,Student two)
{
    return one.grade[com_item]>two.grade[com_item];
};

int main(void)
{
    
    //Student stu[2010];
    int n,m;
    char show[4]={'A','C','M','E'};
    scanf("%d%d",&n,&m);
    
    for(int i=1;i<n+1;++i)
    {
        scanf("%d%d%d%d",&stu[i].ID,&stu[i].grade[1],&stu[i].grade[2],&stu[i].grade[3]);
        stu[i].grade[0]=round((stu[i].grade[3]+stu[i].grade[1]+stu[i].grade[2]))+0.5;

    }//学生数组stu从1开始，成绩排名数组Rank也是从1开始


    for(com_item=0;com_item<4;++com_item)//com_item从0开始
    {
        sort(stu+1,stu+1+n,cmp);
        Rank[stu[1].ID][com_item]=1;
        for(int i=2;i<n+1;++i)
        {   
            if(stu[i].grade[com_item]==stu[i-1].grade[com_item])
            {
                Rank[stu[i].ID][com_item]=Rank[stu[i-1].ID][com_item];
            }
            else
            {
                Rank[stu[i].ID][com_item]=i;
            } 
        }
    }

    int query;
    for(int j=1;j<m+1;++j)
    {
        //temp=0;
        scanf("%d",&query);
        if(Rank[query][1]==0)
        {
            printf("N/A\n");
        }
        else
        {
            int temp=0;
            for(int i=0;i<4;++i)
            {
                //int temp;
                if(Rank[query][i]<Rank[query][temp])
                {
                    //int temp;
                    temp = i;
                }
            }
            printf("%d %c\n",Rank[query][temp],show[temp]); 
        }         
    }

    return 0;
}
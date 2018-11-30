#include<cstdio>
#include<algorithm>
#include<cstring>

using namespace std;

struct Student
{
    int id;
    char name[10];
    int grade;
}stu[100002];

bool cmp_1( Student a,Student b)
{
    return a.id<b.id;
}

bool cmp_2(Student a,Student b)
{
    int s=strcmp(a.name,b.name);
    if(s==0)
    {
        return a.id<b.id;
    }
    else
    {
        return (s<0);
    }
}

bool cmp_3(Student a,Student b)
{
    if(a.grade==b.grade)
    {
        return cmp_1(a,b);
    }
    else
    {
        return a.grade<b.grade;
    }
}

int main(void)
{
    int n,c;
    scanf("%d%d",&n,&c);
    for(int i=0;i<n;++i)
    {
        scanf("%d %s %d",&stu[i].id,&stu[i].name,&stu[i].grade);
    }

    switch(c)
    {
        case(1):
            sort(stu,stu+n,cmp_1);
            break;
        case(2):
            sort(stu,stu+n,cmp_2);
            break;
        case(3):
            sort(stu,stu+n,cmp_3);
            break;
    }
    for(int i=0;i<n;++i)
    {
        printf("%06d %s %d\n",stu[i].id,stu[i].name,stu[i].grade);
    }
    return 0;
}
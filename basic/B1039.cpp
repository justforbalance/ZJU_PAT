#include<cstdio>
#include<algorithm>
#include<cstring>
#include<string>

using namespace std;

int main(void)
{
    int hashtable[150]={0};
    char given_str[1005];
    char desired_str[1005];
    scanf("%s",given_str);
    scanf("%s",desired_str);
    int num1,num2;
    num1=strlen(given_str);
    num2=strlen(desired_str);
    int ynum=0;
    int total_num = num2;

    for(int i=0;i<num2;++i)
    {
        ++hashtable[int(desired_str[i])];
    }

    for(int j=0;j<num1;++j)
    {
        if(hashtable[int(given_str[j])]>0)
        {
            --hashtable[int(given_str[j])];
            --total_num;
        }
        else
        if(hashtable[int(given_str[j])]==0)
        {
            ++ynum;
        }
    }

    if(total_num<=0)
    {
        printf("Yes %d",ynum);
    }
    else
    {
        printf("No %d",total_num);
    }

    return 0;
    
}
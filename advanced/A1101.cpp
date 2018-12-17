#include<cstdio>
#include<algorithm>

using namespace std;

const int INF=0x3fffffff;

int main(void)
{
   int n;
   int a[100010];
   scanf("%d",&n);

   for(int i=0;i<n;++i)
   {
       scanf("%d",a+i);
   }

   int left_max[100010];
   left_max[0]=0;
   int right_min[100010];
   right_min[n-1]=INF;

   for(int i=1;i<n;++i)
   {
       if(a[i-1]>left_max[i-1])
       {
           left_max[i]=a[i-1];
       }
       
       else
       {
           left_max[i]=left_max[i-1];
       }   
   }

   for(int i=n-2;i>=0;--i)
   {
       if(a[i+1]<right_min[i+1])
       {
           right_min[i]=a[i+1];
       }
       else
       {
           right_min[i]=right_min[i+1];
       }
   }

    int count=0;
    int main_num[100010];
   for(int i=0;i<n;++i )
   {
       if(a[i]>left_max[i]&&a[i]<right_min[i])
       {
           main_num[count]=a[i];
           ++count;
       }
   }

   printf("%d\n",count);
    for(int i=0;i<count;++i)
    {
       printf("%d",main_num[i]);
       if(i<count-1)
       {
           printf(" ");
       }
    }

   printf("\n");

    return 0;
}
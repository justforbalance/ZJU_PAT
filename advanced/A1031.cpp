#include<cstdio>
#include<algorithm>
#include<cstring>

using namespace std;

int main(void)
{
    int n1,n2,n3;
    int N;
    char str[100];
    scanf("%s",str);
    //getc(str);
    N = strlen(str);
    n1 = (N+2)/3;
    n3=n1;
    n2=N+2-n1-n3;
    for(int i=0;i<n1-1;++i)
    {
        printf("%c",str[i]);
        for(int j=0;j<n2-2;++j)
        {
            printf(" ");
        }
        printf("%c\n",str[N-1-i]);
    }
    for(int i=0;i<n2;++i)
    {
        printf("%c",str[n1+i-1]);
    }
    return 0;

}
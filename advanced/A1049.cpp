#include<cstdio>
#include<algorithm>

using namespace std;

int main(void)
{
    int n;
    scanf("%d", &n);
    //n = 12;
    int total = 0;
    int expp = 1;
    int tmp = n;
    for (int i = 0; tmp != 0;++i)
    {
        if(tmp%10>1)
        {
            total += (tmp / 10 + 1) * expp;
        }
        else if(tmp % 10==1)
        {
            total += (tmp / 10) * expp;
            total += n % expp+1;
        }
        else
        {
            total += (tmp / 10) * expp;
        }
        tmp = tmp / 10;
        expp = expp * 10;
    }

    printf("%d", total);
    return 0;
}
#include<cstdio>
#include<algorithm>

using namespace std;

int inttomax(int a)
{
    int b[4];
    for (int i = 0; i < 4;++i)
    {
        b[i] = a % 10;
        a = a / 10;
    }
    sort(b, b + 4);
    return b[3] * 1000 + b[2] * 100 + b[1] * 10 + b[0];
};

int inttomin(int a)
{
    int b[4];
    for (int i = 0; i < 4;++i)
    {
        b[i] = a % 10;
        a = a / 10;
    }
    sort(b, b + 4);
    return b[0] * 1000 + b[1] * 100 + b[2] * 10 + b[3];
};

int main(void)
{
    int a;
    scanf("%d", &a);
    int maxnum = 0, minnum = 0, subnum = a;
    for (int i = 0; ;++i)
    {
        maxnum = inttomax(subnum);
        minnum = inttomin(subnum);
        subnum = maxnum - minnum;
        printf("%04d - %04d = %04d\n", maxnum, minnum, subnum);
        if(subnum==0||subnum==6174)
        {
            break;
        }
    }

    return 0;
}
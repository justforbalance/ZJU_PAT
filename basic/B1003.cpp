#include<cstdio>
#include<algorithm>
#include<cstring>
#include<iostream>

using namespace std;

int main(void)
{
    int T;
    scanf("%d", &T);
    while(T--)
    {
        char str[100];
        scanf("%s", str);
        int len = strlen(str);

        int nump = 0;
        int numt = 0;
        int other = 0;
        int locp = -1;
        int loct = -1;
        int bat;
        for (int i = 0; i < len;++i)
        {
            if(str[i]=='P')
            {
                nump++;
                locp = i;
            }
            else if(str[i]=='T')
            {
                ++numt;
                loct = i;
            }
            else if(str[i]!='A')
            {
                ++other;
            }
        }
        if ((nump != 1) || (numt != 1) || (other != 0) || (loct - locp<=1))
        {
            printf("NO\n");
            continue;
        }

        int x = locp, y = loct - locp - 1, z = len - loct - 1;
        if(z-x*(y-1)==x)
        {
            printf("YES\n");
        }
        else
        {
            printf("NO\n");
        }
    }

    return 0;
}
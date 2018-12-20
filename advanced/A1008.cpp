#include<cstdio>
#include<algorithm>

using namespace std;

int main(void)
{
    int now = 0, to = 0;
    int total=0;
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n;++i)
    {
        scanf("%d", &to);
        if(to>now)
        {
            total += (to - now) * 6 + 5;
        }
        else if (to<now)
        {
            total += (now - to) * 4 + 5;
        }
        else if(to==now)
        {
            total += 5;
        }
        now = to;
    }
    printf("%d", total);
    return 0;
}
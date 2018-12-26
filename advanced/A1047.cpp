#include<cstdio>
#include<algorithm>
#include <cstring>
#include<string>
#include <math.h>
#include <vector>

using namespace std;

const int maxn = 40010;
const int maxc = 2510;

char name[maxn][5];
vector<int> course[maxc];

bool cmp(int a,int b)
{
    return strcmp(name[a],name[b])<0;
};

int main(void)
{
    int n, k;
    int c, courseid;
    scanf("&d&d", &n, &k);
    for (int i = 0; i < n;++i)
    {
        scanf("%s%d", name[i], &c);
        for (int j = 0; j < c;++j)
        {
            scanf("%d", &courseid);
            course[courseid].push_back(i);
        }
    }

    for (int i = 1; i <= k;++i)
    {
        printf("%d %d\n", i, course[i].size());
        sort(course[i].begin(), course[i].end(), cmp);//变换之后，变的是course的内部排序，不变的是name,如果直接对name进行排序，会产生错乱，导致对不上号  
        for (int j = 0; j<course[i].size();++j)
        {
            printf("%s\n", name[course[i][j]]);
        }
    }
    return 0;
}
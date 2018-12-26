#include<cstdio>
#include<algorithm>
#include <cstring>
#include<string>
#include <math.h>
#include <vector>
const int N = 40010;
const int M = 26 * 26 * 26 * 10 + 1;
vector<int> selsectCourse[M];

using namespace std;

int get_id(char name[])
{
    int id = 0;
    for (int i = 0; i < 3;++i)
    {
        id = id * 26 + int(name[i] - 'A');
    }

    id = id * 10 + int(name[3] - '0');
    return id;
};

int main(void)
{
    char name[5];
    int n, k;
    scanf("%d%d", &n, &k);
    for (int i = 0; i < k;++i)
    {
        int course, x;
        scanf("%d%d", &course, &x);
        for (int j = 0; j < x;++j)
        {
            scanf("%s", name);
            int id = get_id(name);
            selsectCourse[id].push_back(course);
        }
    }

    for (int i = 0; i < n;++i)
    {
        scanf("%s", name);
        int id = get_id(name);
        sort(selsectCourse[id].begin(), selsectCourse[id].end());//默认从小到大排序
        printf("%s %d", name, selsectCourse[id].size());
        for (int j = 0; j < selsectCourse[id].size();++j)
        {
            printf(" %d", selsectCourse[id][j]);
        }
        printf("\n");
    }
    return 0;
}
#include<cstdio>
#include<iostream>
#include <vector>
#include <algorithm>

using namespace std;
//169 5 2
vector<int> mi;

int n, p, k;
int maxdisum = -1;
vector<int> di_mi, ans, temp;

int power_p(int x){
    int res=1;
    for (int i = 1; i <= p;++i)
    {
        res = res * x;
    }
    return res;
};

void init(){
    //int tmp;
    for (int i = 0; power_p(i) <= n;++i)
    {
        di_mi.push_back(power_p(i));
    }
};

void DFS(int index, int nowk, int now_sum, int nowdisum){
    if(now_sum==n&&nowk==k)
    {
        if(nowdisum>maxdisum)
        {
            ans = temp;
            maxdisum = nowdisum;
        }
        return;
    }

    if(now_sum>n||nowk>k)
    {
        return;
    }

    if(index>=1)
    {
        temp.push_back(index);
        DFS(index, nowk + 1, now_sum + di_mi[index], nowdisum + index);
        temp.pop_back();
        DFS(index - 1, nowk, now_sum, nowdisum);
    }

};

int main(void)
{
    scanf("%d%d%d", &n, &k, &p);
    init();
    int len = di_mi.size();
    DFS(len-1, 0, 0, 0);
    if(maxdisum==-1)
    {
        printf("Impossible\n");
    }
    else
    {
        printf("%d = %d^%d", n, ans[0], p);
        for (int i = 1; i < ans.size();++i)
        {
            printf(" + %d^%d", ans[i], p);
        }
    }
    return 0;
}
#include<cstdio>
#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>

// 20 9 24
// 10 2 4 3 5 10 2 18 9 7 2 2 1 3 12 1 8 6 2 2
// 00 4 01 02 03 04
// 02 1 05
// 04 2 06 07
// 03 3 11 12 13
// 06 1 09
// 07 2 08 10
// 16 1 15
// 13 3 14 16 17
// 17 2 18 19
//output
// 10 5 2 7
// 10 4 10
// 10 3 3 6 2
// 10 3 3 6 2

using namespace std;

int n, m, s;
vector<int> res[101];
int resnum=0;
int weight[101];

bool cmp(int a,int b)
{
    return a >= b;
}

struct node
{
    //int data;
    int weight;
    vector<int> child;
} Node[101];

void DFS(int root,int sum,vector<int> tmpweight)
{
    sum = sum + Node[root].weight;
    tmpweight.push(Node[root].weight);
    if(Node[root].child.size==0)
    {
        if(sum==s)
        {
            res[resnum] = tmpweight;
            ++resnum;
        }
    }
    else{
        sort(Node[root].child, Node[root].child + Node[root].child.size(), cmp);
        for(int i = 0; i < Node[root].child.size();++i)
        {
            DFS(Node[root].child[i], sum, tmpweigth);
        }
    }
}

int main(void)
{
    scanf("%d%d%d", &n, &m, &s);
    for (int i = 0; i < n; ++i)
    {
        scanf("%d", weight + i);
    }

    for (int i = 0; i < m;++i)
    {
        int tmpnode;
        int sonnum;
        scanf("%d %d",&tmpnode, &sonnum);
        for (int j = 0; j < sonnum;++j)
        {
            int child;
            scanf("%d", &child);
            Node[i].child.push(child);
        }
    }

    vector<int> tmpweight;
    DFS(0,0,tmpweight);

}
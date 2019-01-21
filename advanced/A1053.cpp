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

bool cmp(vector<int> a,vector<int> b)
{
    int size;
    if(a.size()<b.size)
    {
        size = a.size();
    }
    
    else
    {
        size = b.size();
    }

    int i;
    for (i = 0; i < size;++i)
    {
        if(a[i]>b[i])
        {
            return true;
            //break;
        }
        else
        {
            if(a[i]<b[i])
            {
                return false;
                //break;
            }
        }
    }
    if(i==size-1)
    {
        if(a.size()>b.size())
        {
            return true;
        }
        else
        {
            return false;
        }
    }
}

struct node
{
    int data;
    int weight;
    vector<int> child;
} Node[101];


int main(void)
{
    
}
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
    for (int i = 0; power_p(i) < n;++i)
    {
        di_mi.push_back(power_p(i));
    }
};

void DFS(int index, int nowk, int now_sum, int nowdisum){

};

int main(void)
{
    scanf("%d%d%d", &n, &k, &p);

    
}
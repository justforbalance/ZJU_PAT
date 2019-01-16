#include<cstdio>
#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

vector<int> core;
vector<int> flag;//判断是否已经循环过
int m, n, l, t;//m*n,l个矩阵，临界值为t

int core_num = 0;

int address(int a, int b, int c)
{
	if (a >= 0 && a < l&&b >= 0 && b < m&&c >= 0 && c < n)
	{
		return a * m*n + b * n + c;
	}
	if (c == n)
	{
		return -1;
	}
	if (b == m)
	{
		return -1;
	}
	if (a == l)
	{
		return -1;
	}
}

int BFS(int i, int j, int k, int tmp_core_num)
{
	
}

int main(void)
{
	scanf("%d%d%d%d", &m, &n, &l, &t);
	for (int i = 0; i < l; ++i)
	{
		int tmp;
		for (int j = 0; j < m; ++j)
		{
			for (int k = 0; k < n; ++k)
			{
				scanf("%d", &tmp);
				core.push_back(tmp);
				flag.push_back(1);
			}
		}
	}//core[i*m*n+j*n+k]=core[i][j][k];

	BFS(0, 0, 0, 0);

	printf("%d\n", core_num);
	return 0;
}
#include<cstdio>
#include<iostream>
#include<vector>
#include<algorithm>
#include<queuq>

using namespace std;

vector<int> core;
vector<int> flag;//判断是否已经循环过
int m, n, l, t;//m*n,l个矩阵，临界值为t

int address(int a, int b, int c)
{
	if (a >= 0 && a < l&&b >= 0 && b < m&&c >= 0 && c < n)
	{
		return a * m*n + b * n + c;
	}
	else
	{
		return -1;
	}
}

int BFS(int i, int j, int k)
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
	int core_num = 0;
	for (int i = 0; i < l; ++i)
	{
		for (int j = 0; j < m; ++j)
		{
			for (int k = 0; k < n; ++k)
			{
				int pos = address(i, j, k);
				if (pos >= 0)
				{
					if (core[pos] == 1 && flag[pos] == 1)
					{
						int temp = BFS(i, j, k);
						if (temp >= t)
						{
							core_num += temp;
						}
					}
				}
			}
		}
	}

	printf("%d\n", core_num);
	return 0;
}
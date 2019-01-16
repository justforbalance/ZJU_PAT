#include<cstdio>
#include<iostream>
#include<vector>
#include<algorithm>

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
	int this_num = 0;
	if (address(i, j, k) == -1)
	{
		return 0;
	}
    flag[address(i, j, k)] = 0;
	else
	{
		if (core[address(i, j, k)] == 1)
		{
			++this_num;
			int pos = address(i,j,k-1);
			if (pos >= 0)
			{
				if (flag[pos] == 1)
				{
					this_num += BFS(i, j, k - 1);
				}
			}
			 pos = address(i, j, k + 1);
			if (pos >= 0)
			{
				if (flag[pos] == 1)
				{
					this_num += BFS(i, j, k + 1);
				}
			}
			 pos = address(i, j-1, k);
			if (pos >= 0)
			{
				if (flag[pos] == 1)
				{
					this_num += BFS(i, j-1, k);
				}
			}
			 pos = address(i, j+1, k);
			if (address(i, j + 1, k) >= 0)
			{
				if (flag[pos] == 1)
				{
					this_num += BFS(i, j +1, k);
				}
			}
			 pos = address(i-1, j, k);
			if (pos >= 0)
			{
				if (flag[pos] == 1)
				{
					this_num += BFS(i-1, j, k - 1);
				}
			}
			 pos = address(i+1, j, k);
			if (address(i + 1, j, k) >= 0)
			{
				if (flag[pos] == 1)
				{
					this_num += BFS(i + 1, j, k - 1);
				}
			}
		}
		else
		{
			return 0;
		}
	}
	return this_num;
	
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
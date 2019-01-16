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
	int pos = address(i, j, k);
	if (pos != -1)//范围可BFS
	{
		if (flag[pos] == 1)//还没有搜索过
		{
			flag[pos] = 0;
			if (core[pos] == 1)//此位为1，则搜索它的邻居
			{
                int tmp;
				tmp=BFS(i, j, k + 1, tmp_core_num + 1);
				tmp=BFS(i, j + 1, k, tmp_core_num + tmp);
				tmp=BFS(i + 1, j, k, tmp_core_num + tmp);
                if(tmp_core_num==0&&tmp>=t)
                {
                    core_num+=tmp;
                }
			}

			if (core[pos] == 0)//此位为0，搜索下一个位置，不过tmp_core_num变为0；
			{
				if (k + 1 == n)
				{
					k = 0;
					++j;
					if (j == m)
					{
						j = 0;
						++i;
						if (i == l)
						{
							return 0;
						}
					}
					BFS(i, j, k,0);
				}
				else
				{
					BFS(i, j, k + 1, 0);
				}
                return tmp_core_num;
			}
		}
		else//已经搜索过
		{
			return tmp_core_num;
		}
	}
	else//不在BFS范围内
	{
		return tmp_core_num;
	}

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
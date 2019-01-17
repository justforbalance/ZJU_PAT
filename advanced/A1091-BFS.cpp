#include<cstdio>
#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>

using namespace std;

vector<int> core;
vector<int> flag;//判断是否已经循环过
int m, n, l, t;//m*n,l个矩阵，临界值为t


struct Node
{
	int x;
	int y;
	int z;
}node;

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

int BFS(Node tmpnode)
{
	int i=tmpnode.x;
	int j=tmpnode.y;
	int k=tmpnode.z;

	queue<Node> tmp_que;

	int pos=address(i,j,k);
	flag[pos]=0;
	if(core[pos]==0)
	{
		return 0;
	}
	int num=0;

	tmp_que.push(tmpnode);
	while(tmp_que.size()!=0)
	{
		Node node2=tmp_que.front();
		tmp_que.pop();
		i=node2.x;
		j=node2.y;
		k=node2.z;

		int pos=address(i,j,k);
		flag[pos]=0;
		if(core[pos]==1)
		{
			++num;
			//邻居入队
			pos=address(i,j,k-1);
			if(pos>=0)
			{
				if(flag[pos]==1)
				{
					Node node1;

					node1.x=i;
					node1.y=j;
					node1.z=k-1;
					tmp_que.push(node1);
				}
			}

			pos=address(i,j,k+1);
			if(pos>=0)
			{
				if(flag[pos]==1)
				{
					Node node1;
					
					node1.x=i;
					node1.y=j;
					node1.z=k+1;
					tmp_que.push(node1);
				}
			}

			pos=address(i,j-1,k);
			if(pos>=0)
			{
				if(flag[pos]==1)
				{
					Node node1;
					
					node1.x=i;
					node1.y=j-1;
					node1.z=k;
					tmp_que.push(node1);
				}
			}

			pos=address(i,j+1,k);
			if(pos>=0)
			{
				if(flag[pos]==1)
				{
					Node node1;
					
					node1.x=i;
					node1.y=j+1;
					node1.z=k;
					tmp_que.push(node1);
				}
			}

			pos=address(i-1,j,k);
			if(pos>=0)
			{
				if(flag[pos]==1)
				{
					Node node1;
					
					node1.x=i-1;
					node1.y=j;
					node1.z=k;
					tmp_que.push(node1);
				}
			}

			pos=address(i+1,j,k);
			if(pos>=0)
			{
				if(flag[pos]==1)
				{
					Node node1;
					
					node1.x=i+1;
					node1.y=j;
					node1.z=k;
					tmp_que.push(node1);
				}
			}
		}

	}
	return num;
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
					if (flag[pos] == 1)//为1且位置未被搜索
					{
						Node node1;
						node1.x=i;
						node1.y=j;
						node1.z=k;
						int temp = BFS(node1);
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
#include<cstdio>
#include<iostream>
#include<queue>

using namespace std;

int initial_order[1010];//cunzhu paixu
int final_order[1010];
queue<int> tmprank;

int main(void)
{
	int np, ng;
	scanf("%d%d", &np, &ng);
	for (int i = 0; i < np; ++i)
	{
		scanf("%d", initial_order + i);
	}


	int order;
	for (int i = 0; i < np; ++i)
	{
		scanf("%d", &order);
		tmprank.push(order);
	}

	int groupnum;
	while (tmprank.size() != 1)
	{
		int this_circle = tmprank.size();
		int next_circle = 0;

		if (tmprank.size() % ng == 0)
		{
			groupnum = tmprank.size() / ng;
		}
		else {
			groupnum = (tmprank.size() / ng) + 1;
		}

		next_circle = groupnum;

		for (int i = 0; i < groupnum; ++i)//分组处理
		{
			int k = tmprank.front();
			//tmprank.pop();
			for (int j = 0; j < ng && i * ng + j < this_circle; ++j)
			{
				if (initial_order[tmprank.front()] > initial_order[k])
				{
					k = tmprank.front();
				}
				final_order[tmprank.front()] = next_circle + 1;
				tmprank.pop();
			}
			tmprank.push(k);
		}
	}
	final_order[tmprank.front()] = 1;
	for (int i = 0; i < np; ++i)
	{
		printf("%d", final_order[i]);
		if (i != np - 1)
		{
			printf(" ");
		}
	}
	return 0;
}
#include<cstdio>
#include<iostream>
#include <algorithm>

using namespace std;

struct Node
{
	int data;
	int pos;
	int last_pos;
	int next_pos;
	int order;
} node[100010];

bool cmp(Node a, Node b)
{
	return a.order < b.order;
}

int main(void)
{
	int start_pos;
	int n, l;
	scanf("%d%d%d", &start_pos, &n, &l);
	int tmp_pos, tmp_data, tmp_next_pos;
	for (int i = 0; i < 100010; ++i)
	{
		node[i].order = 100009;
	}

	for (int i = 0; i < n; ++i) //input data
	{
		scanf("%d%d%d", &tmp_pos, &tmp_data, &tmp_next_pos);
		node[tmp_pos].data = tmp_data;
		node[tmp_pos].next_pos = tmp_next_pos;
		node[tmp_pos].pos = tmp_pos;
		node[tmp_pos].order = 111111;
		if (tmp_next_pos != -1)
		{
			node[tmp_next_pos].last_pos = tmp_pos;
		}
	}

	int count = 0;
	tmp_pos = start_pos;
	while (tmp_pos != -1 && node[tmp_pos].order == 111111)
	{
		node[tmp_pos].order = count + 1;
		++count;
		tmp_pos = node[tmp_pos].next_pos;
	}
	sort(node, node + 100010, cmp);

	int circle = count / l;
	bool flag;
	if (count%l == 0)
	{
		flag = true;
	}
	else {
		flag = false;
	}

	int tmp = count;
	for (int i = 0; i < circle; ++i)
	{
		if (i == circle - 1)
		{
			node[i * l].next_pos = node[i * l + l].pos;
		}
		else
		{
			node[i * l].next_pos = node[i * l + 2*l-1].pos;
		}
		
		//node[i * l].last_pos = node[i * l + l].pos;

		
		for (int j = i * l + l - 1; j >= i * l; --j)
		{
			if (j != i * l)
			{
				printf("%05d %d %05d\n", node[j].pos, node[j].data, node[j].last_pos);
			}
			else
			{
				if (tmp == 1)
				{
					printf("%05d %d -1\n", node[j].pos, node[j].data);
				}
				else if (node[j].next_pos != -1)
				{
					printf("%05d %d %05d\n", node[j].pos, node[j].data, node[j].next_pos);
				}
				else
				{
					printf("%05d %d -1\n", node[j].pos, node[j].data);
				}
			}
			--tmp;
		}		
	}

	int j = tmp;
	while (j > 0)
	{
		if (j != 1)
		{
			printf("%05d %d %05d\n", node[count - j].pos, node[count - j].data, node[count - j].next_pos);
		}
		else
		{
			printf("%05d %d -1\n", node[count - j].pos, node[count - j].data);
		}
		--j;
	}
	return 0;
}

/* test case:
case 1:
00100 6 4
00000 4 99999
00100 1 12309
68237 6 -1
33218 3 00000
99999 5 68237
12309 2 33218
case 2:
00100 6 3
00000 4 99999
00100 1 12309
68237 6 -1
33218 3 00000
99999 5 68237
12309 2 33218
case 3:
00100 6 2
00000 4 99999
00100 1 12309
68237 6 -1
33218 3 00000
99999 5 68237
12309 2 33218 */
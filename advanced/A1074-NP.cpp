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

bool cmp(Node a,Node b)
{
	return a.order < b.order;
}

int main(void)
{
	int start_pos;
	int n, l;
	scanf("%d%d%d", &start_pos, &n, &l);
	int tmp_pos, tmp_data, tmp_next_pos;
	for (int i = 0; i < 100010;++i)
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

	int count=0;
	tmp_pos = start_pos;
	while(tmp_pos!=-1&&node[tmp_pos].order==111111)
	{
		node[tmp_pos].order = count + 1;
		++count;
		tmp_pos = node[tmp_pos].next_pos;
	}
	sort(node, node + 100010, cmp);

	int circle = count / l;
	bool flag;
	if(count%l==0)
	{
		flag = true;
	}
	else{
		flag = false;
	}

	int tmp = count;
	for (int i = 0; i < circle;++i)
	{
		node[i * l].next_pos = node[i * l + l].pos;
		for (int j = i * l + l - 1; j >= i * l;--j)
		{
			if(j!=i*l)
			{
				printf("%05d %d %05d\n", node[j].pos, node[j].data, node[j].last_pos);
			}
			else
			{
				if(node[j].next_pos!=-1)
				{
					printf("%05d %d -1\n", node[j].pos, node[j].data);
				}
				else
				{
					printf("%05d %d %05d\n", node[j].pos, node[j].data, node[j].next_pos);
				}
			}
			--tmp;
		}
	}

	int j = tmp;
	while(j!=0)
	{
		printf("%05d %d %05d\n", node[count-1-j].pos, node[count-1-j].data, node[count-1-j].next_pos);
		--j;
	}
	printf("%05d %d -1\n", node[count-1-j].pos, node[count-1-j].data);

	return 0;

}
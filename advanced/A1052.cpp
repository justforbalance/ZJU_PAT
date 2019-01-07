#include<cstdio>
#include<iostream>
#include <algorithm>

using namespace std;
struct Node
{
	int add;
	int key;
	int next;
	int flag;
} node[100010];

bool cmp(Node a, Node b)
{
	if (a.flag < 0 && b.flag < 0)
	{
		return a.key < b.key;
	}
	else
		return a.flag < b.flag;
}

int main(void)
{
	int n, start;
	scanf("%d%d", &n, &start);
	int add, key, next;
	for (int i = 0; i < 100010; ++i)
	{
		node[i].flag = 10;
	}
	for (int i = 0; i < n; ++i)
	{
		scanf("%d %d %d", &add, &key, &next);
		node[add].add = add;
		node[add].key = key;
		node[add].next = next;
		node[add].flag = 0;
	}
	int tmp = start;
	int count = 0;
	while (tmp != -1&&node[tmp].flag==0)
	{
		node[tmp].flag = -1;
		++count;
		tmp = node[tmp].next;
	}
	if (count == 0)
	{
		printf("0 -1\n");
		return 0;
	}
	sort(node, node + 100010, cmp);
	printf("%d %05d\n", count, node[0].add);
	for (int i = 0; i < count; ++i)
	{
		if (i < count - 1)
		{
			printf("%05d %d %05d\n", node[i].add, node[i].key, node[i + 1].add);
		}
		else
		{
			printf("%05d %d -1\n", node[i].add, node[i].key);
		}
	}
	return 0;
}
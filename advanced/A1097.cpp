#include<cstdio>
#include<iostream>
#include<map>

//如果没有有效链表就不输出
//如果没有移除链表的话，那么移除的部分也不输出

using namespace std;

struct Node
{
	int data;
	int add=100000;
	int next=100000;
} node[100010];

int abs1(int a)
{
	if (a < 0)
	{
		return -a;
	}
	else {
		return a;
	}
};

int hashtable[100010] = { 0 };

int main(void)
{
	int start_pos, n;
	scanf("%d%d", &start_pos, &n);
	int add, data, next;
	for (int i = 0; i < n; ++i)
	{
		scanf("%d%d%d", &add, &data, &next);
		node[add].add = add;
		node[add].data = data;
		node[add].next = next;
	}

	int tmp_pos = start_pos;
	int cutnum = 0;
	int count = 0;
	int cut_start;
	int cut_tmp_pos;
	int last_tmp = start_pos;
	while (tmp_pos != -1 && node[tmp_pos].add == tmp_pos)//判断是否是链表结尾以及判断是否输入该节点
	{
		int k = abs1(node[tmp_pos].data);
		if (hashtable[k] == 0)//证明此时k还未出现过
		{
			++hashtable[k];
			last_tmp = tmp_pos;
			tmp_pos = node[tmp_pos].next;
			++count;
		}
		else {
			if (cutnum == 0)
			{
				cut_start = tmp_pos;
				cut_tmp_pos = cut_start;
				++cutnum;
			}
			else {
				node[cut_tmp_pos].next = tmp_pos;
				cut_tmp_pos = tmp_pos;
				++cutnum;
			}
			tmp_pos = node[tmp_pos].next;
			node[last_tmp].next = tmp_pos;
		}
	}
	if (cutnum != 0)
	{
		node[cut_tmp_pos].next = -1;
	}
	if (count != 0)
	{
		tmp_pos = start_pos;
		while (tmp_pos != -1)
		{
			if (node[tmp_pos].next != -1)
			{
				printf("%05d %d %05d\n", node[tmp_pos].add, node[tmp_pos].data, node[tmp_pos].next);
			}
			else {
				printf("%05d %d %d\n", node[tmp_pos].add, node[tmp_pos].data, node[tmp_pos].next);
			}
			tmp_pos = node[tmp_pos].next;
		}
	}

	if (cutnum != 0)
	{
		tmp_pos = cut_start;
		while (tmp_pos != -1)
		{
			if (node[tmp_pos].next != -1)
			{
				printf("%05d %d %05d\n", node[tmp_pos].add, node[tmp_pos].data, node[tmp_pos].next);
			}
			else {
				printf("%05d %d %d\n", node[tmp_pos].add, node[tmp_pos].data, node[tmp_pos].next);
			}
			tmp_pos = node[tmp_pos].next;
		}
	}

	return 0;
}

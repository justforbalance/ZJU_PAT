#include<cstdio>
#include<iostream>

using namespace std;

struct node
{
	char data;
	int pos;
	int next;
	bool flag;
} Node[100010];

int main(void)
{
	int s1, s2, n;
	scanf("%d%d%d", &s1, &s2, &n);
	int address,next;
	char data;
	for (int i = 0; i < n; ++i)
	{
		scanf("%d %c %d", &address,&data,&next);//%c是可以读取空格的
		//scanf("%c%d", &Node[address].data, &Node[address].next);
		Node[address].pos = address;
		Node[address].data = data;
		Node[address].next = next;
	}
	while (s1 != -1)
	{
		Node[s1].flag = true;
		s1 = Node[s1].next;
	}
	//bool flag;
	while (s2 != -1)
	{
		if (Node[s2].flag==true)
		{
			printf("%05d\n", s2);
			return 0;
		}
		else {
			s2 = Node[s2].next;
		}
	}
	printf("-1\n");
	return 0;
}
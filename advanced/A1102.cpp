#include<cstdio>
#include<iostream>
#include<queue>

// 8
// 1 -
// - -
// 0 -
// 2 7
// - -
// - -
// 5 -
// 4 6
//scanf("%c")会接受换行符
using namespace std;

const int maxn = 11;

struct node
{
	int data = -1;
	int lchild = -1;
	int rchild = -1;
} Node[maxn];

int n;
int flag[maxn] = { -1 };

void invertnode(int root)
{
	if (root < 0)
	{
		return;
	}
	if (Node[root].lchild == -1 && Node[root].rchild == -1)
	{
		return;
	}
	else
	{
		int tmp;
		tmp = Node[root].lchild;
		Node[root].lchild = Node[root].rchild;
		Node[root].rchild = tmp;
	}
	invertnode(Node[root].lchild);
	invertnode(Node[root].rchild);
}

int printnum = 0;

void levelorder(int root)
{
	if (root < 0)
	{
		return;
	}
	queue<int> q;
	q.push(root);
	while (!q.empty())
	{
		int k = q.front();
		q.pop();
		printf("%d", k);
		++printnum;
		if (Node[k].lchild >= 0)
		{
			q.push(Node[k].lchild);
		}
		if (Node[k].rchild >= 0)
		{
			q.push(Node[k].rchild);
		}
		if (printnum < n)
		{
			printf(" ");
		}
	}
}

void inorder(int root)
{
	if (root < 0)
	{
		return;
	}
	inorder(Node[root].lchild);
	printf("%d", root);
    ++printnum;
	if (printnum < n)
	{
		printf(" ");
	}
	inorder(Node[root].rchild);
	
}

int main(void)
{
	scanf("%d", &n);
    for (int i = 0; i < n;++i)
    {
        flag[i] = -1;
    }

        for (int i = 0; i < n; ++i)
        {
            Node[i].data = i;
            char c1, c2;
            scanf("%*c%c %c", &c1, &c2);
            if (c1 != '-')
            {
                int t = c1 - '0';
                Node[i].lchild = t;
                flag[t] = 1;
            }
            if (c2 != '-')
            {
                int t = c2 - '0';
                Node[i].rchild = t;
                flag[t] = 1;
            }
        }
	int root;
	for (int i = 0; i < n; ++i)
	{
		if (flag[i] < 0)
		{
			root = i;
			break;
		}
	}
	invertnode(root);
	levelorder(root);
	printf("\n");
	printnum = 0;
	inorder(root);
	printf("\n");
	return 0;
}


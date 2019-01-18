#include<cstdio>
#include<iostream>
#include<string>
#include<cstring>
#include<stack>
#include<vector>

using namespace std;

// 6
// Push 1
// Push 2
// Push 3
// Pop
// Pop
// Push 4
// Pop
// Pop
// Push 5
// Push 6
// Pop
// Pop

const int maxn = 35;
int n;
int printnum = 0;

struct node
{
	int data;
	node* lchild;
	node* rchild;
};

vector<int> pre;
vector<int> in;
stack<int> q;

void postorder(node* root)
{
	if (root == NULL)
	{
		return;
	}
	postorder(root->lchild);
	postorder(root->rchild);
	printf("%d", root->data);
	++printnum;
	if (printnum != n)
	{
		printf(" ");
	}
}

node* create(int preL, int preR, int inL, int inR)
{
	if (preL > preR)
	{
		return NULL;
	}
	node* root = new node;
	root->data = pre[preL];
	int k;
	for (k = inL; k <= inR; ++k)
	{
		if (in[k] == pre[preL])
		{
			break;
		}
	}
	int leftnum = k - inL;
	root->lchild = create(preL + 1, preL + leftnum, inL, k - 1);
	root->rchild = create(preL + leftnum + 1, preR, k + 1, inR);
	return root;
}

int main(void)
{
	scanf("%d", &n);
	char s[7];
	for (int i = 0; i < 2 * n; ++i)
	{
		scanf("%s", s);
		if (s[2] == 's')//push
		{
			int d;
			scanf("%d", &d);
			pre.push_back(d);
			q.push(d);
		}
		else //pop
		{
			int k = q.top();
			q.pop();
			in.push_back(k);
		}
	}
	node* root = create(0, n - 1, 0, n - 1);
	postorder(root);

	return 0;
}
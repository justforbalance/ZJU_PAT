#include<iostream>
#include <queue>

using namespace std;

// 7
// 2 3 1 5 7 6 4 post
// 1 2 3 4 5 6 7 in

struct node
{
	int data;
	node* lchild;
	node* rchild;
};

int post[31];
int in[31];
int n;
//vector<int> level;

node* create(int postL, int postR, int inL, int inR)
{
	if (postL > postR)
	{
		return NULL;
	}

	//node* root=new node;
	node* root = new node;
	root->data = post[postR];
	int k;
	for (k = inL; k <= inR; ++k)
	{
		if (in[k] == post[postR])
		{
			break;
		}
	}
	int leftnum = k - inL;
	root->lchild = create(postL, postL + leftnum-1, inL, k - 1);
	root->rchild = create(postL + leftnum, postR - 1, k + 1, inR);
	return root;
}
void levelorder(node* root)
{
	queue<node*> q;
	q.push(root);
	while (!q.empty())
	{
		node* now = q.front();
		q.pop();
		//level.push_back(now->data);
		printf("%d", now->data);
		if (now->lchild != NULL)
		{
			q.push(now->lchild);
		}
		if (now->rchild != NULL)
		{
			q.push(now->rchild);
		}
		if (!q.empty())
		{
			printf(" ");
		}
	}
	printf("\n");
}
int main(void)
{
	scanf("%d", &n);
	for (int i = 0; i < n; ++i)
	{
		scanf("%d", post + i);
	}
	for (int i = 0; i < n; ++i)
	{
		scanf("%d", in + i);
	}
	node* root = create(0, n - 1, 0, n - 1);
	levelorder(root);
	return 0;
}
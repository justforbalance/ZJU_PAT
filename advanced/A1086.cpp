#include<cstdio>
#include<iostream>
#include<string>
#include<cstring>
#include<stack>

using namespace std;

const int maxn = 35;
int n;

struct node
{
    int data;
    node* lchild;
    node* rchild;
}

int printnum = 0;
void postorder(node* root)
{
    if(root==NULL)
    {
        return;
    }
    postorder(root->lchild);
    postorder(root->rchild);
    printf("%d", root->data);
    ++printnum;
    if(printnum!=n)
    {
        printf(" ");
    }
}

int main(void)
{
    scanf("%d", &n);
    node* root = new node;
    node* now = root;
    for (int i = 0; i < 2 * n;++i)
    {
        string s;
        getline(cin, s);
        if(s[2]=='s')//push
        {
            now->data = s[5] - '0';
            now = now->lchild;
        }
        if(s[2]=='p')//pop
        {
            
        }
    }

    return 0;
}
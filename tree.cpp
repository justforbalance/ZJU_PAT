树的知识

1 基本知识
    root
    node
    child
    leaf
    edge
    subtree
    empty tree
    layer
    degree
    depth/height

2 二叉树
    left child
    right child
    查找
    插入
    创建
    完全二叉树采用数组存储
    二叉树指针实现
    struct node
    {
        int data;
        node* lchild;
        node* rchild;
    };

3 二叉树的遍历

    先序遍历
    void perorder(node* root)
    {
        if(root==NULL)
        {
            return;
        }
        printf("%d\n",root->data);
        preorder(root->lchild);
        preorder(root->rchild);
    }
    中序遍历
    void inorder(node* root)
    {
        if(root==NULL)
        {
            return;
        }
        inorder(root->lchild);
        printf("%d\n",root->data);
        inorder(root->rchild);
    }
    后序遍历
    void postorder(node* root)
    {
        if(root==NULL)
        {
            return;
        }
        postorder(root->lchild);
        postorder(root->rchild);
        printf("%d\n",root->data);
    }
    层序遍历//本质上是BFS
    void LayerOrder(node* root)
    {
        queue<node*> q;
        q.push(root);
        while(!q.empty())
        {
            node* now=q.front;
            q.pop();
            printf("%d\n",now->data);
            if(now->lchild!=NULL)
                q.push(now->lchild);
            if(now->rchild!=NULL)
                q.push(now->rchild);
        }
    }

    //先序遍历以及中序遍历确定一棵树
    node* create(int preL,int preR,int inL,int inR)
    {
        if(preL>preR)
        {
            return NULL;
        }
        node* root=new node;
        root->data=pre[preL];
        int k;
        for(k=inL;k<=inR;++k)
        {
            if(in[k]==pre[preL])
            {
                break;
            }
        }
        root->lchild=create(preL+1,preL+k-inL,inL,k-1);
        root->rchild=create(preL+k-inL+1,preR,k+1,inR);
        return root;
    }

    //中序遍历以及后序遍历确定一棵树
    node* create(int postL,int postR,int inL,int inR)
    {
        if(postL>postR)
        {
            return NULL;
        }
        node* root=new node;
        root->data=post[postR];
        int k;
        for(k=inL;k<=inR;++k)
        {
            if(in[k]==post[postR])
            {
                break;
            }
        }
        int leftnum=k-inL;
        root->lchild=create(postL,postL+leftnum-1,inL,k-1);
        root->rchild=create(postL+leftnum,postR-1,k+1,inR);
        return root;
    }

    //中序遍历以及层序遍历确定一棵树
    node* create(int layerL,int layerR,int inL,int inR)
    {
        node* root=new node;
    }

    二叉树的静态写法
    struct node{
        int data;
        int lchild;
        int rchild;
    } Node[100];

4 树的遍历//推荐使用的是树的静态写法
    struct node
    {
        int data;
        int child[maxn];
    } Node[maxn];
    或者
    struct node
    {
        int data;
        vector<int> child;
    } //之后的代码都是在此基础上写的
    假如不涉及数据域，可以写成
        vector<int> child[maxn];
    其中child[0]存放0号节点的子vector//本质上式图的邻接表写法

    先序排序
    void preorder(int root)
    {
        printf("%d\n", Node[root].data);
        for (int i = 0; i < Node[root].child.size();++i)
        {
            preorder(Node[root].child[i]);
        }
    }
    后序排序类似;
    层序排序
    void Layerorder(int root)
    {
        queue<int> q;
        q.push(root);
        while(!q.empty())
        {
            int front = q.front();
            q.pop();
            printf("%d", Node[front].data);
            for (int i = 0; i < Node[front].child.size();++i)
            {
                q.push(Node[front].child[i]);
            }
        }
    }

    如果涉及到层号，根节点的层号为0或者1，以0为例
    struct node
    {
        int layer;
        int data;
        vector<int> child;
    } Node[maxn];

    void Layerorder(int root);
    {
        queue<int> q;
        Node[root].layer = 0;
        q.push(root);
        while(!q.empty())
        {
            int front = q.front;
            printf("%d\n", Node[front].data);
            for (int i = 0; i < Node[front].child.size();++i)
            {
                int child = Node[front].child[i];
                Node[child].layer = Node[front].layer + 1;
                q.push(child);
            }
        }
    }
5 树的搜索
    DFS
    BFS
    
6 BST 二叉搜索树(左侧的小于等于根节点，右侧的大于根节点)
    void search(node* root,int x)
    {
        if(root==nuLL)
        {
            printf("search failed");
            return;
        };
        if(x==root->data)
        {
            printf("%d\n", root->data);
            else if(x<root->data)
            {
                search(root->lchild, x);
            }
            else
            {
                search(root->rchild, x);
            }    
        }
    }

    void insert(node* &root,int x)/root 会发生变化
    {
        if(root==NULL)
        {
            root = newnode(x);
            return;
        }
        if(x==root->data)
        {
            return;
        }
        else if(x<root->data)
        {
            insert(root->lchild, x);
        }
        else
        {
            insert(root->rchild, x);
        }   
    }

    node* Create(int d[],int n)
    {
        node* root = NULL;
        for (int i = 0; i < n;++i)
        {
            insert(root,data[i]);
        }
        return root;
    }

    二叉树的删除 前驱 以及 后继
    node* findmax(node* root)
    {
        while(root->rchild!=NULL)
        {
            root = root->rchild;
        }
        return root;
    }

    node* findMin(node* root)
    {
        while(root->lchild!=NULL)
        {
            root = root->lchild;
        }
        return root;
    }

    void deleteNode(Node* &root,int x)//root 会发生变化
    {
        if(root==NULL)
            return;
        if(root->data==x)
        {
            if(root->rchild==NULL&&root-<lchild==NULL)
            {
                root == NULL;
            }
            else if(root->lchild!=NULL)
            {
                node* pre = findMax(root->lchild);
                root->data = pre->data;
                deleteNode(root->lchild, pre->data);
            }
            else
            {
                node* next = findMin(root->rchild);
                root->data = next->data;
                deleteNode(root->rchild, next->data);
            }  
        }
        else if(x<root->data)
        {
            deleteNode(root->lchild, x);
        }
        else
        {
            deleteNode(root->rchild, x);
        }
        
    }
    二叉查找树的中序遍历是有序的，本质上是二叉树

7 AVL 平衡二叉树





    


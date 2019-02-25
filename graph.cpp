1.图的概念 
    图，有向图，无向图，度，入度，出度，权值，点权，边权

2.图的存储 
    vector<int> adj[n];
    如果存在点权，边权
    struct Node
    {
        int v;
        int w;
    } vector<Node> adj[n];
    或者
    struct Node
    {
        int v, w;
        Node(int _v,int_w) : v(_v),w(_w) {}
    };
    adj[1].push_back(Node(3, 4));//1的邻居有3，边权为4

    3.图的遍历 
    vector<int> Adj[maxv];
    int n;
    bool vis[maxv] = {false};
    DFS版本
        void DFS(int u,int depth)
        {
            vis[u] = true;
            for (int i = 0; i < Adj[u].size();++i)
            {
                int v = Adj[u][i];
                if(vis[u]==false)
                {
                    DFS(v, depth + 1);
                }
            }
        }

        void DFSTrave()
        {
            for (int u = 0; u < n;++u)
            {
                if(vis[u]==false)
                {
                    DFS(u, 1);
                }
            }
        }
    BFS版本
        vector<int> Adj[maxv];
        int n;
        bool inq[maxv] = {false};

        void BFS(int u)
        {
            queue<int> q;
            q.push(u);
            inq[u] = true;
            while(!q.empty())
            {
                int u = q.front();
                q.pop();
                for (int i = 0; i < Adj[u].size();++i)
                {
                    int v = Adj[u][i];
                    if(inq[v]==false)
                    {
                        q.push(v);
                        inq[v] = true;
                    }
                }
            }
        }

        void BFSTrave()
        {
            for (int u = 0; u < n;++u)
                {
                    if(inq[u]==false)
                    {
                        BFS(u);
                    }
                }
        }

4.最短路径
    Dijkstra算法
    struct Node
    {
        int v, dis;
    };
    vector<Node> Adj[N];
    int n;
    int d[maxv];
    bool vis[maxv] = {false};

    void Dijkstra(int s)
    {
        fill(d, d + maxv, INF);
        d[s] = 0;
        for (int i = 0; i < n;++i)
        {
            int u = -1, Min = INF;
            fof(int j = 0; j < n;++j)
            {
                if(vis[j]=false&&d[j]<Min)
                {
                    u = j;
                    Min = dis[j];
                }
            }
            if(u==-1)
            {
                return;
            }
            vis[u] = true;
            for (int j = 0; j < Adj[u].size();++j)
            {
                int v = Adj[u][j].v;
                if(vis[v]==false&&d[u]+Adj[u][j].dis<d[v])
                {
                    d[v]=d[u]+Adj[u][j].dis
                }
            }
        }
    }

    增加pre数组的dijkstra算法
    struct Node
    {
        int v, dis;
    };
    vector<Node> Adj[N];
    int n;
    int d[maxv];
    int pre[maxv];
    bool vis[maxv] = {false};

    void Dijkstra(int s)
    {
        fill(d, d + maxv, INF);
        for (int i = 0; i < n;++i)
        {
            pre[i] = i;
        }
        d[s] = 0;
        for (int i = 0; i < n;++i)
        {
            int u = -1, Min = INF;
            fof(int j = 0; j < n;++j)
            {
                if(vis[j]=false&&d[j]<Min)
                {
                    u = j;
                    Min = d[j];
                }
            }
            if(u==-1)
            {
                return;
            }
            vis[u] = true;
            for (int j = 0; j < Adj[u].size();++j)
            {
                int v = Adj[u][j].v;
                if(vis[v]==false&&d[u]+Adj[u][j].dis<d[v])
                {
                    d[v] = d[u] + Adj[u][j].dis;
                    pre[v] = u;
                }
                如果上述条件相等，则判断第二尺度
            }
        }
    }

    有时会出现除了最短路径之外的第二尺度，此时需要另外增加数组进行优化判断;
    此外还有一种方法是首先使用dijkstra计算所有最优路径，在遍历这些路径进行第二尺度比较
        代码如下：
            vector<int> pre[maxv];
            void dijkstra(int s)
            {
                fill(d, d + maxv, Inf);
                d[s] = 0;
                for (int i = 0; i < n;++i)
                {
                    int u = -1;
                    int Min = Inf;
                    for (int j = 0; j < n;++j)
                    {
                        if(vis[j]==false&&d[j]<Min)
                        {
                            u = j;
                            min = d[j];
                        }
                    }
                    if(u==-1)
                    {
                        return;
                    }
                    vis[u] = true;
                    for (int j = 0; j < Adj[u].size();++j)
                    {
                        int v = Adj[u][j].v;
                        if (vis[v] == false && d[u] + Adj[u][j].dis < d[v])
                        {
                            d[v] = d[u] + Adj[u][j].dis;
                            pre[v].clear();
                            pre[v].push_back(u);
                        }
                        else if(d[u]+Adj[u][j].dis==d[v])
                        {
                            pre[v].push_back(u);
                        }
                    }
                }
            }//所求的pre即不考虑第二尺度的最优路径，随后对这些路径进行遍历即可；
            //使用DFS或者BFS遍历，使用vector进行纪录路径

5.最小生成树
    prim算法
    struct Node
    {
        int v, dis;
    };
    vector<Node> Adj[N];
    int n;
    int d[maxv];
    bool vis[maxv] = {false};

    void prim()
    {
        fill(d, d + maxv, INF);
        d[0] = 0;
        int ans = 0;//存放最小生成树的和
        for (int i = 0; i < n;++i)
        {
            int u = -1, Min = INF;
            fof(int j = 0; j < n;++j)
            {
                if(vis[j]=false&&d[j]<Min)
                {
                    u = j;
                    Min = dis[j];
                }
            }
            if(u==-1)
            {
                return;
            }
            vis[u] = true;
            ans += d[u];
            for (int j = 0; j < Adj[u].size();++j)
            {
                int v = Adj[u][j].v;
                if(vis[v]==false&&Adj[u][j].dis<d[v])
                {
                    d[v]=Adj[u][j].dis
                }
            }
        }
        return ans;
    }
    krustral算法//使用并查集

    


    
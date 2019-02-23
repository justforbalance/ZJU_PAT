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
    
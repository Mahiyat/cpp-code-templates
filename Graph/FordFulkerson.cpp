#include<bits/stdc++.h>
using namespace std;

class Graph
{
    int V,parent[100005],S,T;
    vector<int>adj[100005];
    map<int,map<int,int> >chk;
public:
    Graph(int n, int s, int t)
    {
        V=n;
        S=s;
        T=t;
    }
    void addEdge(int u, int v, int c)
    {
        if(!chk[u][v])
        {
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        chk[u][v]+=c;
    }
    bool BFS(long long v)
    {
        vector<bool>visited(V+1,false);
        queue<long long>q;
        q.push(v);
        memset(parent,-1,sizeof(parent));
        while(!q.empty())
        {
            v=q.front();
            q.pop();
            if(visited[v]==false)
            {
                visited[v]=true;
                if(v==T)break;
                for(auto ite=adj[v].begin();ite!=adj[v].end();ite++)
                {
                    if(visited[*ite]==false&&chk[v][*ite]>0)
                    {
                        q.push(*ite);
                        parent[*ite]=v;
                    }
                }
            }
        }
        return visited[T];
    }
    int maxFlow()
    {
        int mxflow=0;
        while(BFS(S))
        {
            int pflow=INT_MAX,u,v;
            for(v=T;v!=S;)
            {
                u=parent[v];
                pflow=min(pflow,chk[u][v]);
                v=u;
            }
            for(v=T;v!=S;)
            {
                u=parent[v];
                chk[u][v]-=pflow;
                chk[v][u]+=pflow;
                v=u;
            }
            mxflow+=pflow;
        }
        return mxflow;
    }
};

int main()
{
    int n,m,s,t,u,v,w,i,ans;
    cout<<"Enter the number of vertices, number of edges, source and sink: ";
    cin>>n>>m>>s>>t;
    Graph G(n,s,t);
    cout<<"Enter the edges:\n";
    for(i=1;i<=m;i++)
    {
        cin>>u>>v>>w;
        G.addEdge(u,v,w);
    }
    ans=G.maxFlow();
    cout<<"Maximum flow: "<<ans<<"\n";
    return 0;
}
/*
    7 20 6 7
    6 1 3
    1 6 6
    6 2 6
    2 6 4
    1 3 1
    3 1 4
    1 4 4
    4 1 3
    2 3 6
    3 2 3
    2 5 2
    5 2 1
    3 4 1
    4 3 6
    3 5 4
    5 3 1
    4 7 4
    7 4 8
    5 7 7
    7 5 2

    6 9 1 6
    1 2 10
    1 4 10
    2 4 2
    2 3 4
    2 5 8
    4 5 9
    5 3 6
    3 6 10
    5 6 10
*/

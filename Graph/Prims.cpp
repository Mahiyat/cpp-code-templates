#include<bits/stdc++.h>
using namespace std;

int main()
{
    int i,n,m,cost=0,visited[105]={},key[105],inf=100001,s,u,v,w;
    int W[105][105];
    vector<int>adj[105];
    priority_queue<pair<int,int>,vector<pair<int,int> >,greater<pair<int,int> > >p;
    cout<<"Enter the number of vertices and edges of the weighted graph: ";
    cin>>n>>m;
    for(i=1;i<=n;i++)key[i]=inf;
    cout<<"Enter the edges with weight:\n";
    for(i=1;i<=m;i++)
    {
        cin>>u>>v>>w;
        adj[u].push_back(v);
        adj[v].push_back(u);
        W[u][v]=w;
        W[v][u]=w;
    }
    cout<<"Enter the source vertex: ";
    cin>>s;
    p.push(make_pair(0,s));
    key[s]=0;
    while(!(p.empty()))
    {
        pair<int,int>tmp=p.top();
        p.pop();
        u=tmp.second;
        if(!visited[u])cost+=key[u];
        visited[u]=1;
        for(auto ite=adj[u].begin();ite!=adj[u].end();ite++)
        {
            v=*ite;
            if(!visited[v])
            {
                if(key[v]>W[u][v])
                {
                    key[v]=W[u][v];
                    p.push(make_pair(key[v],v));
                }
            }
        }
    }
    cout<<"Required minimum cost: "<<cost<<"\n";
    return 0;
}

#include<bits/stdc++.h>
using namespace std;

struct node
{
    int level,value;
};

int visited[200005],cost[200005],lg,sz,H[200005];
vector<int>adj[200005];
vector<int>euler,L;
node m[400005][20];

void Build()
{
    int i,j;
    for(i=0;i<sz;i++)
    {
        m[i][0].level=L[i];
        m[i][0].value=euler[i];
    }
    for(j=1;j<=lg;j++)
    {
        for(i=0;i+(1<<(j-1))<sz;i++)
        {
            //m[i][j]=min(m[i][j-1],m[i+(1<<(j-1))][j-1]);
            if(m[i][j-1].level<m[i+(1<<(j-1))][j-1].level)
            {
                m[i][j].level=m[i][j-1].level;
                m[i][j].value=m[i][j-1].value;
            }
            else
            {
                m[i][j].level=m[i+(1<<(j-1))][j-1].level;
                m[i][j].value=m[i+(1<<(j-1))][j-1].value;
            }
        }
    }
}

int Query(int l, int r)
{
    int len=r-l+1,j,mn;
    j=log2(len);
    //mn=min(m[l][j],m[r-(1<<j)+1][j]);
    if(m[l][j].level<m[r-(1<<j)+1][j].level)mn=m[l][j].value;
    else mn=m[r-(1<<j)+1][j].value;
    return mn;
}

void BFS(int v)
{
    queue<int>q;
    q.push(v);
    cost[v]=0;
    while(!(q.empty()))
    {
        v=q.front();
        q.pop();
        //if(!visited[v])cout<<v<<" ";
        visited[v]=1;
        for(auto ite=adj[v].begin();ite!=adj[v].end();ite++)
        {
            if(!visited[*ite])
            {
                q.push(*ite);
                cost[*ite]=cost[v]+1;
            }
        }
    }
}

void DFS(int v)
{
    euler.push_back(v);
    L.push_back(cost[v]);
    visited[v]=1;
    for(auto ite=adj[v].begin();ite!=adj[v].end();ite++)
    {
        if(!visited[*ite])
        {
            //cout<<"*** "<<v<<" "<<*ite<<"\n";
            DFS(*ite);
            euler.push_back(v);
            L.push_back(cost[v]);
        }
    }
}

int main()
{
    int u,v,i,n,m,q;
    cout<<"Enter the number of vertices and edges in the graph: ";
    cin>>n>>m;
    cout<<"Enter the edges:\n";
    for(i=0;i<m;i++)
    {
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    BFS(0);
    for(i=0;i<=n;i++)visited[i]=0;
    DFS(0);
    for(i=0;i<=n;i++)visited[i]=0;
    sz=euler.size();
    lg=log2(sz);
    for(i=0;i<sz;i++)
    {
        if(!visited[euler[i]])
        {
            H[euler[i]]=i;
            visited[euler[i]]++;
        }
    }
    Build();
    cout<<"Enter the number of queries: ";
    cin>>q;
    for(i=0;i<q;i++)
    {
        cout<<"Enter the nodes whose LCA needs to be found: ";
        cin>>u>>v;
        if(H[u]>H[v])swap(u,v);
        cout<<Query(H[u],H[v])<<"\n";
    }
    return 0;
}

#include<bits/stdc++.h>
using namespace std;

int t,st[2005],ed[2005],visited[2005];
vector<int>adj[2005];
stack<int>s;

void DFS(int v)
{
    t++;
    st[v]=t;
    visited[v]=1;
    for(auto ite=adj[v].begin();ite!=adj[v].end();ite++)
    {
        if(!visited[*ite])DFS(*ite);
    }
    t++;
    ed[v]=t;
    s.push(v);
}

void DFS(int v,vector<int>adjt[])
{
    cout<<v<<" ";
    t++;
    st[v]=t;
    visited[v]=1;
    for(auto ite=adjt[v].begin();ite!=adjt[v].end();ite++)
    {
        if(!visited[*ite])DFS(*ite,adjt);
    }
    t++;
    ed[v]=t;
}

int main()
{
    int u,v,i,n,m,c=0;
    vector<int>adjt[2005];
    cout<<"Enter the number of vertices and edges in the graph: ";
    cin>>n>>m;
    cout<<"Enter the edges:\n";
    for(i=0;i<m;i++)
    {
        cin>>u>>v;
        adj[u].push_back(v);
        adjt[v].push_back(u);
    }
    for(i=0;i<n;i++)
    {
        if(!visited[i])DFS(i);
    }
    for(i=0;i<n;i++)visited[i]=0;
    t=0;
    cout<<"Strongest Connected Components in the graph:\n";
    while(!s.empty())
    {
        u=s.top();
        s.pop();
        if(!visited[u])
        {
            DFS(u,adjt);
            cout<<"\n";
            c++;
        }
    }
    cout<<"Number of Strongly Connected Components: "<<c<<"\n";
    return 0;
}


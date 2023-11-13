#include<bits/stdc++.h>
using namespace std;

int t,st[200005],ed[200005],visited[200005];
vector<int>adj[200005];
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

int main()
{
    int u,v,i,n,m;
    cout<<"Enter the number of vertices and edges in DAG: ";
    cin>>n>>m;
    cout<<"Enter the edges:\n";
    for(i=0;i<m;i++)
    {
        cin>>u>>v;
        adj[u].push_back(v);
    }
    for(i=0;i<n;i++)
    {
        if(!visited[i])DFS(i);
    }
    cout<<"After topological sort:\n";
    while(!s.empty())
    {
        cout<<s.top()<<" ";
        s.pop();
    }
    cout<<"\n";
    return 0;
}


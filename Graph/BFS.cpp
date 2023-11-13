#include<bits/stdc++.h>
using namespace std;

vector<int>adj[200005];
int cost[200005],visited[2000005];

void BFS(int v)
{
    queue<int>q;
    q.push(v);
    cost[v]=0;
    while(!(q.empty()))
    {
        v=q.front();
        q.pop();
        if(!visited[v])
        {
            cout<<v<<" ";
            visited[v]=1;
            for(auto ite=adj[v].begin(); ite!=adj[v].end(); ite++)
            {
                if(!visited[*ite])
                {
                    q.push(*ite);
                    cost[*ite]=cost[v]+1;
                }
            }
        }
    }
}

int main()
{
    int n,m,i,u,v,s;
    cout<<"Enter the number of vertices and edges of the graph: ";
    cin>>n>>m;
    cout<<"Enter the edges:\n";
    for(i=0; i<m; i++)
    {
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    cout<<"Enter the source vertex: ";
    cin>>s;
    BFS(s);
    return 0;
}

#include<bits/stdc++.h>
using namespace std;

class Graph
{
    int V;
    list<int> *adj;
    map<int,char>mp;
public:
    Graph(int n)
    {
        V=n+1;
        adj=new list<int>[n+1];
    }
    void Assign(int u, int v)
    {
        adj[u].push_back(v);
        adj[v].push_back(u);
        mp[u]='\0';
        mp[v]='\0';
    }
    void BFS(int v)
    {
        vector<bool>visited(V,false);
        queue<int>q;
        bool f=true;
        q.push(v);
        mp[v]='r';
        while(!q.empty())
        {
            v=q.front();
            q.pop();
            if(!visited[v])visited[v]=true;
            for(auto ite=adj[v].begin();ite!=adj[v].end();ite++)
            {
                if(mp[*ite]=='\0')
                {
                    if(mp[v]=='r')mp[*ite]='b';
                    else mp[*ite]='r';
                }
                else
                {
                    if(mp[v]==mp[*ite])
                    {
                        f=false;
                        break;
                    }
                }
                if(!visited[*ite])q.push(*ite);
            }
            if(!f)break;
        }
        if(f)cout<<"Bipartite Graph.\n";
        else cout<<"Not Bipartite Graph.\n";
    }

};

int main()
{
    int a,b,n,i,m;
    cout<<"Enter the number of vertices: ";
    cin>>n;
    Graph g(n);
    cout<<"Enter the number of edges: ";
    cin>>m;
    cout<<"Enter the edges:\n";
    for(i=1;i<=m;i++)
    {
        cin>>a>>b;
        g.Assign(a,b);
    }
    g.BFS(1);
    return 0;
}

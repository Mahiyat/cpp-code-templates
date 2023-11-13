#include<bits/stdc++.h>
using namespace std;

int t,low[200005],st[200005],ed[200005],visited[200005],parent[200005],cnt,sa,sb,sbc;
vector<int>adj[200005],a;
vector<pair<int,int> >bc[200005],b;
stack<pair<int,int> >edgest;

void articulationPoint(int v)
{
    t++;
    st[v]=t;
    low[v]=st[v];
    visited[v]=1;
    for(auto ite=adj[v].begin();ite!=adj[v].end();ite++)
    {
        if(!visited[*ite])
        {
            parent[*ite]=v;
            articulationPoint(*ite);
            low[v]=min(low[v],low[*ite]);
            if(parent[v]==v)
            {
                if(cnt==1)a.push_back(v);
                else cnt=1;
            }
            else
            {
                if(low[*ite]>=st[v])
                {
                    a.push_back(v);
                }
            }
        }
        else if(*ite!=parent[v]&&st[*ite]<st[v])
        {
            low[v]=min(low[v],st[*ite]);
        }
    }
    t++;
    ed[v]=t;
}

void determineAP(int n)
{
    int i;
    t=0;
    memset(visited,0,sizeof(visited));
    memset(st,0,sizeof(st));
    memset(ed,0,sizeof(ed));
    memset(low,0,sizeof(low));
    for(i=1;i<=n;i++)
    {
        if(!visited[i])articulationPoint(i);
    }
    sa=a.size();
    cout<<"Articulation Points:\n";
    for(i=0;i<sa;i++)
    {
        cout<<a[i];
        if(i<sa-1)cout<<" ";
    }
    cout<<"\n";
}

void bridge(int v)
{
    t++;
    st[v]=t;
    low[v]=st[v];
    visited[v]=1;
    for(auto ite=adj[v].begin();ite!=adj[v].end();ite++)
    {
        if(!visited[*ite])
        {
            parent[*ite]=v;
            bridge(*ite);
            low[v]=min(low[v],low[*ite]);
            if(low[*ite]>st[v])b.push_back(make_pair(v,*ite));
        }
        else if(*ite!=parent[v]&&st[*ite]<st[v])
        {
            low[v]=min(low[v],st[*ite]);
        }
    }
    t++;
    ed[v]=t;
}

void determineBridge(int n)
{
    int i;
    t=0;
    memset(visited,0,sizeof(visited));
    memset(st,0,sizeof(st));
    memset(ed,0,sizeof(ed));
    memset(low,0,sizeof(low));
    for(i=1;i<=n;i++)
    {
        if(!visited[i])bridge(i);
    }
    sb=b.size();
    cout<<"Bridges:\n";
    for(i=0;i<sb;i++)
    {
        cout<<b[i].first<<"-"<<b[i].second<<"\n";
    }
}

void biconnectedComponent(int v)
{
    t++;
    st[v]=t;
    low[v]=st[v];
    visited[v]=1;
    for(auto ite=adj[v].begin();ite!=adj[v].end();ite++)
    {
        if(!visited[*ite])
        {
            edgest.push(make_pair(v,*ite));
            parent[*ite]=v;
            biconnectedComponent(*ite);
            low[v]=min(low[v],low[*ite]);
            if(low[*ite]>=st[v])
            {
                pair<int,int>tmp;
                sbc++;
                do
                {
                    if(edgest.empty())break;
                    tmp=edgest.top();
                    edgest.pop();
                    bc[sbc].push_back(tmp);
                }while(!(tmp.first==v&&tmp.second==*ite));
            }
        }
        else if(*ite!=parent[v]&&st[*ite]<st[v])
        {
            edgest.push(make_pair(v,*ite));
            low[v]=min(low[v],st[*ite]);
        }
    }
    t++;
    ed[v]=t;
}

void determineBiconnectedComponents(int n)
{
    int i;
    t=0;
    memset(visited,0,sizeof(visited));
    memset(st,0,sizeof(st));
    memset(ed,0,sizeof(ed));
    memset(low,0,sizeof(low));
    for(i=1;i<=n;i++)
    {
        if(!visited[i])biconnectedComponent(i);
    }
    cout<<"Biconnected Components:\n";
    for(i=1;i<=sbc;i++)
    {
        cout<<"Component "<<i<<": ";
        for(auto ite=bc[i].begin();ite!=bc[i].end();ite++)
        {
            pair<int,int>tmp=*ite;
            cout<<tmp.first<<"-"<<tmp.second;
            cout<<" ";
        }
        cout<<"\n";
    }
}

int main()
{
    int u,v,i,n,m,root;
    cout<<"Enter the number of vertices and edges in the graph: ";
    cin>>n>>m;
    cout<<"Enter the edges:\n";
    for(i=0;i<m;i++)
    {
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    cout<<"Enter the root: ";
    cin>>root;
    parent[root]=root;
    determineAP(n);
    determineBridge(n);
    determineBiconnectedComponents(n);
    return 0;
}

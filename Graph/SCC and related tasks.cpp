#include<bits/stdc++.h>
using namespace std;

int t,st[2005],ed[2005],visited[2005],mp[2005],cnt[2005],fl,d,mn=100001;
vector<int>adj[2005],components[2005];
stack<int>s;
map<pair<int,int>,int >pair_check,edge_check;

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

void DFS(int v,vector<int>adjt[],int c)
{
    //cout<<v<<" ";
    components[c].push_back(v);
    mp[v]=c;
    t++;
    st[v]=t;
    visited[v]=1;
    for(auto ite=adjt[v].begin();ite!=adjt[v].end();ite++)
    {
        if(!visited[*ite])DFS(*ite,adjt,c);
    }
    t++;
    ed[v]=t;
}

void Path_Find(int u, int v)
{
    int f=0;
    if(cnt[mp[u]]==0)
    {
        d++;
        f=1;
    }
    cnt[mp[u]]++;
    visited[u]=1;
    if(u==v)
    {
        fl=1;
        mn=min(mn,d);
    }
    for(auto ite=adj[u].begin();ite!=adj[u].end();ite++)
    {
        if((*ite==v)||(!visited[*ite]))Path_Find(*ite,v);
    }
    if(f)
    {
        d--;
        cnt[mp[u]]--;
    }
}

int main()
{
    int u,v,i,n,m,c=0,j,ec=0,indeg[2005],outdeg[2005],nin=0,nout=0;
    vector<int>adjt[2005];
    cout<<"Enter the number of vertices and edges in the graph: ";
    cin>>n>>m;
    cout<<"Enter the edges:\n";
    for(i=0;i<m;i++)
    {
        cin>>u>>v;
        edge_check[(make_pair(u,v))]++;
        adj[u].push_back(v);
        adjt[v].push_back(u);
    }
    for(i=1;i<=n;i++)
    {
        if(!visited[i])DFS(i);
    }
    for(i=1;i<=n;i++)visited[i]=0;
    t=0;
    while(!s.empty())
    {
        u=s.top();
        s.pop();
        if(!visited[u])
        {
            c++;
            //cout<<"Component "<<c<<": ";
            DFS(u,adjt,c);
            //cout<<"\n";
        }
    }
    ec=c-1;
    cout<<"Number of Strongly Connected Components: "<<c<<"\n";
    cout<<"Strongest Connected Components in the graph:\n";
    for(i=1;i<=c;i++)
    {
        cout<<"Component "<<i<<": ";
        int l=components[i].size();
        ec+=(l-1);
        for(j=0;j<l;j++)cout<<components[i][j]<<" ";
        cout<<"\n";
    }
    for(i=1;i<=n;i++)
    {
        for(auto ite=adj[i].begin();ite!=adj[i].end();ite++)
        {
            int tmp=*ite;
            if(mp[i]!=mp[tmp])
            {
                pair_check[(make_pair(mp[i],mp[tmp]))]++;
            }
        }
    }
    cout<<"The compressed graph:\n";
    for(auto ite=pair_check.begin();ite!=pair_check.end();ite++)
    {
        pair<int,int>ptmp=ite->first;
        indeg[ptmp.second]++;
        outdeg[ptmp.first]++;
        cout<<ptmp.first<<" "<<ptmp.second<<"\n";
    }
    for(i=1;i<=n;i++)visited[i]=0;
    cout<<"Enter the two vertices: ";
    cin>>u>>v;
    Path_Find(u,v);
    if(fl)
    {
        cout<<"Minimum number of components encountered while traversing from "<<u<<" to "<<v<<" is "<<mn<<"\n";
    }
    else cout<<"There is no path from "<<u<<" to "<<v<<"\n";
    for(i=1;i<=c;i++)
    {
        if(indeg[i]==0)nin++;
        if(outdeg[i]==0)nout++;
    }
    ec+=max(nin,nout);
    cout<<"Number of extra edges required: "<<ec<<"\n";
    return 0;
}

//1 2
//3 1
//3 2
//4 3
//4 5
//4 7
//5 6
//6 7
//7 5


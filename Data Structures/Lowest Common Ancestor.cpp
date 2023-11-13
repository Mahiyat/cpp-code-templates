#include<bits/stdc++.h>
using namespace std;

vector<int>adj[200005];
int A[20][200005],lvl[200005],mx,lg;

void DFS(int v,int p)
{
    if(p!=-1)lvl[v]=lvl[p]+1;
    else lvl[v]=1;
    A[0][v]=p;
    for(auto ite=adj[v].begin();ite!=adj[v].end();ite++)
    {
        DFS(*ite,v);
    }
    mx=max(mx,lvl[v]);
}

void Build(int n)
{
    int j,i;
    for(j=1;(1<<j)<=n;j++)
    {
        for(i=1;i<=n;i++)
        {
            A[j][i]=A[j-1][A[j-1][i]];
        }
    }
}

int LCA(int u, int v, int n)
{
    int a=lvl[u],b=lvl[v],d,it=0,l,p1,p2;
    if(b>a)
    {
        swap(a,b);
        swap(u,v);
    }
    d=a-b;
    while(d)
    {
        if(d&1)u=A[it][u];
        d/=2;
        it++;
    }
    //cout<<u<<"&&&&\n";
    if(u==v)l=u;
    else
    {
        int j=log2((double)lvl[u]);
        //cout<<j<<"****\n";
        while(j>=0)
        {
            p1=A[j][u];
            p2=A[j][v];
            if(p1!=p2)
            {
                u=p1;
                v=p2;
            }
            j--;
        }
        l=A[0][u];
    }
    return l;
}

int main()
{
    int i,n,u,v,q;
    cin>>n>>q;
    for(i=2;i<=n;i++)
    {
        cin>>u;
        adj[u].push_back(i);
    }
    memset(A,-1,sizeof(A));
    DFS(1,-1);
    Build(n);
    for(i=1;i<=q;i++)
    {
        cin>>u>>v;
        int l=LCA(u,v,n);
        cout<<l<<"\n";
    }
    return 0;
}


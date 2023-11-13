//HLD for point update and path sum
#include<bits/stdc++.h>
using namespace std;

struct node
{
    long long sm;
    long long lazyvalue;
    bool lazyflag;
    node()
    {
        lazyflag=false;
    }
};

long long a[200005],n,parent[200005],lvl[200005],sz[200005],b[200005],st[200005],ed[200005],t,head[200005],visited[200005];
vector<long long>adj[200005];
node seg[800010];

void Build(long long idx,long long x,long long y)
{
    if(x==y)
    {
        long long ind=x;
        seg[idx].sm=b[ind];
        return;
    }
    long long mid=(x+y)/2;
    long long lft=2*idx,rgt=2*idx+1;
    Build(lft,x,mid);
    Build(rgt,mid+1,y);
    seg[idx].sm=(seg[lft].sm+seg[rgt].sm);
}

void Update(long long idx, long long st, long long ed, long long x, long long y, long long k)
{
    if(st==x&&ed==y)
    {
        seg[idx].lazyflag=true;
        seg[idx].lazyvalue=k;
        seg[idx].sm=(ed-st+1)*k;
        return;
    }
    long long mid=(st+ed)/2,lft=2*idx,rgt=2*idx+1;
    if(seg[idx].lazyflag==true)
    {
        Update(lft,st,mid,st,mid,seg[idx].lazyvalue);
        Update(rgt,mid+1,ed,mid+1,ed,seg[idx].lazyvalue);
        seg[idx].lazyflag=false;
    }
    if(y<=mid)Update(lft,st,mid,x,y,k);
    else if(x>mid)Update(rgt,mid+1,ed,x,y,k);
    else
    {
        Update(lft,st,mid,x,mid,k);
        Update(rgt,mid+1,ed,mid+1,y,k);
    }
    seg[idx].sm=(seg[lft].sm+seg[rgt].sm);
}

long long Query(long long idx , long long st, long long ed, long long x , long long y)
{
    if(st==x&&ed==y)return seg[idx].sm;
    long long mid=(st+ed)/2,lft=2*idx,rgt=2*idx+1;
    if(seg[idx].lazyflag==true)
    {
        Update(lft,st,mid,st,mid,seg[idx].lazyvalue);
        Update(rgt,mid+1,ed,mid+1,ed,seg[idx].lazyvalue);
        seg[idx].lazyflag=false;
    }
    if(y<=mid)return Query(lft,st,mid,x,y);
    else if(x>mid)return Query(rgt,mid+1,ed,x,y);
    else
    {
        long long a=Query(lft,st,mid,x,mid);
        long long b=Query(rgt,mid+1,ed,mid+1,y);
        return (a+b);
    }
}

void DFS(long long v,long long p)
{
    parent[v]=p;
    lvl[v]=lvl[p]+1;
    sz[v]=1;
    visited[v]=1;
    for(auto ite=adj[v].begin();ite!=adj[v].end();ite++)
    {
        if(!visited[*ite])
        {
            DFS(*ite,v);
            sz[v]+=sz[*ite];
            if(sz[*ite]>sz[adj[v][0]])swap(*ite,adj[v][0]);
        }
    }
}

void HLD(long long v)
{
    t++;
    st[v]=t;
    b[t]=a[v];
    visited[v]=1;
    for(auto ite=adj[v].begin();ite!=adj[v].end();ite++)
    {
        if(!visited[*ite])
        {
            if(*ite==adj[v][0])head[*ite]=head[v];
            else head[*ite]=*ite;
            HLD(*ite);
        }
    }
    ed[v]=t;
}

void Modify(long long u, long long v, long long k)
{
    while(head[u]!=head[v])
    {
        if(lvl[head[u]]<lvl[head[v]])
        {
            Update(1,1,n,st[head[v]],st[v],k);
            v=parent[head[v]];
        }
        else
        {
            Update(1,1,n,st[head[u]],st[u],k);
            u=parent[head[u]];
        }
    }
    if(st[u]<=st[v])Update(1,1,n,st[u],st[v],k);
    else Update(1,1,n,st[v],st[u],k);
}

long long Sum(long long u, long long v)
{
    long long ans=0;
    while(head[u]!=head[v])
    {
        if(lvl[head[u]]<lvl[head[v]])
        {
            ans+=Query(1,1,n,st[head[v]],st[v]);
            //cout<<ans<<"!!!\n";
            v=parent[head[v]];
        }
        else
        {
            ans+=Query(1,1,n,st[head[u]],st[u]);
            //cout<<ans<<"!!!\n";
            u=parent[head[u]];
        }
    }
    if(st[u]<=st[v])ans+=Query(1,1,n,st[u],st[v]);
    else ans+=Query(1,1,n,st[v],st[u]);
    return ans;
}

int main()
{
    long long i,q,u,v,type,j=1;
    long long c;
    cin>>n>>q;
    for(i=1;i<=n;i++)cin>>a[i];
    for(i=1;i<n;i++)
    {
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    DFS(1,1);
    for(i=0;i<=n;i++)visited[i]=0;
    HLD(1);
    Build(1,1,n);
    //for(i=1;i<=n;i++)cout<<b[i]<<"***\n";
    for(i=1;i<=q;i++)
    {
        cin>>type;
        if(type==1)
        {
            cin>>u>>v;
            Modify(u,u,v);
        }
        else
        {
            cin>>u>>v;
            c=Sum(u,v);
            cout<<c<<"\n";
        }
    }
    return 0;
}


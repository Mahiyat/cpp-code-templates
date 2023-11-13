#include<bits/stdc++.h>
using namespace std;

long long findRoot(long long u, long long Root[])
{
    if(Root[u]==u)
        return u;
    Root[u]=findRoot(Root[u],Root);
    return Root[u];
}

void dsu(long long u, long long v, long long Root[],long long &s, long long e)
{
    long long ru,rv;
    ru=findRoot(u,Root);
    rv=findRoot(v,Root);
    if(ru!=rv)
    {
        if(ru<rv)
            swap(ru,rv);
        Root[ru]=Root[rv];
        s+=e;
    }
}

bool cmp(tuple<long long,long long,long long>tp1,tuple<long long,long long,long long>tp2)
{
    return (get<2>(tp1)<get<2>(tp2));
}

int main()
{
    long long a,b,c,s=0,i,n,m,d,Root[1005],l,o;
    tuple<long long,long long,long long>tp[10005];
    cout<<"Enter the number of vertices and edges of the weighted graph: ";
    cin>>n>>m;
    for(i=1; i<=n; i++)
        Root[i]=i;
    cout<<"Enter the edges with weight:\n";
    for(i=0; i<m; i++)
    {
        cin>>b>>c>>d;
        tp[i]=make_tuple(b,c,d);
    }
    sort(tp,tp+m,cmp);
    for(i=0; i<m; i++)
    {
        b=get<0>(tp[i]);
        c=get<1>(tp[i]);
        if(Root[b]!=Root[c])
        {
            dsu(b,c,Root,s,get<2>(tp[i]));
        }
    }
    cout<<"Required minimum cost: "<<s<<"\n";
    return 0;
}


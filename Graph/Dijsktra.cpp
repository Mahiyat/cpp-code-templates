#include<bits/stdc++.h>
using namespace std;

int main()
{
    priority_queue<pair<int,int>,vector<pair<int,int> >,greater<pair<int,int> > >p;
    int i,n,a,b,c,m,inf=1000001,d[105],e[105][105],j,s,v,mp[105]={};
    cin>>n>>m;
    for(i=1;i<=n;i++)
    {
        d[i]=inf;
        for(j=1;j<=n;j++)
        {
            e[i][j]=inf;
        }
    }
    for(i=1;i<=m;i++)
    {
        cin>>a>>b>>c;
        e[a][b]=c;
    }
    cin>>s;
    p.push(make_pair(0,s));
    d[s]=0;
    mp[s]=1;
    while(!p.empty())
    {
        pair<int,int>tmp;
        tmp=p.top();
        p.pop();
        a=tmp.second;
        for(i=1;i<=n;i++)
        {
            if(d[a]+e[a][i]<d[i])
            {
                d[i]=d[a]+e[a][i];
            }
            if(!mp[i]&&d[i]!=inf)
            {
                p.push(make_pair(d[i],i));
                mp[i]=1;
            }
        }
    }
    for(i=1;i<=n;i++)
    {
        cout<<i<<" "<<d[i]<<"\n";
    }
    return 0;
}


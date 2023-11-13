#include<bits/stdc++.h>
using namespace std;

int w[105][105],q[105][105];

int main()
{
    int a,b,inf=1000001,n,m,i,j,k,c;
    cin>>n>>m;
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=n;j++)w[i][j]=inf;
    }
    for(i=1;i<=m;i++)
    {
        cin>>a>>b>>c;
        w[a][b]=c;
    }
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=n;j++)
        {
            if(i==j)q[i][j]=0;
            else q[i][j]=w[i][j];
        }
    }
    for(k=1;k<=n;k++)
    {
        for(i=1;i<=n;i++)
        {
            for(j=1;j<=n;j++)
            {
                if(i!=j)q[i][j]=min(q[i][j],(q[i][k]+q[k][j]));
            }
        }
    }
    cout<<"All Pair Shortest Path:\n";
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=n;j++)
        {
            cout<<q[i][j];
            if(j<n)cout<<" ";
        }
        cout<<"\n";
    }
    return 0;
}


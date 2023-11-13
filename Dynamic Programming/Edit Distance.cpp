#include<bits/stdc++.h>
using namespace std;

int editDistance(string x,int n,string y,int m)
{
    int E[n+5][m+5],i,j;
    for(i=0;i<=n;i++)E[i][0]=i;
    for(i=0;i<=m;i++)E[0][i]=i;
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=m;j++)
        {
            int c=1;
            if(x[i-1]==y[j-1])c=0;
            E[i][j]=min(E[i][j-1]+1,min(E[i-1][j]+1,E[i-1][j-1]+c));
        }
    }
    return E[n][m];
}

int main()
{
    string x,y;
    int n,m,a;
    cin>>x>>y;
    n=x.size();
    m=y.size();
    a=editDistance(x,n,y,m);
    cout<<a<<"\n";
    return 0;
}

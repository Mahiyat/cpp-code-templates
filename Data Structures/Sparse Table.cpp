#include<bits/stdc++.h>
using namespace std;

int n,lg,a[200005],m[20][200005];

void Build()
{
    int i,j;
    for(i=1;i<=n;i++)m[0][i]=a[i];
    for(j=1;j<=lg;j++)
    {
        for(i=1;i+(1<<(j-1))<=n;i++)
        {
            m[j][i]=min(m[j-1][i],m[j-1][i+(1<<(j-1))]);
        }
    }
}

int Query(int l, int r)
{
    int len=r-l+1,j,mn;
    j=log2(len);
    mn=min(m[j][l],m[j][r-(1<<j)+1]);
    return mn;
}

int main()
{
    int i,q,l,r;
    cin>>n;
    lg=log2(n);
    for(i=1;i<=n;i++)cin>>a[i];
    Build();
    cin>>q;
    for(i=1;i<=q;i++)
    {
        cin>>l>>r;
        cout<<Query(l,r)<<"\n";
    }
    return 0;
}

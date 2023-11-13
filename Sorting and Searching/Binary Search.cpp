#include<bits/stdc++.h>
using namespace std;

int main()
{
    int i,n,a[105],x,f=-1,l,r,m;
    cin>>n;
    for(i=0;i<n;i++)cin>>a[i];
    cin>>x;
    l=0;
    r=n-1;
    while(l<=r)
    {
        m=(l+r)/2;
        if(a[m]==x)
        {
            f=m;
            break;
        }
        else if(a[m]<x)l=m+1;
        else r=m-1;
    }
    if(f==-1)cout<<"No\n";
    else cout<<"Yes\n";cout<<"Index: "<<f+1<<"\n";
    return 0;
}

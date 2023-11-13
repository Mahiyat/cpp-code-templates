#include<bits/stdc++.h>
using namespace std;

int main()
{
    int i,n,a[105],b[105],c[100005]={},mx=0;
    cin>>n;
    for(i=0;i<n;i++)
    {
        cin>>a[i];
        c[a[i]]++;
        mx=max(mx,a[i]);
    }
    for(i=1;i<=mx;i++)
    {
        c[i]+=c[i-1];
    }
    for(i=n-1;i>=0;i--)
    {
        b[c[a[i]]-1]=a[i];
        c[a[i]]--;
    }
    cout<<"After sorting:\n";
    for(i=0;i<n;i++)
    {
        cout<<b[i];
        if(i<n-1)cout<<" ";
    }
    cout<<"\n";
    return 0;
}

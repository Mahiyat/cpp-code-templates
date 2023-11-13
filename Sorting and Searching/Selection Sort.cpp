#include<bits/stdc++.h>
using namespace std;

int main()
{
    int i,n,a[105],mx,j;
    cin>>n;
    for(i=0;i<n;i++)cin>>a[i];
    for(i=n-1;i>=0;i--)
    {
        mx=i;
        for(j=0;j<=i;j++)
        {
            if(a[mx]<a[j])mx=j;
        }
        swap(a[mx],a[i]);
    }
    cout<<"After sorting:\n";
    for(i=0;i<n;i++)
    {
        cout<<a[i];
        if(i<n-1)cout<<" ";
    }
    cout<<"\n";
    return 0;
}

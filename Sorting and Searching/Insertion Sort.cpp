#include<bits/stdc++.h>
using namespace std;

int main()
{
    int i,n,a[105],j;
    cin>>n;
    for(i=0;i<n;i++)cin>>a[i];
    for(i=0;i<n;i++)
    {
        for(j=i-1;j>=0;j--)
        {
            if(a[j]>a[j+1])swap(a[j],a[j+1]);
        }
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

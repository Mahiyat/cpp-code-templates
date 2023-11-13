#include<bits/stdc++.h>
using namespace std;

int a[105];

void CountingSort(int n, int p)
{
    int b[105],c[15]={},mx=10,i;
    for(i=0; i<n; i++)
    {
        c[(a[i]/p)%10]++;
    }
    for(i=1; i<mx; i++)
    {
        c[i]+=c[i-1];
    }
    for(i=n-1; i>=0; i--)
    {
        b[c[((a[i]/p)%10)]-1]=a[i];
        c[((a[i]/p)%10)]--;
    }
    for(i=0;i<n;i++)
    {
        a[i]=b[i];
    }
}

void RadixSort(int n)
{
    int i,mx=0;
    for(i=0;i<n;i++)mx=max(mx,a[i]);
    for(i=1;mx/i>0;i*=10)CountingSort(n,i);
}

int main()
{
    int i,n;
    cin>>n;
    for(i=0;i<n;i++)cin>>a[i];
    RadixSort(n);
    cout<<"After sorting:\n";
    for(i=0;i<n;i++)
    {
        cout<<a[i];
        if(i<n-1)cout<<" ";
    }
    cout<<"\n";
    return 0;
}

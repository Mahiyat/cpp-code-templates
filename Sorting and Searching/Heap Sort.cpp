#include<bits/stdc++.h>
using namespace std;

int a[105];

void Heapify(int i, int n)
{
    int l=2*i+1,r=2*i+2,largest;
    if(l<n&&a[l]>a[i])largest=l;
    else largest=i;
    if(r<n&&a[r]>a[largest])largest=r;
    if(largest!=i)
    {
        swap(a[i],a[largest]);
        Heapify(largest,n);
    }
}

void Heapsort(int n)
{
    int i;
    for(i=0;i<n;i++)
    {
        Heapify(0,n-i);
        swap(a[0],a[n-i-1]);
    }
}

int main()
{
    int i,n,m;
    cin>>n;
    m=n/2;
    for(i=0;i<n;i++)cin>>a[i];
    for(i=m-1;i>=0;i--)Heapify(i,n);
    Heapsort(n);
    cout<<"After sorting:\n";
    for(i=0;i<n;i++)
    {
        cout<<a[i];
        if(i<n-1)cout<<" ";
    }
    cout<<"\n";
    return 0;
}

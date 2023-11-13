#include<bits/stdc++.h>
using namespace std;

int a[105];

void Merge(int l, int r, int m)
{
    int i=l,j=m+1,k;
    vector<int>b;
    while(i<=m||j<=r)
    {
        if(i<=m&&j<=r)
        {
            if(a[i]<a[j])
            {
                b.push_back(a[i]);
                i++;
            }
            else
            {
                b.push_back(a[j]);
                j++;
            }
        }
        else if(i<=m)
        {
            b.push_back(a[i]);
            i++;
        }
        else
        {
            b.push_back(a[j]);
            j++;
        }
    }
    for(i=0,j=l;j<=r;i++,j++)
    {
        a[j]=b[i];
    }
}

void Partition(int l, int r)
{
    if(l==r)return;
    int mid=(l+r)/2;
    Partition(l,mid);
    Partition(mid+1,r);
    Merge(l,r,mid);
}

int main()
{
    int i,n;
    cin>>n;
    for(i=0;i<n;i++)cin>>a[i];
    Partition(0,n-1);
    cout<<"After sorting:\n";
    for(int i=0;i<n;i++)
    {
        cout<<a[i];
        if(i<n-1)cout<<" ";
    }
    cout<<"\n";
    return 0;
}


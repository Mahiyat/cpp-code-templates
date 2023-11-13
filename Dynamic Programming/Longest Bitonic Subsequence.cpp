#include<bits/stdc++.h>
using namespace std;

long long LBS(long long a[], long long n)
{
    long long i,j,inf=1000000007ll,LIS[n+5],LDS[n+5],mx=0;
    vector<long long>d(n+1,inf);
    for(i=0;i<n;i++)LIS[i]=LDS[i]=inf;
    d[0]=-inf;
    //map<long long,long long>mark;
    for(i=0;i<n;i++)
    {
        j=upper_bound(d.begin(),d.end(),a[i])-d.begin();
        //cout<<j<<"***\n";
        if(d[j-1]<a[i]&&a[i]<d[j])
        {
            d[j]=a[i];
            LIS[i]=j;
            //mark[a[i]]=i;
        }
        else if(d[j-1]==a[i])LIS[i]=j-1;
    }
    for(i=0;2*i<n;i++)swap(a[i],a[n-i-1]);
    for(i=0;i<=n;i++)d[i]=inf;
    d[0]=-inf;
    //mark.clear();
    for(i=0;i<n;i++)
    {
        j=upper_bound(d.begin(),d.end(),a[i])-d.begin();
        if(d[j-1]<a[i]&&a[i]<d[j])
        {
            d[j]=a[i];
            LDS[i]=j;
            //mark[a[i]]=i;
        }
        else if(d[j-1]==a[i])LDS[i]=j-1;
    }
    for(i=0;2*i<n;i++)swap(LDS[i],LDS[n-i-1]);
    for(i=0;i<n;i++)
    {
        //cout<<LIS[i]<<" "<<LDS[i]<<"\n";
        if(LIS[i]!=inf&&LDS[i]!=inf)mx=max(mx,LIS[i]+LDS[i]-1);
    }
    return mx;
}

int main()
{
    long long i,n,a[100005],mx;
    cin>>n;
    for(i=0;i<n;i++)cin>>a[i];
    mx=LBS(a,n);
    cout<<mx<<"\n";
    return 0;
}

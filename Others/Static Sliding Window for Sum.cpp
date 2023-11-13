#include<iostream>
using namespace std;

int main()
{
    int i,j,n,a[105],k,s=0,mx=0;
    cin>>n>>k;
    for(i=0;i<n;i++)
    {
        cin>>a[i];
    }
    j=0;
    for(i=0;i<n;i++)
    {
       s+=a[i];
       if(i>=k-1)
       {
           mx=max(mx,s);
           s-=a[j];
           j++;
       }
    }
    cout<<mx<<"\n";
    return 0;
}

#include<bits/stdc++.h>
using namespace std;

int main()
{
    int i,n,a[105],f=-1,x;
    cin>>n;
    for(i=0;i<n;i++)cin>>a[i];
    cin>>x;
    for(i=0;i<n;i++)
    {
        if(a[i]==x)
        {
            f=i;
            break;
        }
    }
    if(f==-1)cout<<"No\n";
    else cout<<"Yes\n";cout<<"Index: "<<f+1<<"\n";
    return 0;
}

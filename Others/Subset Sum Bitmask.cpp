#include<bits/stdc++.h>
using namespace std;

int main()
{
    int i,n,a[105],s,mask;
    cin>>n;
    for(i=0;i<n;i++)
    {
        cin>>a[i];
    }
    for(mask=0;mask<(1<<n);mask++)
    {
        s=0;
        for(i=0;i<n;i++)
        {
            if(mask&(1<<i))
            {
                s+=a[i];
                cout<<a[i]<<" ";
            }
        }
        cout<<s<<"\n";
    }
    return 0;
}

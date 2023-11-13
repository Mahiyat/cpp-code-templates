#include<bits/stdc++.h>
using namespace std;

int main()
{
    int i,n,a[105],l[105],j,prev[105],mx=0,ind=0;
    vector<int>sq;
    cout<<"Enter the number of elements: ";
    cin>>n;
    cout<<"Enter the elements: ";
    for(i=1;i<=n;i++)cin>>a[i];
    a[0]=0;
    l[0]=0;
    prev[0]=-1;
    for(i=1;i<=n;i++)
    {
        l[i]=0;
        for(j=0;j<i;j++)
        {
            if(a[i]>a[j]&&l[i]<=l[j])
            {
                l[i]=l[j];
                prev[i]=j;
            }
        }
        l[i]++;
    }
    for(i=1;i<=n;i++)
    {
        if(mx<l[i])
        {
            mx=l[i];
            ind=i;
        }
    }
    cout<<"Length of the longest increasing subsequence: "<<mx<<"\n";
    cout<<"The required sequence:\n";
    do
    {
        sq.push_back(a[ind]);
        ind=prev[ind];
    }while(ind>0);
    reverse(sq.begin(),sq.end());
    for(i=0;i<mx;i++)
    {
        cout<<sq[i];
        if(i<mx-1)cout<<" ";
    }
    cout<<"\n";
    return 0;
}

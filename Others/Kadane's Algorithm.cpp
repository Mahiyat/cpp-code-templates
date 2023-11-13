#include<iostream>
using namespace std;

//Kadane's algorithm to find maximum subarray sum.
int main()
{
    int i,n,l=0,g=INT_MIN,a[105];
    cin>>n;
    for(i=0;i<n;i++)cin>>a[i];
    for(i=0;i<n;i++)
    {
        l+=a[i];
        if(l>g)g=l;
        if(l<0)l=0;
    }
    cout<<g<<endl;
    return 0;
}

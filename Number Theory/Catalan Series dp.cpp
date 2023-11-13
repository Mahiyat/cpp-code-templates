#include<bits/stdc++.h>
using namespace std;

long long CatalanSeries(long long n)
{
    long long C[n+5],i,a,j;
    C[0]=1;
    C[1]=1;
    for(i=2;i<=n;i++)
    {
        a=0;
        for(j=0;j<i;j++)
        {
            a+=C[j]*C[i-j-1];
        }
        C[i]=a;
    }
    return C[n];
}

int main()
{
    long long n,c;
    cin>>n;
    c=CatalanSeries(n);
    cout<<c<<"\n";
    return 0;
}

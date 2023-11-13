#include<bits/stdc++.h>
using namespace std;

void phi_range(long long n,vector<long long>&phi)
{
    long long i,j;
    for(i=0;i<=n;i++)
    {
        phi.push_back(i);
    }
    for(i=2;i<=n;i++)
    {
        if(phi[i]==i)
        {
            for(j=i;j<=n;j+=i)
            {
                phi[j]-=(phi[j]/i);
            }
        }
    }
}

int main()
{
    long long n,i;
    vector<long long>phi;
    cout<<"Enter the number: ";
    cin>>n;
    phi_range(n,phi);
    for(i=1;i<=n;i++)
    {
        cout<<"Phi("<<i<<") = "<<phi[i]<<"\n";
    }
    return 0;
}

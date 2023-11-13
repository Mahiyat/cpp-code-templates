#include<bits/stdc++.h>
using namespace std;

vector<long long>v;
bool prime[1000005];
long long sz=1000000,vz;

void sieveOfEratosthenes()
{
    fill(prime,prime+sz,false);
    long long i,j;
    v.push_back(2);
    for(i=4;i<=sz;i+=2)prime[i]=true;
    for(i=3;i*i<=sz;i+=2)
    {
        if(prime[i]==false)
        {
            for(j=i*i;j<=sz;j+=(2*i))prime[j]=true;
        }
    }
    for(i=3;i<=sz;i+=2)
    {
        if(prime[i]==false)v.push_back(i);
    }
}

void countDivisor(long long a,map<long long,long long>&mp)
{
    long long i;
    for(i=0;i<vz;i++)
    {
        if(v[i]*v[i]>a)break;
        while(a%v[i]==0)
        {
            mp[v[i]]++;
            a/=v[i];
        }
    }
    if(a!=1)mp[a]++;
}

int main()
{
    int it,n;
    cin>>n;
    sieveOfEratosthenes();
    vz=v.size();
    for(it=1;it<=n;it++)
    {
        long long x,c=1;
        map<long long,long long>mp;
        cin>>x;
        countDivisor(x,mp);
        for(auto ite=mp.begin();ite!=mp.end();ite++)
        {
            c*=(ite->second+1);
        }
        cout<<c<<"\n";
    }
    return 0;
}

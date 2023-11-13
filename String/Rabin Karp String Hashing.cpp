#include<bits/stdc++.h>
using namespace std;

vector<long long>stringHashing(string T,string P)
{
    long long d=37,q=1000000007,n=T.size(),m=P.size(),h[100005],h_p,p[100005],i,sz,a,b;
    vector<long long>occurrence;
    p[0]=1;
    sz=max(n,m);
    for(i=1;i<sz;i++)
    {
        p[i]=(p[i-1]*d)%q;
    }
    h[0]=(T[0]-'a'+1)%q;
    for(i=1;i<n;i++)
    {
        h[i]=(h[i-1]*d+(T[i]-'a'+1))%q;
    }
    h_p=(P[0]-'a'+1)%q;
    for(i=1;i<m;i++)
    {
        h_p=(h_p*d+(P[i]-'a'+1))%q;
    }
    for(i=0;i<=n-m;i++)
    {
        a=i;
        b=i+m-1;
        long long h_curr=(h[b]-h[a-1]*p[b-a+1])%q;
        if(h_curr<0)h_curr+=q;
        if(h_curr==h_p)occurrence.push_back(i);
    }
    return occurrence;
}

int main()
{
    string T,P;
    cout<<"Enter the text: ";
    cin>>T;
    cout<<"Enter the pattern to be searched in the text: ";
    cin>>P;
    vector<long long>o=stringHashing(T,P);
    long long i,n=o.size();
    cout<<"Number of occurrences of the pattern in the text: "<<n<<"\n";
    cout<<"Position of Occurrences:\n";
    for(i=0;i<n;i++)
    {
        cout<<o[i]+1;
        if(i<n-1)cout<<" ";
    }
    cout<<"\n";
    return 0;
}

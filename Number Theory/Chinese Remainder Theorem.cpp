#include<bits/stdc++.h>
using namespace std;

long long MultiInverse(long long a, long long b)
{
    long long r,t,t1=0,t2=1,q,c=a;
    //if(a<b)swap(a,b);
    do
    {
        r=a%b;
        q=a/b;
        t=t1-(t2*q);
        a=b;
        b=r;
        t1=t2;
        t2=t;
    }while(b!=0);
    if(t1<0)t1+=c;
    return t1;
}

long long CRT(long long a[], long long m[], long long n)
{
    long long X=0,M[105],MI[105],MOD=1,i;
    for(i=1;i<=n;i++)
    {
        MOD*=m[i];
    }
    for(i=1;i<=n;i++)
    {
        M[i]=MOD/m[i];
        MI[i]=MultiInverse(m[i],M[i]);
        //cout<<"****"<<M[i]<<" "<<MI[i]<<"\n";
    }
    for(i=1;i<=n;i++)
    {
        X+=(a[i]*M[i]*MI[i]);
    }
    X%=MOD;
    return X;
}

int main()
{
    long long a[105],m[105],n,i,X;
    cin>>n;
    for(i=1;i<=n;i++)cin>>m[i]>>a[i];
    X=CRT(a,m,n);
    cout<<X<<"\n";
    return 0;
}

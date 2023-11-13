#include<bits/stdc++.h>
using namespace std;

int rn,lb,rb,block[15],tb,bs,be,a[15]={0,2,4,3,1,6,7,8,9,1,7},n=10,lazy[15];

void PreProcessing()
{
    rn=sqrt(n);
    tb=n/rn;
    if(n%rn!=0)tb++;
    for(int i=1;i<=tb;i++)
    {
        block[i]=100001;
        bs=((i-1)*rn)+1;
        be=i*rn;
        for(int j=bs;j<=be;j++)block[i]=min(block[i],a[j]);
    }
}

int findMinValue(int l, int r)
{
    int i,mn=100001;
    lb=((l-1)/rn)+1;
    rb=((r-1)/rn)+1;
    for(i=lb+1;i<=rb-1;i++)
    {
        if(lazy[i])mn=min(mn,lazy[i]);
        else mn=min(mn,block[i]);
    }
    be=lb*rn;
    if(lazy[lb])mn=min(mn,lazy[lb]);
    else
    {
        for(i=l;i<=min(be,r);i++)
        {
            mn=min(mn,a[i]);
        }
    }
    bs=(rb-1)*rn+1;
    if(lazy[rb])mn=min(mn,lazy[rb]);
    else
    {
        for(i=max(l,bs);i<=r;i++)
        {

            mn=min(mn,a[i]);
        }
    }

    return mn;
}

void update(int l, int r,int value)
{
    int i;
    lb=((l-1)/rn)+1;
    rb=((r-1)/rn)+1;
    for(i=lb+1;i<=rb-1;i++)lazy[i]=value;
    be=lb*rn;
    for(i=l;i<=min(be,r);i++)a[i]=value;
    for(i=(lb-1)*rn+1;i<l;i++)if(lazy[lb])a[i]=lazy[lb];
    for(i=min(be,r)+1;i<=be;i++)if(lazy[lb])a[i]=lazy[lb];
    lazy[lb]=0;
    bs=(rb-1)*rn+1;
    for(i=max(l,bs);i<=r;i++)a[i]=value;
    for(i=bs;i<max(l,bs);i++)if(lazy[rb])a[i]=lazy[rb];
    for(i=r+1;i<=rb*rn;i++)if(lazy[rb])a[i]=lazy[rb];
    lazy[rb]=0;
    block[lb]=100001;
    block[rb]=100001;
    for(i=(lb-1)*rn+1;i<=lb*rn;i++)block[lb]=min(block[lb],a[i]);
    for(i=(rb-1)*rn+1;i<=rb*rn;i++)block[rb]=min(block[rb],a[i]);
}

int main()
{
    int i,q,l,r,v;
    string type;
    PreProcessing();
    cout<<"Enter the number of queries: ";
    cin>>q;
    for(i=1;i<=q;i++)
    {
        cout<<"Enter the type of query and left and right values of range: ";
        cin>>type>>l>>r;
        if(type=="query")cout<<"Minimum value from "<<l<<" to "<<r<<" is "<<findMinValue(l,r)<<"\n";
        else
        {
            cout<<"Enter the value for updating: ";
            cin>>v;
            update(l,r,v);
        }
    }
    return 0;
}


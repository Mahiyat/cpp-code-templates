/*
    Array name: arr (1 base indexing)
    ***Queries***
    [Here 1 indicates point update and 2 indicates answering queries]
    1 add ind v: Add v to arr[ind]
    1 replace ind v: Replace value of arr[ind] with v
    2 sum lq rq: Find the sum in the array from range lq to rq inclusive
    2 min lq rq: Find the minimum value in the array from range lq to rq inclusive
    2 max lq rq: Find the maximum value in the array from range lq to rq inclusive
*/



#include<bits/stdc++.h>
using namespace std;

struct node
{
    long long sum,mn,mx;
    node()
    {
        sum=0;
        mn=1000000007;
        mx=-1000000007;
    }
};

long long n,arr[100005];
node tree[400020];

void Build(long long idx,long long l,long long r)
{
    if(l==r)
    {
        tree[idx].mn=arr[l];
        tree[idx].mx=arr[l];
        tree[idx].sum=arr[l];
        return;
    }
    long long m=(l+r)/2,lft=2*idx,rgt=2*idx+1;
    Build(lft,l,m);
    Build(rgt,m+1,r);
    tree[idx].mn=min(tree[lft].mn,tree[rgt].mn);
    tree[idx].mx=max(tree[lft].mx,tree[rgt].mx);
    tree[idx].sum=tree[lft].sum+tree[rgt].sum;
}

void Update(string type,long long idx,long long l,long long r,long long ind,long long v)
{
    if(l==r)
    {
        if(type=="replace")
        {
            tree[idx].mn=v;
            tree[idx].mx=v;
            tree[idx].sum=v;
        }
        else
        {
            tree[idx].mn+=v;
            tree[idx].mx+=v;
            tree[idx].sum+=v;
        }
        return;
    }
    long long m=(l+r)/2,lft=2*idx,rgt=2*idx+1;
    if(l<=ind&&ind<=m)Update(type,lft,l,m,ind,v);
    else if(m<ind&&ind<=r)Update(type,rgt,m+1,r,ind,v);
    tree[idx].mn=min(tree[lft].mn,tree[rgt].mn);
    tree[idx].mx=max(tree[lft].mx,tree[rgt].mx);
    tree[idx].sum=tree[lft].sum+tree[rgt].sum;
}

long long Query(string type,long long idx,long long l,long long r,long long lq,long long rq)
{
    if(l==lq&&r==rq)
    {
        if(type=="sum")return tree[idx].sum;
        else if(type=="min")return tree[idx].mn;
        else return tree[idx].mx;
    }
    long long m=(l+r)/2,lft=2*idx,rgt=2*idx+1;
    if(rq<=m)return Query(type,lft,l,m,lq,rq);
    else if(lq>m)return Query(type,rgt,m+1,r,lq,rq);
    else
    {
        long long p1,p2;
        p1=Query(type,lft,l,m,lq,m);
        p2=Query(type,rgt,m+1,r,m+1,rq);
        if(type=="sum")return (p1+p2);
        else if(type=="min")return min(p1,p2);
        else return max(p1,p2);
    }
}

int main()
{
    long long i,q,lq,rq,ind,v,qt,ans;
    string type;
    cout<<"Enter the number of elements: ";
    cin>>n;
    cout<<"Enter the elements:\n";
    for(i=1;i<=n;i++)cin>>arr[i];
    Build(1,1,n);
    cout<<"Enter the number of queries: ";
    cin>>q;
    cout<<"Array name: arr (1 base indexing)\n";
    cout<<"***Queries***\n";
    cout<<"[Here 1 indicates point update and 2 indicates answering queries]\n";
    cout<<"1 add ind v: Add v to arr[ind]\n";
    cout<<"1 replace ind v: Replace value of arr[ind] with v\n";
    cout<<"2 sum lq rq: Find the sum in the array from range lq to rq inclusive\n";
    cout<<"2 min lq rq: Find the minimum value in the array from range lq to rq inclusive\n";
    cout<<"2 max lq rq: Find the maximum value in the array from range lq to rq inclusive\n";
    cout<<"Enter the queries:\n";
    for(i=1;i<=q;i++)
    {
        cin>>qt>>type;
        if(qt==1)
        {
            cin>>ind>>v;
            Update(type,1,1,n,ind,v);
        }
        else
        {
            cin>>lq>>rq;
            ans=Query(type,1,1,n,lq,rq);
            if(type=="sum")cout<<"The required sum: "<<ans<<"\n";
            else if(type=="min")cout<<"The required minimum: "<<ans<<"\n";
            else cout<<"The required maximum: "<<ans<<"\n";
        }
    }
    return 0;
}

/*
1. Point Update(add)
2. Point Update(replace)
3. Range Update(add)
4. Prefix Sum
5. Range Sum
*/



#include<bits/stdc++.h>
using namespace std;

class FenwickTree
{
    vector<int>BIT,arr;
    int sz;
    public:
    FenwickTree(int n)
    {
        sz=n;
        arr.push_back(0);
        for(int i=0;i<=n;i++)BIT.push_back(0);
    }
    void Insert(int v)
    {
        arr.push_back(v);
    }
    void Add(int idx, int v)
    {
        while(idx<=sz)
        {
            BIT[idx]+=v;
            idx+=(idx&(-idx));
        }
    }
    void AddRange(int l, int r, int v)
    {
        Add(l,v);
        Add(r+1,-v);
    }
    void Replace(int idx,int v)
    {
        Add(idx,-arr[idx]);
        Add(idx,v);
        arr[idx]=v;
    }
    int Sum(int idx)
    {
        int s=0;
        while(idx)
        {
            s+=BIT[idx];
            idx-=(idx&(-idx));
        }
        return s;
    }
};

int main()
{
    int i,n,s,a,q,t,l,r;
    cout<<"Enter the number of elements: ";
    cin>>n;
    FenwickTree f(n);
    cout<<"Enter the elements:\n";
    for(i=1;i<=n;i++)
    {
        cin>>a;
        f.Insert(a);
        f.Add(i,a);
    }
    cout<<"***Queries***\n";
    cout<<"1. Point Update(add)\n";
    cout<<"2. Point Update(replace)\n";
    cout<<"3. Range Update(add)\n";
    cout<<"4. Prefix Sum\n";
    cout<<"5. Range Sum\n";
    cout<<"Enter the number of queries: ";
    cin>>q;
    for(i=1;i<=q;i++)
    {
        cout<<"Enter the type of query: ";
        cin>>t;
        if(t==1)
        {
            cout<<"Enter the array index and the value to be added: ";
            cin>>a>>s;
            f.Add(a,s);
        }
        else if(t==2)
        {
            cout<<"Enter the array index and the value to be replaced: ";
            cin>>a>>s;
            f.Replace(a,s);
        }
        else if(t==3)
        {
            cout<<"Enter the range and the value to be added: ";
            cin>>l>>r>>s;
            f.AddRange(l,r,s);
        }
        else if(t==4)
        {
            cout<<"Enter the array index: ";
            cin>>a;
            s=f.Sum(a);
            cout<<"The required prefix sum: ";
            cout<<s<<"\n";
        }
        else
        {
            cout<<"Enter the range: ";
            cin>>l>>r;
            s=f.Sum(r)-f.Sum(l-1);
            cout<<"The required range sum: ";
            cout<<s<<"\n";
        }
    }
    return 0;
}

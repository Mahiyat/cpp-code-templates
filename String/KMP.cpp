#include<bits/stdc++.h>
using namespace std;

void LPS(string p, int lps[])
{
    int n=p.size(),i,k=-1;
    lps[0]=-1;
    for(i=1;i<n;i++)
    {
        while(k>=0&&p[k+1]!=p[i])k=lps[k];
        if(p[k+1]==p[i])k++;
        lps[i]=k;
    }
}

void kmp(string t, string p)
{
    int n,m,lps[100005],q=-1,i;
    LPS(p,lps);
    n=t.size();
    m=p.size();
    for(i=0;i<n;i++)
    {
        while(q>=0&&p[q+1]!=t[i])q=lps[q];
        if(p[q+1]==t[i])q++;
        if(q==m-1)
        {
            cout<<"Pattern occurs with shift "<<i+1-m<<"\n";
            q=lps[q];
        }
    }
}

int main()
{
    string t,p;
    cout<<"Enter the text: ";
    cin>>t;
    cout<<"Enter the pattern: ";
    cin>>p;
    kmp(t,p);
    return 0;
}

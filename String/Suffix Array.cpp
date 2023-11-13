#include<bits/stdc++.h>
using namespace std;

vector<int> suffixArray(string s)
{
    int i,n,h,clas,x;
    n=s.size();
    vector<int>p(n+5),c(n+5),cnt(max(n+5,260),0);
    for(i=0;i<n;i++)
    {
        x=(int)s[i];
        cnt[x]++;
    }
    for(i=1;i<260;i++)cnt[i]+=cnt[i-1];
    for(i=0;i<n;i++)
    {
        x=(int)s[i];
        p[--cnt[x]]=i;
    }
    c[p[0]]=0;
    clas=1;
    for(i=1;i<n;i++)
    {
        if(s[p[i]]!=s[p[i-1]])clas++;
        c[p[i]]=clas-1;
    }
    vector<int>pn(n+5),cn(n+5);
    for(h=0;(1<<h)<n;h++)
    {
        for(i=0;i<n;i++)
        {
            pn[i]=p[i]-(1<<h);
            if(pn[i]<0)pn[i]+=n;
        }
        fill(cnt.begin(),cnt.begin()+clas,0);
        for(i=0;i<n;i++)
        {
            cnt[c[pn[i]]]++;
        }
        for(i=1;i<clas;i++)cnt[i]+=cnt[i-1];
        for(i=n-1;i>=0;i--)
        {
            p[--cnt[c[pn[i]]]]=pn[i];
        }
        cn[p[0]]=0;
        clas=1;
        for(i=1;i<n;i++)
        {
            pair<int,int>cur=make_pair(c[p[i]],c[(p[i]+(1<<h))%n]);
            pair<int,int>pre=make_pair(c[p[i-1]],c[(p[i-1]+(1<<h))%n]);
            if(cur!=pre)clas++;
            cn[p[i]]=clas-1;
        }
        c.swap(cn);
    }
    return p;
}

vector<int> LCP(string s)
{
    vector<int>suff=suffixArray(s);
    int i,n,l=0,r,j,f=0;
    n=s.size();
    vector<int>rnk(n+5),lcp(n+5,0);
    for(i=0;i<n;i++)
    {
        rnk[suff[i]]=i;
    }
    //lcp[rnk[n-1]]=0;
    for(i=0;i<n-1;i++)
    {
        r=rnk[i];
        j=suff[r-1];
        while(i+l<n&&j+l<n)
        {
            if(s[i+l]!=s[j+l])break;
            l++;
        }
        lcp[r]=l;
        l=max(l-1,0);
    }
    return lcp;
}

int main()
{
    string s;
    cin>>s;
    s+="$";
    vector<int>lcp=LCP(s);
    int i,n;
    n=s.size();
    for(i=0;i<n;i++)cout<<lcp[i]<<" ";
    cout<<"\n";
    return 0;
}

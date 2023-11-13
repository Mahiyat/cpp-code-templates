#include<bits/stdc++.h>
using namespace std;

int SubsetSumCheck(int a[], int s, int n)
{
    int i,j,S[n+5][s+5];
    for(i=0;i<=n;i++)
    {
        for(j=0;j<=s;j++)
        {
            if(j==0)S[i][j]=1;
            else if(i==0)S[i][j]=0;
            else
            {
                if(j-a[i-1]<0)S[i][j]=S[i-1][j];
                else S[i][j]=S[i-1][j-a[i-1]]|S[i-1][j];
            }
        }
    }
    return S[n][s];
}

int main()
{
    int i,n,x,s=0,a[100005],f;
    cin>>n;
    for(i=0;i<n;i++)
    {
        cin>>a[i];
        s+=a[i];
    }
    if(s&1)cout<<"Impossible\n";
    else
    {
        x=s/2;
    }
    f=SubsetSumCheck(a,x,n);
    if(f)cout<<"Possible\n";
    else cout<<"Impossible\n";
    return 0;
}

#include<bits/stdc++.h>
using namespace std;

long long MCM(long long n,long long p[])
{
    long long M[n+5][n+5],K[n+5][n+5],i,j,k,inf=1000000007ll,op,l;
    for(i=0;i<=n;i++)
    {
        for(j=0;j<=n;j++)M[i][j]=inf;
    }
    for(l=0;l<n;l++)
    {
        for(i=1;i<=n;i++)
        {
            j=i+l;
            if(j>n)continue;
            if(i==j)M[i][j]=0;
            else if(i<j)
            {
                for(k=i;k<j;k++)
                {
                    op=M[i][k]+M[k+1][j]+p[i-1]*p[k]*p[j];
                    if(op<M[i][j])
                    {
                        M[i][j]=op;
                        K[i][j]=k;
                    }
                }
            }
        }
    }
    return M[1][n];
}

int main()
{
    long long i,n,p[100005],ans;
    cout<<"Enter the number of matrices: ";
    cin>>n;
    cout<<"Enter the list of dimensions of the matrices:\n";
    for(i=0;i<=n;i++)cin>>p[i];
    ans=MCM(n,p);
    cout<<"Minimum number of operations for matrix multiplication: "<<ans<<"\n";
    return 0;
}

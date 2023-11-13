#include<bits/stdc++.h>
using namespace std;

long long p,mod=10001ll,m=2;

void matrix_multiply(long long a[][10],long long b[][10])
{
    long long i,j,k,c[10][10];
    for(i=0;i<m;i++)
    {
        for(j=0;j<m;j++)
        {
            c[i][j]=0;
            for(k=0;k<m;k++)
            {
                c[i][j]=(c[i][j]+(a[i][k]*b[k][j]))%mod;
            }
        }
    }
    for(i=0;i<m;i++)
    {
        for(j=0;j<m;j++)
        {
            a[i][j]=c[i][j];
        }
    }
}

void matrix_multiply(long long a[][10],long long b[][10],long long c[][10],long long m1,long long m2,long long o1)
{
    long long i,j,k;
    for(i=0;i<m1;i++)
    {
        for(j=0;j<o1;j++)
        {
            c[i][j]=0;
            for(k=0;k<m2;k++)
            {
                c[i][j]=(c[i][j]+(a[i][k]*b[k][j]))%mod;
            }
        }
    }
}

void matrix_exponentiation(long long a[][10],long long b[][10])
{
    while(p)
    {
        if(p&1)matrix_multiply(b,a);
        matrix_multiply(a,a);
        p/=2;
    }
}

int main()
{
    long long a[10][10]={{1,1},{1,0}},b[10][10]={{1,0},{0,1}},n,f[10][10]={{1},{0}},f_final[10][10];
    cout<<"Enter the value of n: ";
    cin>>n;
    p=n-1;
    matrix_exponentiation(a,b);
    matrix_multiply(b,f,f_final,2,2,1);
    cout<<"The "<<n<<"th fibonacci number is: "<<f_final[0][0]<<"\n";
    return 0;
}

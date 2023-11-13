#include<bits/stdc++.h>
using namespace std;

struct item{
int v;
int w;
};

int knapsack(int W, item a[], int n)
{
    int K[n+1][W+1],i,j;
    for(i=0;i<=n;i++)
    {
        for(j=0;j<=W;j++)
        {
            if(i==0||j==0)K[i][j]=0;
            else if(a[i-1].w<=j)K[i][j]=max(a[i-1].v+K[i-1][j-a[i-1].w],K[i-1][j]);
            else K[i][j]=K[i-1][j];
        }
    }
    return K[n][W];
}

int main()
{
    item ite[105];
    int n,W,i;
    cout<<"Enter the number of items: ";
    cin>>n;
    cout<<"Enter the value and weight of each item: \n";
    for(i=0;i<n;i++)
    {
        cin>>ite[i].v>>ite[i].w;
    }
    cout<<"Enter maximum weight: ";
    cin>>W;
    cout<<"Maximum value: "<<knapsack(W,ite,n)<<endl;
    return 0;
}


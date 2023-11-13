#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

int a[1000];

void divisor(int a[], int n)
{
    int i,m,j=0;
    m=sqrt(n);
    for(i=1;i*i<n;i++)
    {
        if(n%i==0)
        {
            a[j]=i;
            j++;
        }
    }
    for(i=m;i>=1;i--)
    {
        if(n%i==0)
        {
            a[j]=n/i;
            j++;
        }
    }
}

int length(int a[])
{
    int i=0,l=0;
    while(a[i])
    {
        i++;
        l++;
    }
    return l;
}

int main()
{
    int i,j,p,l,n,f;
    char s[1000005];
    scanf("%s",s);
    n=strlen(s);
    divisor(a,n);
    l=length(a);
    for(i=0;i<l;i++)
    {
        f=1;
        p=a[i];
        for(j=0;j<n-p;j++)
        {
            if(s[j]!=s[j+p])
            {
                f=0;
                break;
            }
        }
        if(f)
        {
            break;
        }
    }
    printf("%d\n",p);
    return 0;
}

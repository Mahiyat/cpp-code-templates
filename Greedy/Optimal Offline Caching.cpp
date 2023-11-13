#include<bits/stdc++.h>
using namespace std;
int main()
{
    int k,n,i,j,Framesize,f,c=0;
    string Frames,Requests;
    cin>>Framesize>>Frames>>Requests;
    n=Requests.size();
    for(i=0;i<n;i++)
    {
        f=-1;
        for(j=0;j<Framesize;j++)
        {
            if(Requests[i]==Frames[j])
            {
                f=j;
                break;
            }
        }
        if(f==-1)
        {
            c++;
            int g[105],mx=-1;
            for(j=0;j<Framesize;j++)
            {
                g[j]=n;
                for(k=i+1;k<n;k++)
                {
                    if(Frames[j]==Requests[k])
                    {
                        g[j]=k;
                        break;
                    }
                }
                mx=max(mx,g[j]);
            }
            for(j=0;j<Framesize;j++)
            {
                if(g[j]==mx)
                {
                    Frames[j]=Requests[i];
                    break;
                }
            }
        }
    }
    cout<<"Cache Misses: "<<c<<"\n";
    return 0;
}

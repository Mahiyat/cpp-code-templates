#include<bits/stdc++.h>
using namespace std;

int main()
{
    int i,n,dp[200005]={},j,k;
    string s;
    stack<int>st;
    cin>>s;
    n=s.size();
    for(i=0,k=1;i<n;i++,k++)
    {
        if(s[i]=='(')st.push(k);
        else
        {
            if(!st.empty())
            {
                j=st.top();
                st.pop();
                dp[k]=1+dp[j-1];
            }
        }
    }
    for(i=1;i<=n;i++)dp[i]+=dp[i-1];
    cout<<dp[n]<<"\n";
    return 0;
}

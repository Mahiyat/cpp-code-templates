#include<bits/stdc++.h>
using namespace std;

int main()
{
    int i,n;
    double a[105],d,med;
    priority_queue<double>small;
    priority_queue<double,vector<double>,greater<double> >large;
    vector<double>v;
    cin>>n;
    for(i=0;i<n;i++)cin>>a[i];
    med=a[0];
    v.push_back(med);
    small.push(a[0]);
    for(i=1;i<n;i++)
    {
        d=a[i];
        if(small.size()>large.size())
        {
            if(d<med)
            {
                large.push(small.top());
                small.pop();
                small.push(d);
            }
            else
            {
                large.push(d);
            }
            med=(small.top()+large.top())/2.0;
            v.push_back(med);
        }
        else if(small.size()==large.size())
        {
           if(d<med)
           {
               small.push(d);
               med=small.top();
           }
           else
           {
               large.push(d);
               med=large.top();
           }
           v.push_back(med);
        }
        else
        {
            if(d>med)
            {
                small.push(large.top());
                large.pop();
                large.push(d);
            }
            else
            {
                small.push(d);
            }
            med=(small.top()+large.top())/2.0;
            v.push_back(med);
        }
    }
    double sz=v.size();
    for(i=0;i<sz;i++)
    {
        cout<<v[i];
        if(i<sz-1)cout<<" ";
        else cout<<"\n";
    }
    return 0;
}

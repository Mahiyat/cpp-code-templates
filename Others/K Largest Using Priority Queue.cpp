#include<iostream>
#include<queue>
using namespace std;

int main()
{
    int i,n,a,k;
    priority_queue<int,vector<int>,greater<int> >q;
    cin>>n>>k;
    for(i=0;i<n;i++)
    {
        cin>>a;
        q.push(a);
        if(q.size()>k)q.pop();
    }
    cout<<q.top()<<endl;
    return 0;
}

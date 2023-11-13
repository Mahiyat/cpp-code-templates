#include<bits/stdc++.h>
using namespace std;
map<pair<int,string>,int>M;
pair<int,string>Node[100];
vector<int>G[100];
priority_queue<pair<int,string>,vector<pair<int,string> >,greater<pair<int,string> > >PQ;
void rec(int u, string codeword)
{
    if(G[u].size())
    {
        rec(G[u][0],codeword+"0");
        rec(G[u][1],codeword+"1");
    }
    else
    {
        cout<<Node[u].second<<": Length = "<<codeword.size()<<" Codeword = "<<codeword<<"\n";
    }
}
int main()
{
    int i,n;
    cin>>n;
    for(i=1;i<=n;i++)
    {
        pair<int,string>A;
        cin>>A.second>>A.first;
        M[A]=i,Node[i]=A,PQ.push(A);
    }
    int cnt=n;
    while(PQ.size()>1)
    {
        pair<int,string>x,y,z;
        x=PQ.top();
        PQ.pop();
        y=PQ.top();
        PQ.pop();
        z.first=x.first+y.first;
        z.second=x.second+y.second;
        PQ.push(z);
        cnt++;
        M[z]=cnt;
        Node[cnt]=z;
        int u,v,w;
        u=M[x];
        v=M[y];
        w=M[z];
        G[w].push_back(u);
        G[w].push_back(v);
    }
    int r=M[PQ.top()];
    rec(r,"");
    return 0;
}

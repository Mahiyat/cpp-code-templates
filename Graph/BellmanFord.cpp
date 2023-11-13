#include<bits/stdc++.h>
using namespace std;

int main()
{
    int E,V,u,v,w,i,source,j;
    vector<pair<int,pair<int,int> > >edge;
    set<int>vertex;
    cin>>V>>E;
    int dist[105];
    for(i=1;i<=E;i++)
    {
        cin>>u>>v>>w;
        edge.push_back(make_pair(u,make_pair(v,w)));
        vertex.insert(u);
        vertex.insert(v);
    }
    cin>>source;
    for(auto ite=vertex.begin();ite!=vertex.end();ite++)
    {
        dist[*ite]=100001;
    }
    dist[source]=0;
    for(i=1;i<V;i++)
    {
        for(j=0;j<E;j++)
        {
            u=edge[j].first;
            v=edge[j].second.first;
            w=edge[j].second.second;
            if(dist[u]+w<dist[v])dist[v]=dist[u]+w;
        }
    }
    int f=1;
    for(i=0;i<E;i++)
    {
        u=edge[i].first;
        v=edge[i].second.first;
        w=edge[i].second.second;
        if(dist[u]+w<dist[v])
        {
            f=0;
            break;
        }
    }
    if(!f)cout<<"Negative weight cycle exists!\n";
    else
    {
        cout<<"Shortest distance of all vertices from source vertex "<<source<<":\n";
        for(auto ite=vertex.begin();ite!=vertex.end();ite++)
        {
            cout<<*ite<<" "<<dist[*ite]<<"\n";
        }
    }
    return 0;
}


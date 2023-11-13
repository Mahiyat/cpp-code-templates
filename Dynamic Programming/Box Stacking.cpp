#include<bits/stdc++.h>
#define box tuple<int,int,int>
using namespace std;

//struct box
//{
//    int l,w,h;
//};

bool canbeStacked(box b1, box b2)
{
    return (get<0>(b1)<get<0>(b2)&&get<1>(b1)<get<1>(b2));
}

//bool operator<(const box &b1, const box &b2)
//{
//    return (b1.l<b2.l);
//}
//
//bool operator==(const box &b1, const box &b2)
//{
//    return (b1.l==b2.l&&b1.w==b2.w&&b1.h==b2.h);
//}

int main()
{
    box b[105],bp;
    multimap<box,int>height;
    vector<box>v;
    int i,n,j,m,c,d,e;
    cout<<"Enter the number of boxes: ";
    cin>>n;
    cout<<"Enter the information of each box (L,W,H):\n";
    for(i=0;i<n;i++)
    {
        cin>>c>>d>>e;
        b[i]=make_tuple(c,d,e);
    }
    sort(b,b+n);
    for(i=0;i<n;i++)
    {
        height.insert(make_pair(b[i],get<2>(b[i])));
    }
    for(i=1;i<n;i++)
    {
        bp=b[i];
        for(j=0;j<i;j++)
        {
            if(canbeStacked(b[j],bp))v.push_back(b[j]);
        }
        m=v.size();
        int mx=0;
        for(j=0;j<m;j++)
        {
            auto ite=height.find(v[j]);
            mx=max(mx,ite->second);
        }
        auto ite=height.find(bp);
        cout<<"****** ";
        //cout<<ite->first.l<<" "<<ite->first.w<<" "<<ite->first.h<<endl;
        ite->second=get<2>(bp)+mx;
        v.clear();
    }
    cout<<endl;
    int mxh=0;
    for(auto ite=height.begin();ite!=height.end();ite++)
    {
        //cout<<ite->first.l<<" "<<ite->first.w<<" "<<ite->first.h<<": "<<ite->second<<endl;
        mxh=max(mxh,ite->second);
    }
    cout<<mxh<<"\n";
    return 0;
}

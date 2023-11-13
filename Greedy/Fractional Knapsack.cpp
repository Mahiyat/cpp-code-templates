#include<bits/stdc++.h>
using namespace std;
struct Item
{
    int weight;
    double value,unit_value;
    Item(){}
    Item(int w, double v, double uv)
    {
        weight=w;
        value=v;
        unit_value=uv;
    }
    void print()
    {
        cout<<"Weight: "<<weight<<" Value: "<<value<<" Per unit value: "<<unit_value<<"\n";
    }
};
bool cmp(Item a, Item b)
{
    if(a.unit_value>b.unit_value)return true;
    return false;
}
int main()
{
    int i,n,cc,mx;
    double s=0.0;
    Item item[105];
    cin>>n;
    for(i=0;i<n;i++)
    {
        cin>>item[i].weight>>item[i].value;
        item[i].unit_value=item[i].value/(double)item[i].weight;
    }
    cin>>cc;
    sort(item,item+n,cmp);
    cout<<"After sorting:\n";
    for(i=0;i<n;i++)
    {
        item[i].print();
    }
    for(i=0;i<n;i++)
    {
        mx=min(cc,item[i].weight);
        s+=((double)mx*item[i].unit_value);
        cc-=mx;
    }
    cout<<"Maximum Profit: "<<s<<"\n";
    return 0;
}

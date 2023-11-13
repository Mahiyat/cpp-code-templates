#include<bits/stdc++.h>
using namespace std;
struct Activity
{
    int start,finish;
    Activity(){}
    Activity(int _st, int _fi)
    {
        start=_st;
        finish=_fi;
    }
    void print()
    {
        cout<<"Start Time: "<<start<<" Finish Time: "<<finish<<"\n";
    }
};
bool cmp(Activity a, Activity b)
{
    if(a.finish<b.finish)return true;
    return false;
}
int main()
{
    int N,i,s=0,f,l=0;
    cin>>N;
    Activity A[100];
    for(i=0;i<N;i++)
    {
        cin>>A[i].start>>A[i].finish;
    }
    sort(A,A+N,cmp);
    cout<<"After sorting:\n";
    for(i=0;i<N;i++)
    {
        A[i].print();
    }
    for(i=0;i<N;i++)
    {
        if(s<=A[i].start)
        {
            l++;
            s=A[i].finish;
        }
    }
    cout<<"Maximum Number of Activities: "<<l<<"\n";
    return 0;
}


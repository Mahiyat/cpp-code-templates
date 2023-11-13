#include<bits/stdc++.h>
using namespace std;
struct Event
{
    int duration,deadline;
    Event(){}
    Event(int _dur, int _dead)
    {
        duration=_dur;
        deadline=_dead;
    }
    void print()
    {
        cout<<"Duration: "<<duration<<" Deadline: "<<deadline<<"\n";
    }
};
bool cmp(Event a, Event b)
{
    if(a.deadline<b.deadline)return true;
    return false;
}
int main()
{
    int N,i,s=0,f,l=0;
    cin>>N;
    Event event[100];
    for(i=0;i<N;i++)
    {
        cin>>event[i].duration>>event[i].deadline;
    }
    sort(event,event+N,cmp);
    cout<<"After sorting:\n";
    for(i=0;i<N;i++)
    {
        event[i].print();
    }
    for(i=0;i<N;i++)
    {
        f=s+event[i].duration;
        l=max(l,max(0,f-event[i].deadline));
        s=f;
    }
    cout<<"Maximum Lateness: "<<l<<"\n";
    return 0;
}

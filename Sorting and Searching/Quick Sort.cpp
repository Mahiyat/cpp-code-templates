#include<iostream>
using namespace std;

int arr[105];

int Partition(int l, int r)
{
    int pivot=l;
    while(l<r)
    {
        if(pivot==l)
        {
            if(arr[pivot]<arr[r])
            {
                r--;
            }
            else
            {
                swap(arr[pivot],arr[r]);
                pivot=r;
            }
        }
        if(pivot==r)
        {
            if(arr[pivot]>arr[l])
            {
                l++;
            }
            else
            {
                swap(arr[pivot],arr[l]);
                pivot=l;
            }
        }
    }
    return pivot;
}

void Quicksort(int l, int r)
{
    if(l>=r)return;
    int mid=Partition(l,r);
    Quicksort(l,mid-1);
    Quicksort(mid+1,r);
}

int main()
{
    int i,n;
    cin>>n;
    for(i=0;i<n;i++)cin>>arr[i];
    Quicksort(0,n-1);
    cout<<"After sorting:\n";
    for(i=0;i<n;i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<"\n";
    return 0;
}

#include<bits/stdc++.h>
using namespace std;

int On_Segment(int x1, int y1, int x2, int y2, int x3, int y3)
{
    if(min(x1,x2)<=x3&&x3<=max(x1,x2)&&min(y1,y2)<=y3&&y3<=max(y1,y2))return 1;
    else return 0;
}

int Direction(int x1, int y1, int x2, int y2, int x3, int y3)
{
    return ((x2*y3-x3*y2)-(x1*y3-x3*y1)+(x1*y2-x2*y1));
}

int Segment_Intersection(int x1, int y1, int x2, int y2, int x3, int y3, int x4, int y4)
{
    int d1,d2,d3,d4;
    d1=Direction(x3,y3,x1,y1,x4,y4);
    d2=Direction(x3,y3,x2,y2,x4,y4);
    d3=Direction(x1,y1,x3,y3,x2,y2);
    d4=Direction(x1,y1,x4,y4,x2,y2);
    if(((d1<0&&d2>0)||(d1>0&&d2<0))&&((d3<0&&d4>0)||(d3>0&&d4<0)))return 1;
    else if(d1==0&&On_Segment(x3,y3,x4,y4,x1,y1))return 1;
    else if(d2==0&&On_Segment(x3,y3,x4,y4,x2,y2))return 1;
    else if(d3==0&&On_Segment(x1,y1,x2,y2,x3,y3))return 1;
    else if(d4==0&&On_Segment(x1,y1,x2,y2,x4,y4))return 1;
    else return 0;
}

int main()
{
    int x1,y1,x2,y2,x3,y3,x4,y4,c;
    cout<<"Enter the coordinates of the initial point of first line segment: ";
    cin>>x1>>y1;
    cout<<"Enter the coordinates of the final point of first line segment: ";
    cin>>x2>>y2;
    cout<<"Enter the coordinates of the initial point of second line segment: ";
    cin>>x3>>y3;
    cout<<"Enter the coordinates of the final point of second line segement: ";
    cin>>x4>>y4;
    c=Segment_Intersection(x1,y1,x2,y2,x3,y3,x4,y4);
    if(c)cout<<"The line segments intersect.\n";
    else cout<<"The line segments do no intersect.\n";
    return 0;
}

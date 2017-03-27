#include <bits/stdc++.h>
#define ll long long
#define MOD 1000000007
#define mp make_pair
#define pb push_back
using namespace std;
int main()
{
  //  ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int x=1,y=0,sx,tx,ty;
    string check;
    int low=0,high=1001;
    while(low<high-1)
    {
    int mid=(low+high)/2;
    cout<<"? "<<mid<<" "<<y<<endl;
    fflush(stdout);
    cin>>check;
    if(check=="NO")
    high=mid;
    else
    low=mid;
    }
    sx=low;
    y=sx*2,low=0,high=1001;
    while(low<high-1)
    {
    int mid=(low+high)/2;
    cout<<"? "<<mid<<" "<<y<<endl;
    fflush(stdout);
    cin>>check;
    if(check=="NO")
    high=mid;
    else
    low=mid;
    }
    tx=low;
    low=0,high=1001,x=0;
    while(low<high-1)
    {
    int mid=(low+high)/2;
    cout<<"? "<<x<<" "<<mid<<endl;
    fflush(stdout);
    cin>>check;
    if(check=="NO")
    high=mid;
    else
    low=mid;
    }
    ty=low;
    int area1=4*sx*sx;
    ty=ty-(2*sx);
    int area2=ty*tx;
    cout<<"! "<<area1+area2<<endl;
   // fflush(stdout);
    return 0;
}    
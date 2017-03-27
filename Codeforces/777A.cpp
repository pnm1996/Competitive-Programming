#include <bits/stdc++.h>
#define ll long long
#define MOD 1000000007
#define mp make_pair
#define pb push_back
using namespace std;
int main()
{
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int n,a;
    cin>>n;
    cin>>a;
    int vis1[]={2,3,3,2,1,1};
    int vis2[]={1,1,2,3,3,2};
    int vis3[]={3,2,1,1,2,3};
    int ans=n%6;
    if(ans==0)
    ans=6;
    if(vis1[ans-1]==a+1)
    cout<<0;
    else if(vis2[ans-1]==a+1)
    cout<<1;
    else
    cout<<2;
    return 0;
}
#include <bits/stdc++.h>
#define ll long long
#define MOD 1000000007
#define mp make_pair
#define pb push_back
using namespace std;
int main()
{
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int n;
    cin>>n;
    ll a[n+1];
    for(int i=1;i<=n;i++)
    cin>>a[i];
    ll ans1=0,curr=0;
    for(int i=1;i<n;i++)
    {
        ll val=abs(a[i]-a[i+1]);
        if(i&1)
        {
            curr=max(val,curr+val);
        }
        else
        {
            curr-=val;
        }
        ans1=max(ans1,curr);
    }
    curr=0;
    ll ans2=0;
    for(int i=2;i<n;i++)
    {
        ll val=abs(a[i]-a[i+1]);
        if(!(i&1))
        {
            curr=max(val,curr+val);
        }
        else
        {
            curr-=val;
        }
        ans2=max(ans2,curr);
    }
    cout<<max(ans1,ans2);
    return 0;
}
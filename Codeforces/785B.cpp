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
    ll r1=LLONG_MAX,l1=0,r2=LLONG_MAX,l2=0;
    for(int i=0;i<n;i++)
    {
        ll l,r;
        cin>>l>>r;
        l1=max(l1,l);
        r1=min(r1,r);
    }
    int m;
    cin>>m;
    for(int i=0;i<m;i++)
    {
        ll l,r;
        cin>>l>>r;
        l2=max(l2,l);
        r2=min(r2,r);
    }
    ll ans=max(l1-r2,l2-r1);
    cout<<max(0LL,ans);
    return 0;
}
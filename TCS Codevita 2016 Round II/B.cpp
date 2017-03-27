#include <bits/stdc++.h>
#define ll long long
using namespace std;
int main()
{
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    ll n;
    string a;
    cin>>n>>a;
    ll c=0;
    for(ll i=0;i<n-1;i++)
    if((a[i]=='R' && a[i+1]=='R') || (a[i]!=a[i+1]))
    c++;
    cout<<c;
    return 0;
}
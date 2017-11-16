#include<bits/stdc++.h>
#define ll long long
#define pb push_back
using namespace std;
int n,k;
int memo[10000];
vector <int> v;
ll solve(int i) 
{
    if(i>=n) 
	return 0;
    if(memo[i]!=-1) 
	return memo[i];
    ll ret=0;
    ret=max(ret,solve(i+1));
    ret=max(ret,v[i]+solve(i+k+1));
    return memo[i]=ret;
}

int main() 
{
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	char x;
	cin>>n>>x>>k;
    memset(memo,-1,sizeof(memo));
    for(int i=0;i<n;i++) 
	 {
            int a;
            cin>>a;
            v.pb(a);
     }
    ll ans=solve(0);
    cout<<ans<<endl;
    return 0;
}
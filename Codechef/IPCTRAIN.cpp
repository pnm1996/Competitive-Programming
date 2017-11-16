#include <bits/stdc++.h>
#define ll long long
#define mp make_pair
#define pb push_back
#define ff first
#define ss second
#define pll pair<ll,ll>
using namespace std;
int main() 
{
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int t;
	cin>>t;
	while(t--)
	{
	    ll n,d,a,b,c;
	    cin>>n>>d;
	    multiset<pll,greater<pll>> comp[d+1],ans;
	    for(ll i=1;i<=n;i++)
	    {
	        cin>>a>>b>>c;
	        comp[a].insert(mp(c,b));
	    }
	    for(ll i=1;i<=d;i++)
	    {
	        for(auto it : comp[i])
	        {
	            ans.insert(it);
	        }
	        if(ans.empty())
	        continue;
	        ll x=(*ans.begin()).ff;
	        ll y=(*ans.begin()).ss;
	        ans.erase(ans.begin());
	        y--;
	        if(y!=0)
	        ans.insert(mp(x,y));
	    }
	    ll fin=0;
	    for(auto it : ans)
	    fin+=(it.ff*it.ss);
	    cout<<fin<<endl;
	}
	return 0;
}
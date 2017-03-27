#include <bits/stdc++.h>
#define ll long long
using namespace std;
int main() 
{
	int t;
	cin>>t;
	while(t--)
	{
	    ll o1,o2,c1=0,c0=0;
	    cin>>o1>>o2;
	    ll n=o1*o2;
	    ll a[n+1],dp[n+1]={0};
	    for(ll i=1;i<=n;i++)
	    cin>>a[i];
	    ll first=a[1];
	    for(ll i=1;i<=o2;i++)
	    {
	        if(a[i]==1)
	        c1++;
	        else
	        c0++;
	    }
	    if(o2==1)
	    {
	        ll cd=0,cc=0;
	        for(ll i=1;i<=n;i++)
	        {
	        if(a[i]==1)
	        cd++;
	        else
	        cc++;
	        }
	        puts(cd>cc?"1":"0");
	    }
	    else if(o1==1)
	    {
	       puts(c1>c0?"1":"0");
	    }
	    else
	    {
	    for(ll i=o2+1;i<=n;i++)
	    {
	        if(first==0)
	        c0--;
	        else
	        c1--;
	        first=a[i-o2+1];
	        if(a[i]==1)
	        c1++;
	        else
	        c0++;
	        if(c1>c0)
	        dp[i]=dp[i-o2]+1;
	        else
	        dp[i]=dp[i-o2];
	    }
	    for(ll i=1;i<=o2;i++)
	    {
	        if(first==0)
	        c0--;
	        else
	        c1--;
	        if(i!=o2)
	        first=a[n+i-o2+1];
	        if(a[i]==1)
	        c1++;
	        else
	        c0++;
	        if(c1>c0)
	        dp[i]=dp[n+i-o2]+1;
	        else
	        dp[i]=dp[n+i-o2];
	    }
	    ll ans=0;
	    for(ll i=o2+1;i<=n;i++)
	    {
	    dp[i]=max(dp[i],dp[i-o2]);
	    ans=max(ans,dp[i]);
	    }
	  c1=0,c0=0;
	  puts((ans>o1/2)?"1":"0");
	}
	}
	return 0;
}
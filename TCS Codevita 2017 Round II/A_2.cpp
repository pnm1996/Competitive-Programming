#include <bits/stdc++.h>
#define ll long long
#define MOD 1000000007
#define mp make_pair
#define pb push_back
#define ff first
#define ss second
using namespace std;
vector<ll> f(1005,1);
ll base;
void pre()
{
	ll i;
	for(i=2;i<1005;i++)
	{
		f[i]=i*i;
	}
}
ll cost(ll req)
{
	ll high=base,low=high-req+1;
	ll sum=0,i;
	for(i=low;i<=high;i++)
	{
		if(i<2)
		sum++;
		else
		sum+=f[i];
	}
	sum*=1000;
	return sum;
}
int main()
{
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	pre();
    int t;
    cin>>t;
    while(t--)
    {
        ll n,i;
		cin>>n>>base;
		ll a[n],b[n];
		for(i=0;i<n;i++)
		cin>>a[i];
		ll maxval=0,maxval1=0,maxval2=0;
		if(n&1)
		{
			ll mid=n/2;
			for(i=0;i<n;i++)
			maxval=max(maxval,abs(mid-i)+a[i]);
			b[mid]=maxval;
		//	cout<<maxval<<endl;
			for(i=mid-1;i>=0;i--)
			{
				b[i]=b[i+1]-1;
			}
			for(i=mid+1;i<n;i++)
			{
				b[i]=b[i-1]-1;
			}
		}
		else
		{
			ll mid1=n/2-1,mid2=mid1+1;
		//	cout<<mid1<<" "<<mid2<<endl;
			for(i=0;i<n;i++)
			{
				maxval1=max(maxval1,abs(mid1-i)+a[i]);
			//	cout<<(abs(mid1-i)+a[i])<<" ";
			}
		//	cout<<endl;
		//	cout<<"mid2"<<endl;
			for(i=0;i<n;i++)
			{
				maxval2=max(maxval2,abs(mid2-i)+a[i]);
			//	cout<<(abs(mid2-i)+a[i])<<" ";
			}
		//	cout<<endl;
		    maxval=max(maxval1,maxval2)-1;
			b[mid1]=maxval;
			b[mid2]=maxval;
			for(i=mid1-1;i>=0;i--)
			{
				b[i]=b[i+1]-1;
			}
			for(i=mid2+1;i<n;i++)
			{
				b[i]=b[i-1]-1;
			}
		//	cout<<maxval<<endl;
		//	for(i=0;i<n;i++)
		//	cout<<b[i]<<" ";
		//	cout<<endl;
		}
		ll ans=0;
		for(i=0;i<n;i++)
		{
			ans+=cost(b[i]-a[i]);
		}
		cout<<ans<<endl;
    }
    return 0;
}
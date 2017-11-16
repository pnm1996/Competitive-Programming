#include <bits/stdc++.h>
#define ll long long
#define MOD 1000000007
#define mp make_pair
#define pb push_back
#define ff first
#define ss second
using namespace std;
int main()
{
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	ll a[1010][1010],dp[1010][1010],fibo[50];
	fibo[0]=0; fibo[1]=1; fibo[2]=1;
    ll r,c,n,i,j;
	cin>>r>>c>>n;
	for(i=3;i<50;i++)
	fibo[i]=fibo[i-1]+fibo[i-2];
	for(i=0;i<r;i++)
	{
		for(j=0;j<c;j++)
		{
			cin>>a[i][j];
		}
	}
	for(i=0;i<r;i++)
	{
		dp[i][0]=(a[i][0])%50;
		for(j=1;j<c;j++)
		{
			dp[i][j]=((a[i][j]%50)+(dp[i][j-1]%50))%50;
		}
	}
	while(n--)
	{
		ll x1,y1,x2,y2,sum=0;
		cin>>x1>>y1>>x2>>y2;
		ll p1=min(x1,x2);
		ll q1=min(y1,y2);
		ll p2=max(x1,x2);
		ll q2=max(y1,y2);
		for(i=p1;i<=p2;i++)
		{
			if(q1==0)
			sum+=dp[i][q2];
			else
			sum+=dp[i][q2]-dp[i][q1-1];
		//	cout<<sum<<endl;
			sum%=50;
		}
	//	cout<<sum<<endl;
		cout<<fibo[sum]<<endl;
	}
    return 0;
}
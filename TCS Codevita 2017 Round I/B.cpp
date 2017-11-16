#include <bits/stdc++.h>
#define ll long long
#define MOD 1000000007
#define mp make_pair
#define pb push_back
#define ff first
#define ss second
using namespace std;
int m,n;
int dp[40][40];
char mat[40][40];
bool inside(int x,int y)
{
//	cout<<x<<" "<<y<<endl;
	if(x>=1 and x<=m and y>=1 and y<=n)
	return true;
	return false;
}
bool check()
{
	for(int i=1;i<=m;i++)
	{
		for(int j=1;j<=n;j++)
		{
			if(dp[i][j]==0)
			return false;
		}
	}
	return true;
}
void recur(int xx,int yy)
{
		//if(check())
		//break;
	//	cout<<xx<<" "<<yy<<endl;
		if(inside(xx,yy-1) and mat[xx][yy-1]=='T' and dp[xx][yy-1]>dp[xx][yy]+1)
		{
			dp[xx][yy-1]=dp[xx][yy]+1;
		//	cout<<"hi"<<endl;
			recur(xx,yy-1);
		}
		if(inside(xx-1,yy-1) and mat[xx-1][yy-1]=='T' and dp[xx-1][yy-1]>dp[xx][yy]+1)
		{
			dp[xx-1][yy-1]=dp[xx][yy]+1;
			recur(xx-1,yy-1);
		}
		if(inside(xx-1,yy) and mat[xx-1][yy]=='T' and dp[xx-1][yy]>dp[xx][yy]+1)
		{
			dp[xx-1][yy]=dp[xx][yy]+1;
			recur(xx-1,yy);
		}
		if(inside(xx-1,yy+1) and mat[xx-1][yy+1]=='T' and dp[xx-1][yy+1]>dp[xx][yy]+1)
		{
			dp[xx-1][yy+1]=dp[xx][yy]+1;
			recur(xx-1,yy+1);
		}
		if(inside(xx,yy+1) and mat[xx][yy+1]=='T' and dp[xx][yy+1]>dp[xx][yy]+1)
		{
			dp[xx][yy+1]=dp[xx][yy]+1;
			recur(xx,yy+1);
		}
		if(inside(xx+1,yy+1) and mat[xx+1][yy+1]=='T' and dp[xx+1][yy+1]>dp[xx][yy]+1)
		{
			dp[xx+1][yy+1]=dp[xx][yy]+1;
			recur(xx+1,yy+1);
		}
		if(inside(xx+1,yy) and mat[xx+1][yy]=='T' and dp[xx+1][yy]>dp[xx][yy]+1)
		{
			dp[xx+1][yy]=dp[xx][yy]+1;
			recur(xx+1,yy);
		}
		if(inside(xx+1,yy-1) and mat[xx+1][yy-1]=='T' and dp[xx+1][yy-1]>dp[xx][yy]+1)
		{
			dp[xx+1][yy-1]=dp[xx][yy]+1;
			recur(xx+1,yy-1);
		}
}
int main()
{
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin>>m>>n;
	int x,y;
	cin>>x>>y;
	for(int i=1;i<=m;i++)
	{
		for(int j=1;j<=n;j++)
		{
			cin>>mat[i][j];
			if(mat[i][j]=='W')
			dp[i][j]=-1;
			else
			dp[i][j]=MOD;
		}
	}
	dp[x][y]=1;
	recur(x,y);
	int ans=0;
	for(int i=1;i<=m;i++)
	{
		for(int j=1;j<=n;j++)
		{
		//	cout<<dp[i][j]<<" ";
			ans=max(ans,dp[i][j]);
		}
	//	cout<<endl;
	}
	cout<<ans<<endl;
    return 0;
}
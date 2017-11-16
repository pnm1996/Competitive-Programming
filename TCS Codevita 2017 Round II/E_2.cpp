#include <bits/stdc++.h>
#define ll long long
#define MOD 1000000007
#define mp make_pair
#define pb push_back
#define ff first
#define ss second
using namespace std;
int n;
bool inside(int x,int y)
{
    if(x>=1 and x<=n and y>=1 and y<=n)
    return true;
    return false;
}
int main()
{
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int i,j;
	char x;
	cin>>n;
	int a[n+5][n+5],dp[n+5][n+5];
	bool vis[n+5][n+5];
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=n;j++)
		{
			cin>>a[i][j]>>x;
			vis[i][j]=false;
			dp[i][j]=0;
		}
	}
	if(n==1)
	{
		cout<<0<<endl;
		return 0;
	}
	queue< pair<int,int> > q;
	dp[1][1]=0;
	q.push(mp(1,1));
	vis[1][1]=true;
	bool hoja=false;
	while(!q.empty())
	{
		pair<int,int> cur=q.front();
		q.pop();
		int x=cur.ff;
		int y=cur.ss;
		cout<<x<<" "<<y<<endl;
		int j=0;
		bool flag=false;
		if(y==n and hoja)
		{
			x++;
			flag=true;
		}
		else if(y==1 and hoja)
		x++;
		else
		j=1;
		for(i=1;i<=6;i++)
		{
			if(!flag)
			{
				if(inside(x,y+j) and !vis[x][y+j])
				{
					dp[x][y+j]=dp[x][y]+1;
					q.push(mp(x,y+j));
					vis[x][y+j]=true;
				}
				if(y+j==n)
				{
					flag=true;
					x++;
					continue;
				}
				j++;
			}
			else
			{
				if(inside(x,y+j) and !vis[x][y+j])
				{
					dp[x][y+j]=dp[x][y]+1;
					q.push(mp(x,y+j));
					vis[x][y+j]=true;
				}
				if(y+j==1)
				{
					flag=false;
					x++;
					continue;
				}
				j--;
			}
		} 
		hoja=true;
	}
	for(i=1;i<=n;i++)
	{
	    for(j=1;j<=n;j++)
	    cout<<dp[i][j]<<" ";
	    cout<<endl;
	}
	cout<<dp[n][n]<<endl;
    return 0;
}
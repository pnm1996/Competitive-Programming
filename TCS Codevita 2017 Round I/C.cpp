#include <bits/stdc++.h>
#define ll long long
#define mp make_pair
#define pii pair<int,int>
using namespace std;
int main() 
{
			int t,i,j,k;
    	    int n,m,x,y;
			char lul;
    	    cin>>n>>lul>>m;
    	    int b[12][12];
			int a[12][12];
			int c[12][12];
    	    for(i=1;i<=n;i++)
    	    {
    	        for(j=1;j<=m;j++)
    	        {
					if(j==m)
					cin>>a[i][j];
					else
    	            cin>>a[i][j]>>lul;
    	            b[i][j]=0;
    	            c[i][j]=-1;
    	        }
    	    }
			cin>>x>>lul>>y;
    	    b[x][y]=1;
    	    queue<pii> q;
			q.push(mp(x,y));
    	    while(!q.empty())
    	    {
    	    //	pii qq=q.front();
    	    //	cout<<qq.first<<" "<<qq.second<<endl;
    	        pair<int,int> cor;
    	        cor=q.front();
    	        q.pop();
    	        int x=cor.first,y=cor.second;
    	        if((x>0 && x<=n) and (y>0 && y<=m) and c[x][y]==-1)
    	        {
    	        	c[x][y]=0;
    	            int val1=-1,val2=-1,val3=-1,val4=-1;
    	            if(a[x-1][y]<a[x][y]) // top
    	            {
    	                val1=a[x-1][y];
    	            }
    	            if(a[x][y-1]<a[x][y]) // left
    	            {
    	                val2=a[x][y-1];         
    	            }
    	            if(a[x][y+1]<a[x][y]) // right
    	            {
    	                val3=a[x][y+1];           
    	            }
 
    	            if(a[x+1][y]<a[x][y]) // down
    	            {
    	                val4=a[x+1][y];          
    	            } 
    	            int temp=max(val1,max(val2,max(val3,val4)));
    	            if(val1==temp)
    	            {
    	            	q.push(mp(x-1,y));
    	            	b[x-1][y]=max(b[x][y]+1,b[x-1][y]);
    	            }
    	            if(val2==temp)
    	            {
    	            	q.push(mp(x,y-1));
    	            	b[x][y-1]=max(b[x][y]+1,b[x][y-1]);
    	            }
    	            if(val3==temp)
    	            {
    	            	q.push(mp(x,y+1));
    	            	b[x][y+1]=max(b[x][y]+1,b[x][y+1]);
    	            }
    	            if(val4==temp)
    	            {
    	            	q.push(mp(x+1,y));
    	            	b[x+1][y]=max(b[x][y]+1,b[x+1][y]);
    	            }
    	        }
    	    }
    	    int ans=0;
			for(i=1;i<=n;i++)
    	    {
    	        for(j=1;j<=m;j++)
    	        {
    	         //   cout<<b[i][j]<<" ";
    	            ans=max(ans,b[i][j]);
    	        }
    	     //   cout<<endl;
    	    }
    	    cout<<ans<<endl;
    	return 0;
    }
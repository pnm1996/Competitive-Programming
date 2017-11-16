#include <bits/stdc++.h>
#define ll long long
#define mp make_pair
#define pb push_back
using namespace std;
int main() 
{
		int i,j,k;
	    int n;
	    cin>>n;
	    int max=0;
	    int a[20][20],b[20][20],c[20][20];
	    for(i=1;i<=n;i++)
	    {
	        for(j=1;j<=n;j++)
	        {
	            cin>>a[i][j];
	            b[i][j]=0;
	            c[i][j]=-1;
	        }
	    }
		int x1,y1,x2,y2;
		cin>>x1>>y1;
		cin>>x2>>y2;
		a[x1][y1]=5;
	    queue< pair<int,int> > q;
		q.push(mp(x1,y1));
		bool flag=true;
	    while(!q.empty())
	    {
	        pair<int,int> cor;
	        cor=q.front();
	        q.pop();
	        int x=cor.first,y=cor.second;
	        if((x>0 and x<=n) and (y>0 and y<=n) and c[x][y]==-1 and a[x][y]>1)
	        {
	            c[x][y]=0;
	            if(a[x-1][y-1]==1)
	            {
	                a[x-1][y-1]=flag?a[x][y]:a[x][y]-1;
	                q.push(make_pair(x-1,y-1));           
	            }
	            if(a[x-1][y]==1)
	            {
	                a[x-1][y]=flag?a[x][y]:a[x][y]-1;
	                q.push(make_pair(x-1,y));            
	            }
	            if(a[x-1][y+1]==1)
	            {
	                a[x-1][y+1]=flag?a[x][y]:a[x][y]-1;
	                q.push(make_pair(x-1,y+1));           
	            }
	            if(a[x][y-1]==1)
	            {
	                a[x][y-1]=flag?a[x][y]:a[x][y]-1;
	                q.push(make_pair(x,y-1));            
	            }
	            if(a[x][y+1]==1)
	            {
	                a[x][y+1]=flag?a[x][y]:a[x][y]-1;
	                q.push(make_pair(x,y+1));            
	            }
	            if(a[x+1][y-1]==1)
	            {
	                a[x+1][y-1]=flag?a[x][y]:a[x][y]-1;
	                q.push(make_pair(x+1,y-1));            
	            }
	            if(a[x+1][y]==1)
	            {
	                a[x+1][y]=flag?a[x][y]:a[x][y]-1;
	                q.push(make_pair(x+1,y));           
	            }
	            if(a[x+1][y+1]==1)
	            {
	                a[x+1][y+1]=flag?a[x][y]:a[x][y]-1;
	                q.push(make_pair(x+1,y+1));          
	            }
	        }
			flag=false;
	    }
	/*	for(j=1;j<=n;j++)
	    {
	        for(k=1;k<=n;k++)
	        {
	            cout<<a[j][k]<<" "; 
	        }
	        cout<<endl;
	    } */
		
		for(i=1;i<=n;i++)
	    {
	        for(j=1;j<=n;j++)
	        {
	            c[i][j]=-1;
	        }
	    }
		if(a[x2][y2]>1)
		{
		a[x2][y2]=1;
		c[x2][y2]=0;
		q.push(mp(x2,y2));
		flag=true;
	    while(!q.empty())
	    {
	        pair<int,int> cor;
	        cor=q.front();
	        q.pop();
	        int x=cor.first,y=cor.second;
	        if((x>0 and x<=n) and (y>0 and y<=n))
	        {
	            if(a[x-1][y-1]!=0 and c[x-1][y-1]==-1)
	            {
					if(a[x-1][y-1]!=1)
	                a[x-1][y-1]=flag?a[x][y]:a[x-1][y-1]-1;
	                q.push(make_pair(x-1,y-1));
					c[x-1][y-1]=0;
	            }
	            if(a[x-1][y]!=0 and c[x-1][y]==-1)
	            {
	                if(a[x-1][y]!=1)
	                a[x-1][y]=flag?a[x][y]:a[x-1][y]-1;
	                q.push(make_pair(x-1,y));
					c[x-1][y]=0;
	            }
	            if(a[x-1][y+1]!=0 and c[x-1][y+1]==-1)
	            {
	                if(a[x-1][y+1]!=1)
	                a[x-1][y+1]=flag?a[x][y]:a[x-1][y+1]-1;
	                q.push(make_pair(x-1,y+1)); 
					c[x-1][y+1]=0;
	            }
	            if(a[x][y-1]!=0 and c[x][y-1]==-1)
	            {
	                if(a[x][y-1]!=1)
	                a[x][y-1]=flag?a[x][y]:a[x][y-1]-1;
	                q.push(make_pair(x,y-1));
					c[x][y-1]=0;
	            }
	            if(a[x][y+1]!=0 and c[x][y+1]==-1)
	            {
	                if(a[x][y+1]!=1)
	                a[x][y+1]=flag?a[x][y]:a[x][y+1]-1;
	                q.push(make_pair(x,y+1)); 
					c[x][y+1]=0;
	            }
	            if(a[x+1][y-1]!=0 and c[x+1][y-1]==-1)
	            {
	                if(a[x+1][y-1]!=1)
	                a[x+1][y-1]=flag?a[x][y]:a[x+1][y-1]-1;
	                q.push(make_pair(x+1,y-1));
					c[x+1][y-1]=0;
	            }
	            if(a[x+1][y]!=0 and c[x+1][y]==-1)
	            {
	                if(a[x+1][y]!=1)
	                a[x+1][y]=flag?a[x][y]:a[x+1][y]-1;
	                q.push(make_pair(x+1,y)); 
					c[x+1][y]=0;
	            }
	            if(a[x+1][y+1]!=0 and c[x+1][y+1]==-1)
	            {
	                if(a[x+1][y+1]!=1)
	                a[x+1][y+1]=flag?a[x][y]:a[x+1][y+1]-1;
	                q.push(make_pair(x+1,y+1)); 
					c[x+1][y+1]=0;
	            }
	        }
			flag=false;
	    }
		}	
		
	    for(j=1;j<=n;j++)
	    {
	        for(k=1;k<=n;k++)
	        {
	            cout<<a[j][k]<<" "; 
	        }
	        cout<<endl;
	    }
	return 0;
}
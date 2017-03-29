#include <bits/stdc++.h>
#define ll long long
#define MOD 1000000007
using namespace std;
int main()
{
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int n,k,r;
    cin>>n>>k>>r;
    int cost[n][n],req[r],tech[k];
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            cin>>cost[i][j];
            if(cost[i][j]==0)
            cost[i][j]=MOD;
        }
    }
    bool flag1=true;
    while(flag1)
    {
    flag1=false;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            for(int jj=0;jj<n;jj++)
            {
              if(cost[i][j]>cost[i][jj]+cost[jj][j])
              {
                  flag1=true;
                  cost[i][j]=cost[i][jj]+cost[jj][j];
              }
            }
        }
    }
    }
    for(int i=0;i<k;i++)
    cin>>tech[i];
    for(int i=0;i<r;i++)
    cin>>req[i];
    int ans=0;
    for(int i=0;i<r;i++)
    {
        int flag=0;
        for(int j=0;j<k;j++)
        {
            if(tech[j]==req[i])
            {
                flag=1;
                break;
            }
        }
        if(!flag)
        {
           int c=cost[tech[0]][req[i]];
           int mini=0;
           for(int j=1;j<k;j++)
           {
               if(cost[tech[j]][req[i]]<c)
               {
                mini=j;
                c=cost[tech[j]][req[i]];
               }
           }
           tech[mini]=req[i];
           ans+=c;
        //   cout<<c<<" ";
        }
    }
    cout<<ans<<endl;
}
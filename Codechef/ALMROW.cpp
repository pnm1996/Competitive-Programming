#include <bits/stdc++.h>
#define ll long long
#define MOD 1000000007
#define mp make_pair
#define pb push_back
using namespace std;
vector <int> adj[1000010];
bool vis[1000010];
int level[1000010];
int main()
{
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        for(int i=1;i<=n;i++)
        adj[i].clear(); 
        int k;
        cin>>k;
        for(int i=0;i<k;i++)
        {
            int x,y;
            cin>>x>>y;
            adj[x].pb(y);
            adj[y].pb(x);
        }
        for(int i=1;i<n;i++)
        {
            adj[i].pb(i+1);
            adj[i+1].pb(i);
        }
        ll ans=0;
        for(int i=1;i<n;i++)
        {
                for(int i=1;i<=n;i++)
                vis[i]=0;
                level[i]=0;
                vis[i]=true;
                queue <int> q;
                q.push(i);
                while(!q.empty())
                {
                    int s=q.front();
                    q.pop();
                    for(int ii=0;ii!=adj[s].size();ii++)
                    {
                        if(!vis[adj[s][ii]])
                        {
                            vis[adj[s][ii]]=true;
                            q.push(adj[s][ii]);
                            level[adj[s][ii]]=level[s]+1;
                        }
                    }
                } 
            for(int j=i+1;j<=n;j++)
            ans+=level[j];
       } 
        cout<<ans<<endl;
    }
    return 0;
}   
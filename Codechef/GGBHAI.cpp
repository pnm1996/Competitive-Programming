#include <bits/stdc++.h>
#define ll long long
#define MOD 1000000007
#define mp make_pair
#define pb push_back
using namespace std;
int main()
{
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int t;
    cin>>t;
    while(t--)
    {
        int n,m,a,b;
        cin>>n>>m;
        vector <int> r(m+10);
        vector <int> adj[n+10];
        vector <int> visited(n+10,false);
        vector <int> level(n+10);
        for(int i=0;i<n-1;i++)
        {
            cin>>a>>b;
            adj[a].pb(b);
            adj[b].pb(a);
        }
        for(int i=0;i<m;i++)
        cin>>r[i];
        queue<int> q;
        q.push(1);
        visited[1]=true;
        level[1]=0;
        while(!q.empty())
        {
            int s=q.front();
            q.pop();
            for(int i=0;i!=adj[s].size();i++)
            {
                if(!visited[adj[s][i]])
                {
                    q.push(adj[s][i]);
                    visited[adj[s][i]]=true;
                    level[adj[s][i]]=level[s]+1;
                }
            }
        }
        double ans=0;
        for(int i=0;i<m;i++)
        ans+=level[r[i]];
        ans*=2;
        cout<<setprecision(6)<<fixed<<ans/m<<endl;
    }
    return 0;
} 
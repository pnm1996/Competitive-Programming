#include <bits/stdc++.h>
#define ll long long
#define MOD 1000000007
#define mp make_pair
#define pb push_back
#define N 100010
using namespace std;
vector<pair<int,int>> adj[N];
ll INF=LLONG_MAX;
vector<ll> D(N);
void dijkstra(int source)    
{
    D[source]=0;
    set<pair<ll,ll>> Q;
    Q.insert({0,source});
    while(!Q.empty())   
    {
        ll u=(*Q.begin()).second;
      //  cout<<u<<" ";
        Q.erase(Q.begin());
        for(auto next : adj[u])
        {
            ll v=next.first,weight=next.second;
            if(D[u]+weight<D[v]) 
            {
                if(Q.find({D[v],v})!=Q.end())
                Q.erase(Q.find({D[v],v}));
                D[v]=D[u]+weight;
                Q.insert({D[v],v});
            } 
        }
    }
 //   cout<<endl;
}
int main()
{
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int t;
    cin>>t;
    while(t--)
    {
        int n,k,x,m,s;
        cin>>n>>k>>x>>m>>s;
        for(int i=1;i<=n;i++)
        adj[i].clear();
        for(int i=1;i<=n;i++)
        D[i]=INF;
        int a,b,c;
        for(int i=0;i<m;i++)
        {
            cin>>a>>b>>c;
            adj[a].pb({b,c});
            adj[b].pb({a,c});
        }
        if(s<=k)
        {
            for(int i=1;i<=k;i++)
            {
            if(s!=i)
            {
            adj[s].pb({i,x});
            adj[i].pb({s,x});
            }
            }
        }
     /*   for(int i=1;i<=n;i++)
        {
            cout<<i<<": ";
            for(auto j : adj[i])
            cout<<j.first<<" "<<j.second<<" ";
            cout<<endl;
        } */
        dijkstra(s);
        if(s>k)
        {
        ll mn=INF;
        int j;
        for(int i=1;i<=k;i++)
        {
        if(D[i]<mn)
        {
        mn=D[i];
        j=i;
        }
        }
        for(int i=1;i<=k;i++)
        {
            if(i==j)
            continue;
            adj[i].pb({j,x});
            adj[j].pb({i,x});
        }
      /*  for(int i=1;i<=n;i++)
        {
            cout<<i<<": ";
            for(auto j : adj[i])
            cout<<j.first<<" "<<j.second<<" ";
            cout<<endl;
        } */
        for(int i=1;i<=n;i++)
        D[i]=INF;
        dijkstra(s);
        }
        for(int i=1;i<=n;i++)
        cout<<D[i]<<" ";
        cout<<endl;
    }
    return 0;
}    
#include <bits/stdc++.h>
#define ll long long
#define MOD 1000000007
using namespace std;
vector<int> adj[1000];
vector<bool> visited(1000,false);
void dfs(int s)
{
    visited[s]=true;
    for(int i=0;i!=adj[s].size();i++)
    {
        if(!visited[adj[s][i]])
        dfs(adj[s][i]);
    }
}
int main()
{
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        for(int i=0;i<n;i++)
        {
        adj[i].clear();
        visited[i]=false;
        }
        int a;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                cin>>a;
                if(a==1)
                {
                    adj[i].push_back(j);
                }
            }
        }
      /*  for(int i=0;i<n;i++)
        {
            for(int j=0;j!=adj[i].size();j++)
            cout<<adj[i][j]<<" ";
            cout<<endl;
        } */
        int c=0;
        for(int i=0;i<n;i++)
        {
            if(!visited[i])
            {
                c++;
                dfs(i);
            }
        }
        cout<<c<<endl;
    }
    return 0;
} 
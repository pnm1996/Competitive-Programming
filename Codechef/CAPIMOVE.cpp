#include <bits/stdc++.h>
#define ll long long
#define MOD 1000000007
using namespace std;
int main()
{
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        int p;
        set<pair<int,int>,greater<pair<int,int>>> s;
        map<pair<int,int>,int> mat;
       /* for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=n;j++)
            {
                mat[i][j]=0;
            }
        } */
      //  memset(mat,0,sizeof(mat));
        for(int i=1;i<=n;i++)
        {
        cin>>p;
        s.insert(make_pair(p,i));
        mat[make_pair(i,i)]=1;
        }
     //   vector <int> adj[n+1];
        int a,b;
        for(int i=0;i<n-1;i++)
        {
            cin>>a>>b;
            mat[make_pair(a,b)]=1;
            mat[make_pair(b,a)]=1;
       //     adj[a].push_back(b);
      //      adj[b].push_back(a);
        }
        int ans[n+1]={0};
        for(int i=1;i<=n;i++)
        {
            for(auto it=s.begin();it!=s.end();++it)
            {
                int cmp=(*it).second;
                if(mat[make_pair(i,cmp)]==0)
                {
                ans[i]=cmp;
                break;
                }
            }
        }
        for(int i=1;i<=n;i++)
        cout<<ans[i]<<" ";
        cout<<endl;
    }
    return 0;
}   
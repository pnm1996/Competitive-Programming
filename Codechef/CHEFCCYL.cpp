     #include <bits/stdc++.h>
        #define ll long long
        #define MOD 1000000007
        #define mp make_pair
        #define pb push_back
        #define ff first
        #define ss second
        #define N 100005
        using namespace std;
        vector<vector<ll>>adj;
        vector<vector<ll>>dp;
        ll comp(ll i,ll l,ll r,ll n)
        {
        //    cout<<i<<" "<<l<<" "<<r<<" "<<n<<endl;
            if(l==r)
            return 0;
            ll d1,d2;
            if(l>r)
            swap(l,r);
         //   cout<<dp[i][1]<<" "<<dp[i][2]<<" "<<dp[i][3]<<endl;
        //    cout<<adj[i][1]<<" "<<adj[i][2]<<" "<<adj[i][3]<<endl;
            if(l==1)
            {
                d1=dp[i][r-1];
                d2=dp[i][n]-dp[i][r-1];
            }
            else
            {
                d1=dp[i][r-1]-dp[i][l-1];
                d2=dp[i][l-1]+dp[i][n]-dp[i][r-1];
            }
         //   cout<<d1<<" "<<d2<<endl;
            return min(d1,d2);
        }
        int main()
        {
            ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
            ll t;
            cin>>t;
            while(t--)
            {
                ll left[N],right[N],weight[N],cycle[N],dpcycle[N],nodes[N],dpweight[N];
                ll n,q;
                cin>>n>>q;
                adj.resize(n+1);
                dp.resize(n+1);
                for(ll i=1;i<=n;i++)
                {
                    cin>>nodes[i];
                    adj[i].resize(nodes[i]+1);
                    dp[i].resize(nodes[i]+1);
                    adj[i].clear();
                    dp[i].clear();
                    for(ll j=1;j<=nodes[i];j++)
                    {
                        cin>>adj[i][j];
                    }
                }
                for(ll i=1;i<=n;i++)
                {
                    ll v1,v2,w;
                    cin>>v1>>v2>>w;
                    left[i%n+1]=v2;
                    right[i]=v1;
                    weight[i]=w;
                }
                for(ll i=1;i<=n;i++)
                {
                    dp[i][1]=adj[i][1];
                    for(ll j=2;j<=nodes[i];j++)
                    {
                        dp[i][j]=dp[i][j-1]+adj[i][j];
                    }
                }
                for(ll i=1;i<=n;i++)
                cycle[i]=comp(i,left[i],right[i],nodes[i]);
                dpcycle[1]=cycle[1];
                for(ll i=2;i<=n;i++)
                dpcycle[i]=dpcycle[i-1]+cycle[i]; 
                dpweight[1]=weight[1];
                for(ll i=2;i<=n;i++)
                dpweight[i]=dpweight[i-1]+weight[i]; 
                while(q--)
                {
                    ll v1,c1,v2,c2;
                    cin>>v1>>c1>>v2>>c2;
                    if(c2<c1)
                    {
                        swap(c1,c2);
                        swap(v1,v2);
                    }
                 //   cout<<v1<<" "<<c1<<" "<<v2<<" "<<c2<<endl;
                    ll d1=dpcycle[c2-1]-dpcycle[c1];
                    ll d2;
                    if(c1==1)
                    d2=dpcycle[n]-dpcycle[c2];
                    else
                    d2=dpcycle[c1-1]+dpcycle[n]-dpcycle[c2];
                //    cout<<d1<<" "<<d2<<endl;
                    ll rightvertex1=right[c1];
                    ll leftvertex1=left[c1];
                    ll rightvertex2=right[c2];
                    ll leftvertex2=left[c2];
               //     cout<<rightvertex1<<endl;
                //    cout<<rightvertex2<<endl;
                    ll right1=comp(c1,v1,rightvertex1,nodes[c1]);
                    ll right2=comp(c2,v2,rightvertex2,nodes[c2]);
                    ll left1=comp(c1,leftvertex1,v1,nodes[c1]);
                    ll left2=comp(c2,leftvertex2,v2,nodes[c2]);
                 //   cout<<left1<<" "<<left2<<" "<<right1<<" "<<right2<<endl;
                    d1+=right1+left2;
                    d2+=left1+right2;
                    if(c1==1)
                    d1+=dpweight[c2-1];
                    else
                    d1+=dpweight[c2-1]-dpweight[c1-1];
                    if(c1==1)
                    d2+=dpweight[n]-dpweight[c2-1];
                    else
                    d2+=dpweight[n]-dpweight[c2-1]+dpweight[c1-1];
              //      cout<<d1<<" "<<d2<<endl;
                    cout<<min(d1,d2)<<endl;
                } 
            }
            return 0;
        }   
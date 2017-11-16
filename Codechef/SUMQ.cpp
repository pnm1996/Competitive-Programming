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
            ll p,q,r;
            cin>>p>>q>>r;
            vector<ll> a(p),b(q),c(r);
            for(ll i=0;i<p;i++)
            cin>>a[i];
            for(ll i=0;i<q;i++)
            cin>>b[i];
            for(ll i=0;i<r;i++)
            cin>>c[i];
            sort(a.begin(),a.end());
            sort(c.begin(),c.end());
            vector<ll> dp1(p),dp2(r),ans(q,0);
            dp1[0]=a[0]; dp2[0]=c[0];
            for(ll i=1;i<p;i++)
            dp1[i]=(dp1[i-1]+a[i])%MOD;
            for(ll i=1;i<r;i++)
            dp2[i]=(dp2[i-1]+c[i])%MOD;
            for(ll i=0;i<q;i++)
            {
                ll up=upper_bound(a.begin(),a.end(),b[i])-a.begin();
                ll down=upper_bound(c.begin(),c.end(),b[i])-c.begin();
                if(up==0LL or down==0LL)
                continue;
                ll sz=(up*down)%MOD;
            //    cout<<sz<<endl;
                up--; down--;
            //    cout<<up<<" "<<down<<endl;
                ll sum=b[i]*b[i];
                sum%=MOD;
                sum=(sum*sz)%MOD;
            //    cout<<sum<<endl;
                sum=(sum+(b[i]*((dp1[up]*(down+1))%MOD+(dp2[down]*(up+1))%MOD)%MOD)%MOD)%MOD;
            //    cout<<sum<<endl;
                sum=(sum+(dp1[up]*dp2[down])%MOD)%MOD;
            //    cout<<sum<<endl;
                ans[i]=sum;
            }
         /*   for(ll i=0;i<q;i++)
            cout<<ans[i]<<" ";
            cout<<endl; */
            ll fin=0;
            for(ll i=0;i<q;i++)
            fin=(fin+ans[i])%MOD;
            cout<<fin<<endl;
        }
        return 0;
    } 
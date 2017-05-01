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
        string s;
        cin>>s;
        vector <int> v;
        int n=s.length();
        for(int i=0;i<n;i++)
        if(s[i]=='1')
        v.pb(i+1);
        if(v.size()==0)
        cout<<0<<endl;
        else if(v.size()==1)
        {
          if(v[0]==n)
          cout<<0<<endl;
          else
          cout<<n-v[0]+1<<endl;
        }
        else
        {
          /*  for(int i : v)
            cout<<i<<" ";
            cout<<endl; */
            ll ans=0,cons=1;
            for(int i=0;i<v.size()-1;i++)
            {
            if(v[i+1]-v[i]!=1)
            {
                ans+=(v[i+1]-v[i])*cons;
                cons++;
            }
            else
            cons++;
            }
            if(s[n-1]=='0')
            ans+=(n-v[v.size()-1]+1)*cons;
            cout<<ans<<endl;
        }
    }
    return 0;
} 
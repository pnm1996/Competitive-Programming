#include <bits/stdc++.h>
#define ll long long
#define MOD 1000000007
#define mp make_pair
#define pb push_back
#define ff first
#define ss second
using namespace std;
int main()
{
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int t;
    cin>>t;
    while(t--)
    {
        ll n,s;
        cin>>n>>s;
        vector<ll> odd,even;
        if(n==1)
        {
        	if(s>9)
        	cout<<-1<<endl;
        	else
        	cout<<s<<endl;
        }
        else if(n&1)
        {
            if(s>9*n or s==1)
            cout<<-1<<endl;
            else
            {
                ll temp=s/2;
                for(ll i=1;i<=n/2;i++)
                {
                    odd.pb(min(9LL,temp));
                    temp-=9;
                    if(temp<0)
                    temp=0;
                }
                ll sum=0;
                for(ll i=0;i<odd.size();i++)
                {
                    sum+=odd[i];
                    cout<<odd[i];
                }
                sum*=2;
                ll mid=s-sum;
                cout<<mid;
                reverse(odd.begin(),odd.end());
                for(ll i=0;i<odd.size();i++)
                cout<<odd[i];
                cout<<endl;
            }
        }
        else
        {
            if(s&1 or s>9*n)
            cout<<-1<<endl;
            else
            {
                ll temp=s/2;
                for(ll i=1;i<=n/2;i++)
                {
                    even.pb(min(9LL,temp));
                    temp-=9;
                    if(temp<0)
                    temp=0;
                }
                for(ll i=0;i<even.size();i++)
                cout<<even[i];
                for(ll i=even.size()-1;i>=0;i--)
                cout<<even[i];
                cout<<endl;
            }
        }
    }
    return 0;
}
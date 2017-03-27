#include <bits/stdc++.h>
#define ll long long
#define MOD 1000000007
#define mp make_pair
#define pb push_back
using namespace std;
int main()
{
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    ll ts,tf,t;
    cin>>ts>>tf>>t;
    int n;
    cin>>n;
    ll a[n];
    for(int i=0;i<n;i++)
    cin>>a[i];
    if(n==0 or a[0]>ts)
    cout<<ts;
    else
    {
        int flag=0;
        ll start=ts;
        for(int i=1;i<=n;i++)
        {
            start+=t;
            if(start>tf-t)
            {
                flag=1;
                break;
            }
            if(i==n)
            break;
            if(a[i]>start)
            break;
        }
      //  cout<<"flag="<<flag<<endl;
        if(!flag)
        cout<<start;
        else
        {
            ll wait=ts-a[0]+1;
            ll ans=a[0]-1;
            start=ts+t;
            for(int i=1;start<=tf-t;i++)
            {
                if(start-a[i]+1<wait)
                {
                wait=start-a[i]+1;
                ans=a[i]-1;
                }
                start+=t;
            }
            cout<<ans;
        }
    }
    return 0;
}	
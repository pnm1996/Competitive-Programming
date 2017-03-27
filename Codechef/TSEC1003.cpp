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
       int n;
       cin>>n;
       int a[n],flag=0,mini=INT_MIN;
       for(int i=0;i<n;i++)
       {
       cin>>a[i];
       if(a[i]<0)
       {
        mini=max(mini,a[i]);
       flag++;
       }
       }
       int curr=0,ans1=INT_MIN,ans2=0;
       for(int i=0;i<n;i++)
       {
           if(a[i]>0)
           ans2+=a[i];
           curr=max(a[i],curr+a[i]);
           ans1=max(ans1,curr);
       }
       if(flag==n)
       cout<<ans1<<" "<<mini<<endl;
       else
       cout<<ans1<<" "<<ans2<<endl;
    }
    return 0;
} 
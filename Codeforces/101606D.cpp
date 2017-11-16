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
    string s;
    cin>>s;
    int n=s.length();
    bool vis[n]={0};
    int dest[n];
    string original=s;
    sort(original.begin(),original.end());
 //   cout<<original<<endl;
 //   cout<<s<<endl;
    for(int i=0;i<n;i++)
    {
       for(int j=0;j<n;j++)
       {
           if(vis[j])
           continue;
           if(original[i]==s[j])
           {
               dest[i]=j;
               vis[j]=true;
               break;
           }
       }
    }
    ll swaps=0;
    for(int i=0;i<n;i++)
    {
        if(dest[i]!=i)
        swaps++;
    }
 //   for(int i=0;i<n;i++)
//    cout<<dest[i]<<" ";
//    cout<<endl;
    while(1)
    {
    for(int i=0;i<n;i++)
    {
        if(dest[i]==i)
        continue;
        int l=i;
        int r=dest[i];
        if(original[l]>original[r])
        cout<<l+1<<" "<<r+1<<endl;
        else
        cout<<r+1<<" "<<l+1<<endl;
        swap(original[l],original[r]);
        swap(dest[l],dest[r]);
        break;
    }
    bool flag=false;
    for(int i=0;i<n;i++)
    {
        if(dest[i]!=i)
        {
            flag=true;
            break;
        }
    }
    if(!flag)
    break;
    }
 //   for(int i=0;i<n;i++)
 //   cout<<dest[i]<<" ";
//   cout<<endl;
    return 0;
}
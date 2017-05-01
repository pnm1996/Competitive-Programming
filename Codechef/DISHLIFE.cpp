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
        int n,k,flag1=0;
        cin>>n>>k;
        set<int>s1;
        vector <int> island[k+1];
        for(int i=1;i<=n;i++)
        {
            int p;
            cin>>p;
            for(int j=0;j<p;j++)
            {
                int a;
                cin>>a;
                s1.insert(a);
                island[a].pb(i);
            }
        }
        if(s1.size()<k)
        cout<<"sad"<<endl;
        else
        {
           unordered_map<int,int> v;
           int c=0;
           for(int i=1;i<=k;i++)
           {
               if(island[i].size()==1)
               {
                   if(!v[island[i][0]])
                   {
                       c++;
                       v[island[i][0]]=1;
                   }
               }
           }
           if(c==n)
           cout<<"all"<<endl;
           else
           cout<<"some"<<endl;
        }
    }
    return 0;
} 
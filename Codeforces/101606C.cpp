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
    int n;
    cin>>n;
    string color[n];
    map<string,int> m;
    m["red"]=1;m["yellow"]=2;m["green"]=3;m["brown"]=4;m["blue"]=5;m["pink"]=6;m["black"]=7;
    set<pair<int,string>,greater<pair<int,string>>> v;
    for(int i=0;i<n;i++)
    cin>>color[i];
    int red=0;
    for(int i=0;i<n;i++)
    {
        if(color[i]=="red")
        red++;
        else
        v.insert(mp(m[color[i]],color[i]));
    }
    ll curr=0;
    if(v.size())
    {
        curr=(*v.begin()).ff;
    }
    ll ans=curr*red;
//    cout<<ans<<endl;
    for(auto it : v)
    {
        ans+=it.ff;
    }
    if(v.empty())
    cout<<"1"<<endl;
    else
    cout<<ans+red<<endl;
    return 0;
}
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
    cin.ignore();
    while(t--)
    {
        string s;
        getline(cin,s);
    //    cout<<s<<endl;
		map<char,int> m;
		map<char,int>::iterator it;
        for(unsigned int i=0;i<s.length();i++)
		{
			char x=s[i];
			if(x!=' ')
			{
				for(it=m.begin();it!=m.end();++it)
				{
					if(x<=it->ff and it->ss==1)
					{
						m[it->ff]=0;
						break;
					}
				}
				m[x]=1;
			}
		}
		ll ans=0;
		for(it=m.begin();it!=m.end();++it)
		if(it->ss==1)
		ans++;
		cout<<ans<<endl;
    }
    return 0;
}
#include <bits/stdc++.h>
using namespace std;
#define ll long long int
int main() {
    int t,n,i,q;
    ll a,val;
    cin>>t>>n;
    multiset <ll> s;
    for(i=0;i<n;i++)
    {
        cin>>a;
        s.insert(a);
    }
    while(t--)
    {
        cin>>q>>val;
        if(q==1)
        s.insert(val);
        else if(q==2)
        {
            if(s.find(val)!=s.end())
            {
            while(s.find(val)!=s.end())
            s.erase(val);
            }
        }
        else
        {
            if(!s.empty())
            {
            ll max=*s.rbegin();
            multiset <ll>::iterator it;
         /*   for(it=s.begin();it!=s.end();++it)
          {
            if(*it==max)
            break;
          } */
            it=s.find(max);
            if(it==s.begin())
            {
            cout<<"-1"<<endl;
            continue;
            }
            --it;
            ll sum=*it+max;
            cout<<sum<<endl;
           }
           else
           cout<<"-1"<<endl;
    }
    }
	return 0;
}
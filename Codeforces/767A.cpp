#include <bits/stdc++.h>
#define ll long long
#define MOD 1000000007
#define mp make_pair
#define pb push_back
using namespace std;
int main()
{
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++)
    cin>>a[i];
    set<int,greater<int>> s;
    int m=n;
    for(int i=0;i<n;i++)
    {
        if(a[i]==m)
        {
            cout<<m<<" ";
            m--;
            while(s.size())
            {
                if(*s.begin()==m)
                {
                cout<<*s.begin()<<" ";
                s.erase(s.begin());
                m--;
                }
                else
                break;
            }
        }
        else
        {
            s.insert(a[i]);
        }
        cout<<endl;
    }
    return 0;
}
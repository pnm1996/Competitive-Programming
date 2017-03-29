#include <bits/stdc++.h>
#define ull unsigned long long
#define MOD 1000000007
using namespace std;
int main()
{
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    ull n;
    cin>>n;
    ull ans=n%9;
    if(ans==0)
    cout<<9<<endl;
    else
    cout<<ans<<endl;
    return 0;
} 
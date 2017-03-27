#include <bits/stdc++.h>
#define ll long long
#define MOD 1000000007
#define mp make_pair
#define pb push_back
using namespace std;
int main()
{
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int n,m;
    cin>>n>>m;
    int flag1=0;
    while(m--)
    {
        int k;
        cin>>k;
        int a[k];
        for(int i=0;i<k;i++)
        cin>>a[i];
        int flag=0;
        if(k==0)
        continue;
        map<int,int> mat;
        for(int i=0;i<k;i++)
        {
            if(mat[-1*a[i]]==1)
            {
                flag=1;
                break;
            }
            mat[a[i]]=1;
        }
        if(!flag)
        flag1=1;
    }
    if(flag1)
    cout<<"YES"<<endl;
    else
    cout<<"NO"<<endl;
    return 0;
}
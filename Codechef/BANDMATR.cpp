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
        int z[n]={0},o[n]={0};
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                int a;
                cin>>a;
                (a==0)?z[abs(i-j)]++:o[abs(i-j)]++;
            }
        }
     /*   for(int i=0;i<n;i++)
        cout<<z[i]<<" "<<o[i]<<" ";
        cout<<endl; */
        int i=n-1,j=n-2;
        while(i>=0 and j>=0)
        {
            if(i==j)
            {
            j--;
            continue;
            }
            if(z[j]>=o[i])
            {
                z[j]-=o[i];
                o[j]+=o[i];
                o[i]=0;
                i--;
                if(z[j]==0) j--;
            }
            else
            {
                o[i]-=z[j];
                o[j]+=z[j];
                z[j]=0;
                j--;
            }
        }
        i=0;
        for(;i<n;i++)
        if(o[i]==0)
        break;
        cout<<max(0,i-1)<<endl;
    }
    return 0;
} 
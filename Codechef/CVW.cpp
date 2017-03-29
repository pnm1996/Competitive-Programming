#include <bits/stdc++.h>
#define ll long long
#define MOD 1000000007
using namespace std;
int main()
{
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int t;
    cin>>t;
    while(t--)
    {
        int n,k;
        cin>>n>>k;
        if(k==0)
        {
        for(int i=1;i<=n;i++)
        cout<<i<<" ";
        cout<<endl;
        }
        else
        {
            if(n%2==1)
            cout<<"CAPTAIN AMERICA EVADES"<<endl;
            else
            {
                if(k>(n/2))
                cout<<"CAPTAIN AMERICA EVADES"<<endl;
                else
                {
                    if(n%k!=0)
                    cout<<"CAPTAIN AMERICA EVADES"<<endl;
                    else if((n/k)%2==1)
                    cout<<"CAPTAIN AMERICA EVADES"<<endl;
                    else
                    {
                    int temp=n/k;
                    temp/=2;
                    int i=1,c=k;
                    while(temp--)
                    {
                    for(int ii=i;ii<=c;ii++)
                    cout<<ii+k<<" ";
                    for(int ii=c+1;ii<=k+c;ii++)
                    cout<<ii-k<<" ";
                    i+=2*k;
                    c=i+k-1;
                    }
                    cout<<endl;
                    }
                }
            }
        }
        
    }
    return 0;
}  
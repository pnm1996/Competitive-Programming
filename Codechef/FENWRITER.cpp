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
        ll n,cl1=0,cl2=0,cl3=0,cl,tot=0,k=0;
        int flag=0;
        string l1,l2,l3;
        cin>>l1>>l2>>l3>>n;
        for(char x : l1)
        if(x=='1')
        tot++;
        for(char x : l2)
        if(x=='1')
        k++;
        tot+=(k*n);
        for(char x : l3)
        if(x=='1')
        tot++;
        for(int i=l3.length()-1;i>=0;i--)
        {
            if(l3[i]=='1')
            cl3++;
            else
            {
            flag=1;
            break;
            }
        }
        if(flag!=1)
        {
        for(int i=l2.length()-1;i>=0;i--)
        {
            if(l2[i]=='1')
            cl2++;
            else
            {
            flag=1;
            break;
            }
        }
        if(flag!=1)
        {
            cl2=cl2*n;
        for(int i=l1.length()-1;i>=0;i--)
        {
            if(l1[i]=='1')
            cl1++;
            else
            break;
        }
        }
        }
        cl=cl1+cl2+cl3;
        cout<<tot-cl+1<<endl;
    }
    return 0;
} 
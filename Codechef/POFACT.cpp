#include<iostream>
#define MOD 1589540031
#define ull unsigned long long
using namespace std;
int main()
{
int t,n;
ull fact[100001];
fact[1]=1;
for(int i=2;i<=100000;i++)
{
fact[i]=(fact[i-1]*i)%MOD;
}
cin>>t;
while(t--)
{
cin>>n;
cout<<fact[n]<<endl;
}
return 0;
}   
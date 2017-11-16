#include <bits/stdc++.h>
#define ll long long
#define MOD 1000000007
#define mp make_pair
#define pb push_back
#define ff first
#define ss second
using namespace std;
vector<int> v;
bool jag(int n)
{
	int temp=n;
	unsigned int i;
	while(temp)
	{
		v.pb(temp%10);
		temp/=10;
	}
	reverse(v.begin(),v.end());
	vector<bool> b(v.size());
	for(i=1;i<v.size();i++) // same
	{
		if(v[i]==v[i-1])
		{
			return false;
		}
	}
	if(v[1]>v[0])
	{
		b[0]=true;
		b[1]=false;
	}
	else 
	{
		b[0]=false;
		b[1]=true;
	}
	for(i=2;i<v.size();i++)
	{
		if(v[i]>v[i-1])
		b[i]=false;
		else
		b[i]=true;
	}
	for(i=1;i<v.size();i++)
	{
		if(b[i]==b[i-1])
		return false;
	}
	if(v[0]%2==0 or v[v.size()-1]%2==0)
	return true;
	int c=0;
	for(i=1;i<v.size()-1;i++)
	{
		if(v[i]%2==0)
		c++;
	}
	if(c>=2)
	return true;
	return false;
}
int main()
{
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int n;
	cin>>n;
	while(1)
	{
		if(jag(n))
		{
			cout<<n<<endl;
			break;
		}
		n--;
	}
    return 0;
}
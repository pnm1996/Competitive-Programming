#include <iostream>
#include <cmath>
#define ull unsigned long long
#define MOD 1000000007
using namespace std;
ull power(ull base,ull expo)
{
    ull result=1;
    while(expo)
    {
        if(expo & 1)
        result=(result*base)%MOD;
        base=(base*base)%MOD;
        expo=expo/2;
    }
    return result;
}
int main() 
{
    int t;
    cin>>t;
    while(t--)
    {
        ull n,k;
        cin>>n>>k;
        ull max1=k;
       /* if(n==1 && k==1)   -> for 0 power 0 but it is already returning 1.
        cout<<"1"<<endl; */
        if(n!=1)
        max1=max1*power(k-1,n-1);
        cout<<max1%MOD<<endl;  
    }
	return 0;
} 
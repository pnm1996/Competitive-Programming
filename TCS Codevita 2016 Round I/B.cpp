#include <cstdio>
#define ll long long
using namespace std;
int main() 
{
        ll n,k,i,j,s=0,maxi=0,max;
	    scanf("%lld %lld",&n,&k);
	    ll a[n],b[n],c[n];
	    for(i=0;i<=n-1;i++)
	    {
	    scanf("%lld",&a[i]);
	    c[i]=a[i];
	    }
	    for(i=0;i<=n-1;i++)
	    scanf("%lld",&b[i]);
	    if(k!=0)
	    {
	        for(i=0;i<=n-1;i++)
	        {
	            if(b[i]>0)
	            c[i]=c[i]-2*k;
	            else if(b[i]<0)
	            c[i]=c[i]+2*k;
	        }
	    max=(c[0]*b[0])-(a[0]*b[0]);
	    maxi=0;
	    for(i=1;i<=n-1;i++)
	    {
	        if(max > (c[i]*b[i])-(a[i]*b[i]))
	        {
	            max=(c[i]*b[i])-(a[i]*b[i]);
	            maxi=i;
	        }
	    }
	    a[maxi]=c[maxi];
	    }
        s=0;	   
	    for(i=0;i<=n-1;i++)
	    s=s+(a[i]*b[i]);
	    printf("%lld\n",s);
	return 0;
}
        
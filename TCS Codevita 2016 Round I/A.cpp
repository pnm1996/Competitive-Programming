#include <bits/stdc++.h>
using namespace std;
int main() 
{
	int k=22,a[200];
	a[0]=6;
	for(int i=1;i<=105;i++)
	{
	    a[i]=a[i-1]+k;
	    k+=16;
	}
	set <int> s;
	s.insert(1);
	s.insert(3);
	s.insert(6);
	s.insert(10);
	s.insert(15);
	s.insert(21);
	s.insert(28);
	s.insert(36);
	s.insert(45);
	s.insert(55);
	s.insert(66);
	s.insert(78);
	s.insert(91);
	s.insert(105);
	int n;
	k=1;
	scanf("%d",&n);
	for(int i=0;i<(n*(n+1))/2;i++)
	{
	    if(a[i]>=10000)
	    printf("%d ",a[i]);
	    else if(a[i]>=1000)
	    printf("0%d ",a[i]);
	    else if(a[i]>=100)
	    printf("00%d ",a[i]);
	    else if(a[i]>=10)
	    printf("000%d ",a[i]);
	    else
	    printf("0000%d ",a[i]);
	    if(s.find(k)!=s.end())
	    printf("\n");
	    k++;
	}
	return 0;
}
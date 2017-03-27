#include <bits/stdc++.h>
using namespace std;
int main() 
{
	int n;
	scanf("%d",&n);
	map<string,int> m1,m2;
	for(int i=0;i<n;i++)
	{
	    string a,str1,str2;
	    cin>>a;
	    str1=a.substr(a.length()-2);
	    str2=a.substr(0,a.length()-2);
	    if(str1=="ka")
	    m1[str2]++;
	    else if(str1=="ki")
	    m2[str2]++;
	}
	int c=0;
	for(auto it=m1.begin();it!=m1.end();++it)
	{
//	  cout<<it->first<<" "<<it->second<<endl; 
      c+=min(m1[it->first],m2[it->first]);
	}
	printf("%d",c);
	return 0;
}
 
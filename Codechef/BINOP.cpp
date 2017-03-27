#include <iostream>
#include <algorithm>
using namespace std;
int main() 
{
    int t;
    cin>>t;
    while(t--)
    {
        string a,b;
        int c1=0,c2=0;
        cin>>a>>b;
        for(int i=0;i<a.length();i++)
        {
            if(a[i]=='1')
            c1++;
            else
            c2++;
        }
        if(c1==a.length() || c2==a.length())
       {  
        cout<<"Unlucky Chef"<<endl;
        continue;
       }
       int flag1=0,flag2=0;
       for(int i=0;i<a.length();i++)
       {
           if(a[i]!=b[i])
           {
               if(a[i]=='1' && b[i]=='0')
               flag1++;
               else
               flag2++;
           }
        }
       cout<<"Lucky Chef\n"<<max(flag1,flag2)<<endl;
    }
	return 0;
}  
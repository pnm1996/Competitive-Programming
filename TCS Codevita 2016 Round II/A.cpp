#include <bits/stdc++.h>
using namespace std;
int main() 
{
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	string a;
	getline(cin,a);
	if(a=="E")
	{
	    string enc,ans,u;
	    getline(cin,enc);
	    //cout<<enc;
	    cin>>u;
	    cout<<u.length()<<"-"<<u<<"-";
	    for(int i=0;i<enc.length();i++)
         {
        char hexa[100];
         int k=0;
        long int quotient=enc[i],temp;
        while(quotient!=0)
        {
         temp = quotient % 16;
        if( temp < 10)
           temp =temp + 48;
        else
         temp = temp + 55;
         hexa[k++]= temp;
         quotient = quotient / 16;
        }
        for(int j=0;j<=k-1;j++)
         cout<<hexa[j];
        if(i==enc.length()-1)
        break;
        cout<<"-";
        } 
	}
	else
	{
	    int i=0;
	    string dec;
	    getline(cin,dec);
	    for(i=0;dec[i]!='-';i++);
	    i++;
	    while(dec[i]!='-')
	    {
	    cout<<dec[i];
	    i++;
	    }
	    cout<<endl;
	    i++;
	  //  cout<<i;
	    while(i<dec.length())
	    {
	    int jj;
	    char hexaa[10],hex1[10];
	     for(jj=0;dec[i]!='-';i++,jj++)
	     {
	      if(i==dec.length())
	      break;
          hexaa[jj]=dec[i];
	     }
        int mm=0;
	    for(int kk=jj-1;kk>=0;kk--,mm++)
	    hex1[mm]=hexaa[kk];
	    unsigned int ans;
	    stringstream ss;
        ss<<hex<<hex1;
        ss>>ans;
        cout<<(char)ans;
	    i++;
	    }  
	}
	return 0;
}
#include <iostream>
#include <cstring>
using namespace std;
int main()
{
 char l1[1000000],l2[1000000];
 long int t,c=0,i=0,k=0,j,a=0,b=0;
 cin>>t;
 while(t--)
 {
  j=1;
  cin>>l1;
  cin>>l2;
  while(l1[i]!='\0')
   {
       if(l1[i] == '#' && l2[i] == '#')
        {
         cout<<"No"<<endl;
         goto abc;
        }
       if(l1[i]=='.' && l2[i]=='.')
        {
          if(i==0)
          {
            while(l1[i++]!='#')
            a++;
            i=0;
            while(l2[i++]!='#')
            b++;
            i=0;
            if(a>=b)
            {
              j=1;
              i++;
            }
            else
            {
             k=1;
             j=0;
             i++;
            }
           a=0;
           b=0;
          }
          else
          i++;
        }
       else if(l1[i]=='.' && l2[i]=='#')
        {
          if(k==1 && j!=1)
          {
           j=1;
           c++;
           i++;
          }
          else
           i++;
        }
       else if(l1[i]=='#' && i!=0)
        {
          if(k!=1 || j==1)
          {
          c++;
          i++;
          k=1;
          j=0;
          }
          else
          i++;
        }
       else
          {
          k=1;
          j=0;
          i++;
          }
   }
  cout<<"Yes"<<endl;
  cout<<c<<endl;
  abc:
  i=0;
  c=0;
  k=0;
 }
  return 0;
} 
#include<bits/stdc++.h>
#define ull unsigned long long
using namespace std;
int main()
{
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    ull n;
    set <int> s;
    int p;
    char f;
    int x;
    cin>>n;
    cin>>f;
    cin>>p;
    if(f>=65)
    x=f-'A'+10;
    else
    x=f-'0';
   // cout<<x<<endl;
    for(int a=x+1;a<=36;a++)
      {
     //  cout<<a<<" ";
        char hexa[100];
        int k=0;
        ull quotient=n,temp;
        int c=0;
        while(quotient)
        {
            if(c==p+1)
            break;
         temp=quotient%a;
        if(temp<10)
           temp=temp+48;
        else
         temp=temp+55;
         hexa[k++]=temp;
         quotient=quotient/a;
         c++;
        } 
        if(f==hexa[p])
        s.insert(a);
      }
     //  cout<<endl;
    //  cout<<c<<endl;
       for(auto it : s)
       cout<<it<<" ";
    return 0;
}
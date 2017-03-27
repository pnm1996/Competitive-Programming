#include <bits/stdc++.h>
using namespace std;
int ans=0;
int comp(int c1[],int k)
{
    int c=0,low=500,l=0;
    if(k<=3)
    return ans;
    else
    {
        for(int i=1;i<7;i++)
        if(c1[i]!=0)
        low=min(low,c1[i]);
        if(k==4)
        ans+=low;
        else if(k==5)
        ans+=(low*2);
        else
        ans+=(low*4);
        for(int i=1;i<7;i++)
        {
            if(c1[i]!=0)
            c1[i]-=low;
            if(c1[i]!=0)
            l++;
        }
        return comp(c1,l);
    }
}
int main()
{
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int t;
    cin>>t;
    while(t--)
    {
       int n;
       cin>>n;
       int c[n],type[n][110];
       for(int i=0;i<n;i++)
       {
       cin>>c[i];
       for(int j=0;j<c[i];j++)
       cin>>type[i][j];
       }
       for(int i=0;i<n;i++)
       {
           int count[7]={0},k=0;
           for(int j=0;j<c[i];j++)
           count[type[i][j]]++;
           for(int j=1;j<7;j++)
           if(count[j]!=0)
           k++;
           comp(count,k);
           c[i]+=ans;
           ans=0;
       }
       int fin=0;
       int max=c[0];
       int maxi=0;
       for(int i=1;i<n;i++)
       {
           if(c[i]>max)
           {
               max=c[i];
               maxi=i;
           }
       }
       for(int i=0;i<n;i++)
       {
           if(i==maxi)
           continue;
           else if(c[i]==max)
           {
           fin=1;
           break;
           }
       }
       if(fin)
       cout<<"tie"<<"\n";
       else if(maxi==0)
       cout<<"chef"<<"\n";
       else
       cout<<maxi+1<<"\n";
    }
    return 0;
}  
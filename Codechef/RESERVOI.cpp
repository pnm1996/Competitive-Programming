#include <bits/stdc++.h>
#define ll long long
#define MOD 1000000007
#define mp make_pair
#define pb push_back
using namespace std;
int main()
{
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int t;
    cin>>t;
    while(t--)
    {
        int n,m;
        cin>>n>>m;
        char a;
        char mat[n+10][m+10];
        for(int i=0;i<n+10;i++)
        {
            for(int j=0;j<m+10;j++)
            mat[i][j]=0;
        }
        for(int i=1;i<=n;i++)
        {
            for(int j=0;j<m;j++)
            {
                cin>>a;
                mat[i][j+1]=a;
            }
        }
        int flag=0;
        for(int i=1;i<=n;i++)
        {
            if(mat[i][1]=='W' or mat[m][i]=='W')
            flag=1;
        }
        for(int i=1;i<=m;i++)
        {
            if(mat[n][i]=='W')
            flag=1;
        }
        if(flag==0)
        {
       for(int i=1;i<=n;i++)
       {
           for(int j=1;j<=m;j++)
           {
               char curr=mat[i][j];
               if(curr!='B')
               {
               char top=mat[i-1][j];
               char down=mat[i+1][j];
               char left=mat[i][j-1];
               char right=mat[i][j+1];
               if(curr=='A')
               {
                   if(top=='B' or top=='W' or left=='W' or right=='W')
                   flag=1;
               }
               }
           }
       }
        }
        puts(flag==0?"yes":"no");
    }
    return 0;
} 
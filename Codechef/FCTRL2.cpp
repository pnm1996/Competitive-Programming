#include <iostream>
using namespace std;
int main()
{
    int a[200],t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        a[0]=1;
        int temp=0;
        int i,j,x;
        int m=1;
        for(i=1;i<=n;i++)
        {
            for(j=0;j<m;j++)
            {
                x=a[j]*i+temp;
                a[j]=x%10;
                temp=x/10;
            }
            while(temp>0)
            {
                a[m]=temp%10;
                temp=temp/10;
                m++;
            }
        }
        for(j=m-1;j>=0;j--)
        cout<<a[j];
        cout<<"\n";
    }
    return 0;
} 
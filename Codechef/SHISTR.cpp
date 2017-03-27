#include <iostream>
#include <string>
using namespace std;
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int l,r,k,q,i,n,a[5005]={0};
        cin>>n;
        cin>>q;
        string code;
        cin>>code;
        while(q--)
        {
            int l,r,k;
            cin>>l>>r>>k;
            //k=k%26;
            a[l-1]+=k;
            a[r]-=k;
        }
        a[0]%=26;
        for(i=1;i<n;i++)
     {
        a[i]+=a[i-1];
        a[i]%=26;
    }
            for(i=0;i<n;i++)
            {
                if(code[i]+a[i] <= 'z' && code[i]+a[i] >='a')
                code[i]=code[i]+a[i];
                else if(code[i]+a[i] > 'z')
                code[i]='a'+((code[i]+a[i])-'z')-1;
                else
                code[i]='z'+((code[i]+a[i])-'a')+1;
            }
         //  cout<<code<<endl;
        cout<<code<<endl;
    }
}  
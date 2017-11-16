    #include <bits/stdc++.h>
    #define ll long long
    #define MOD 1000000007
    #define mp make_pair
    #define pb push_back
    using namespace std;
    int main()
    {
        ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
           int n,k,p;
           cin>>n>>k>>p;
           int a[n],ans[n];
           deque<int> q;
           multiset<int,greater<int>> s;
           for(int i=0;i<n;i++)
           cin>>a[i];
           int flag=0,ones=0;
           for(int i=0;i<n;i++)
           {
               if(a[i]==1)
               {
               flag=1;
               ones++;
               }
           }
           if(flag==0)
           {
               for(int i=0;i<n;i++)
               ans[i]=0;
           }
           else if(k>=n)
           {
               for(int i=0;i<n;i++)
               ans[i]=ones;
           }
           else
           {
               int one=0;
               for(int i=0;i<k;i++)
               {
                   if(a[i]==1)
                   one++;
               }
               q.pb(one);
               s.insert(one);
               int head=k,tail=0;
               for(int i=k;i<n;i++)
               {
                   if(a[tail]==1)
                   one--;
                   if(a[head]==1)
                   one++;
                   tail++; head++;
                   q.pb(one);
                   s.insert(one);
               }
            /*   for(int i=0;i<n-k+1;i++)
               cout<<q.at(i)<<" ";
               cout<<endl; */
               ans[0]=*s.begin();
               int left=k-1,right=n-1;
               one=0;
               for(int i=0;i<k;i++)
               {
                   if(a[i]==1)
                   one++;
               }
               for(int i=1;i<n;i++)
               {
                 //  cout<<left<<" "<<right<<endl;
                /*   for(int j=0;j<n-k+1;j++)
                    cout<<q.at(j)<<" ";
                    cout<<endl;  */
                   if(a[left]==1)
                   one--;
                   if(a[right]==1)
                   one++;
                   s.erase(s.find(q.back()));
                   q.pop_back();
                   q.push_front(one);
                   s.insert(one);
                   ans[i]=*s.begin();
                   if(left==0)
                   left=n-1;
                   else
                   left--;
                   right--;
               }
           }
       /*    for(int i=0;i<n;i++)
           cout<<ans[i]<<" ";
           cout<<endl; */
               int z=0;
               while(p--)
               {
                   char c;
                   cin>>c;
                   if(c=='?')
                   {
                       cout<<ans[z]<<endl;
                   }
                   else
                   {
                       z++;
                       if(z==n)
                       z=0;
                   }
               }
        return 0;
    }   
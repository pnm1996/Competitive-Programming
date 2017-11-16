    #include <bits/stdc++.h>
    #define ll long long
    #define MOD 1000000007
    #define mp make_pair
    #define pb push_back
    #define ff first
    #define ss second
    using namespace std;
    bool kaunsa(int a,int b,int x,int y)
    {
        int p=ceil(1.0*a/x-1);
        int q=ceil(1.0*b/y-1);
        if(p>=q)
        return true;
        return false;
    }
    int main()
    {
        ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
        int t;
        cin>>t;
        while(t--)
        {
           string s;
           cin>>s;
           int x,y,a=0,b=0;
           cin>>x>>y;
           for(char x : s)
           if(x=='a')
           a++;
           else
           b++;
           int da=ceil(1.0*a/x)-1;
           int db=ceil(1.0*b/y)-1;
     //    cout<<da<<" "<<db<<endl;
           if(da<=0 and db<=0)
           cout<<s;
           else if(da<=0)
           {
               while(a>0)
               {
                for(int i=1;i<=min(b,y);i++)
                cout<<"b";
                b-=y;
                cout<<"a";
                a--;
               }
               while(b>0)
               {
                   for(int i=1;i<=min(b,y);i++)
                   cout<<"b";
                   b-=y;
                   if(b<=0)
                   break;
                   cout<<"*";
               }
           }
           else if(db<=0)
           {
               while(b>0)
               {
                for(int i=1;i<=min(a,x);i++)
                cout<<"a";
                a-=x;
                cout<<"b";
                b--;
               }
               while(a>0)
               {
                   for(int i=1;i<=min(a,x);i++)
                   cout<<"a";
                   a-=x;
                   if(a<=0)
                   break;
                   cout<<"*";
               }
           }
           else
           {
                bool hoja=false;
                if(kaunsa(a,b,x,y))
                hoja=true;
                int hua=0;
                while(1)
                {
                    if(a<=0 or b<=0)
                    break;
                if(hoja)
                {
                    if(hua==2)
                    {
                        for(int i=1;i<=x-1;i++)
                        {   
                            if(a==0)
                            break;
                            cout<<"a"; 
                            a--;
                        }
                    }
                    else
                    {
                    for(int i=1;i<=x;i++)
                    {
                        if(a==0)
                        break;
                        cout<<"a";
                        a--;
                    }
                    }
                    if(b>0)
                    {
                        cout<<"b";
                        b--;
                        hua=1;
                    }
                    hoja=kaunsa(a,b,x,y);
                }       
                else
                {
                    if(hua==1)
                    {
                        for(int i=1;i<=y-1;i++)
                        {
                        if(b==0)
                        break;
                        cout<<"b";
                        b--;
                        }
                    }
                    else
                    {
                        for(int i=1;i<=y;i++)
                        {
                        if(b==0)
                        break;
                        cout<<"b";
                        b--;
                        }
                    }
                    if(a>0)
                    {
                        cout<<"a";
                        a--;
                        hua=2;
                    }
                    hoja=kaunsa(a,b,x,y);
                }
                }
                if(a<=0 and b<=0)
                goto abc;
                if(a<=0)
                {
                    while(b>0)
                    {
                        if(hua==1)
                        {
                            for(int i=1;i<=y-1;i++)
                            {
                                if(b==0)
                                break;
                                cout<<"b";
                                b--;
                                hua=0;
                            }
                        if(b==0)
                        break;
                        cout<<"*";
                        }
                        else
                        {
                        for(int i=1;i<=y;i++)
                        {
                            if(b==0)
                            break;
                            cout<<"b";
                            b--;
                        }
                        if(b==0)
                        break;
                        cout<<"*";
                        }
                    }
                }
                else if(b<=0)
                {
                    while(a>0)
                    {
                        if(hua==2)
                        {
                            for(int i=1;i<=x-1;i++)
                            {
                                if(a==0)
                                break;
                                cout<<"a";
                                a--;
                                hua=0;
                            }
                        if(a==0)
                        break;
                        cout<<"*";
                        }
                        else
                        {
                        for(int i=1;i<=x;i++)
                        {
                            if(a==0)
                            break;
                            cout<<"a";
                            a--;
                        }
                        if(a==0)
                        break;
                        cout<<"*";
                        }
                    }
                }
           } 
           abc:
           cout<<endl;
        }
        return 0;
    } 
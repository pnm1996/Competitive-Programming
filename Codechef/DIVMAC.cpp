#include <bits/stdc++.h>
#define ll long long
#define MOD 1000000007
#define mp make_pair
#define pb push_back
#define N 100005
using namespace std;
int a[N],lpd[N*10]={0};
int tree[4*N];
void sieve()
{
    lpd[0]=0; lpd[1]=1;
    for(int i=2;i*i<N*10;i++)
    if(lpd[i]==0)
    {
        lpd[i]=i;
        for(int j=i*i;j<N*10;j+=i)
        if(!lpd[j])
        lpd[j]=i;
    }
    for(int i=2;i<N*10;i++)
    if(lpd[i]==0)
    lpd[i]=i;
}
void build(int node,int start,int end)
{
    if(start>end)
    return;
    if(start==end)
    {
        tree[node]=lpd[a[start]];
    }
    else
    {
        int mid=(start+end)/2;
        build(2*node,start,mid);
        build(2*node+1,mid+1,end);
        tree[node]=max(tree[2*node],tree[2*node+1]);
    }
}
void update(int node,int start,int end,int l,int r)
{
    if(start>end or start>r or end<l)
    return;
    if(tree[node]==1)
    return;
    if(start==end)
    {
    tree[node]=lpd[a[start]/lpd[a[start]]];
    a[start]=a[start]/lpd[a[start]];
    }
    else
    {
        int mid=(start+end)/2;
        update(2*node,start,mid,l,r);
        update(2*node+1,mid+1,end,l,r);
        tree[node]=max(tree[2*node],tree[2*node+1]);
    }
}
int query(int node,int start,int end,int l,int r)
{
    if(start>end or start>r or end<l)
    return 0;
    if(tree[node]==1)
    return 1;
    if(start>=l and end<=r)
    return tree[node];
    int mid=(start+end)/2;
    int p1=query(2*node,start,mid,l,r);
    int p2=query(2*node+1,mid+1,end,l,r);
    return max(p1,p2);
}
int main()
{
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    sieve();
    int t;
    cin>>t;
    while(t--)
    {
        int n,m;
        cin>>n>>m;
        for(int i=0;i<n;i++)
        cin>>a[i];
        build(1,0,n-1);
        while(m--)
        {
            int type,l,r,ans=1;
            cin>>type>>l>>r;
            if(type==0)
            {
            update(1,0,n-1,l-1,r-1);
            }
            else
            {
              cout<<max(ans,query(1,0,n-1,l-1,r-1))<<" ";
            }
        }
        cout<<endl;
    }
    return 0;
} 
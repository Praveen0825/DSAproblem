#include<bits/stdc++.h>
using namespace std;
#define lli long long int
#define pb push_back
bool vis[100001];
lli child[100001];
lli cnt[100001];
bool flag[100001];//flag[i]=true means from i we can reach to node n  
vector<lli> v[100001];
lli dfs(lli node)
{
    vis[node]=true;
    for(lli chil:v[node])
    {
        //cout<<chil<<" ";
        if(!vis[chil])
        {
            dfs(chil);
        }
        flag[node]|=flag[chil];
        if((cnt[node]<cnt[chil]+1)&&(flag[chil]==true))
        {
            cnt[node]=cnt[chil]+1;
            child[node]=chil;
        }
    }
    
    return 0;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    lli T;
    T=1;
    while(T--)
    {
        lli n,m,i;
        cin>>n>>m;
        lli x,y;
        for(i=0;i<m;i++)
        {
            cin>>x>>y;
            v[x].pb(y);
        }
        flag[n]=true;
        x=dfs(1);
        /*for(i=1;i<=n;i++)
            cout<<child[i]<<" ";*/
        if(!flag[1]) 
        {
            cout<<"IMPOSSIBLE\n";continue;
        }
        cout<<cnt[1]+1<<"\n";
        cout<<"1 ";
        lli z=1;
        while(child[z]!=n)
        {
            cout<<child[z]<<" ";
            z=child[z];
        }
        cout<<n;
    }
    return 0;
}
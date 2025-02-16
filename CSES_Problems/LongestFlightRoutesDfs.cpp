#include <bits/stdc++.h>

using namespace std;
const int maxN = 1e5+1;

bool vis[maxN];
int N, M, K, a, b, in[maxN], p[maxN], l[maxN], ans[maxN];
vector<int> G[maxN];
queue<int> Q;

void dfs(int u, int par = 0){
    vis[u] = true;
    for(int v : G[u])
        if(v != par && !vis[v])
            dfs(v, u);
}

int main(){
    scanf("%d %d", &N, &M);
    for(int i = 0; i < M; i++){
        scanf("%d %d", &a, &b);
        G[a].push_back(b);
        in[b]++;
    }

    dfs(1);
    if(!vis[N]){
        printf("IMPOSSIBLE\n");
        return 0;
    }

    fill(l+2, l+maxN, -1);
    for(int i = 1; i <= N; i++)
        if(in[i] == 0)
            Q.push(i);

    while(!Q.empty()){
        int u = Q.front(); Q.pop();
        for(int v : G[u]){
            if(l[u] != -1 && l[v] < l[u]+1){
                l[v] = l[u] + 1;
                p[v] = u;
            }
            in[v]--;
            if(in[v] == 0)
                Q.push(v);
        }
    }

    K = l[N] - l[1];
    printf("%d\n", K+1);
    for(int i = K, u = N; i >= 0; i--){
        ans[i] = u;
        u = p[u];
    }
    for(int i = 0; i <= K; i++)
        printf("%d%c", ans[i], (" \n")[i==K]);
}


/*
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
        //for(i=1;i<=n;i++)
         //   cout<<child[i]<<" ";
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
*/
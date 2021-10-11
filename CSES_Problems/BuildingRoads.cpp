#include<bits/stdc++.h>
using namespace std;
vector<int> adj[200005];
vector<int> vis;
void dfs(int s){
    vis[s]=1;
    for(int x:adj[s]){
        if(!vis[x]){
            dfs(x);
        }
    }
}
 
 
int main(){
int n,m;
cin>>n>>m;
vis.resize(n+1,0);
for(int i=0;i<m;i++){
 int u,v;
 cin>>u>>v;
 adj[u].push_back(v);
 adj[v].push_back(u);
}
vector<int> v;
for(int i=1;i<=n;i++)
{
    if(!vis[i]){
        v.push_back(i);
        dfs(i);
       
    }
}
cout<<v.size()-1<<"\n";
for(int i=1;i<v.size();i++){
    cout<<v[i-1]<<" "<<v[i]<<"\n";
}
 
return 0;
}
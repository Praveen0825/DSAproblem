#include<bits/stdc++.h>
using namespace std;
#define SZ 200005
 
int n, m, x,q,u,v,k; 
 
int L[SZ]; 
vector<int> adj[SZ]; 
int jump[21][SZ];
 
void dfs(int u, int p, int l) 
{
    jump[0][u] = p;
    L[u] = l;
	
	for (int v: adj[u]) 
		if(v != p) 
		dfs(v, u, l+1);
}
 
void preprocess_LCA()
{	
	dfs(1, -1, 0);
		
	for (int i = 1; 1<<i <= n ; i++) 
	for (int j = 0; j <= n ; j++)
	jump[i][j] = jump[i-1][jump[i-1][j]];
}
 
int main()
{
    cin >> n >> q;
    for(int i = 2; i <= n; i++) {
        cin >> u;
        adj[u].push_back(i);
        adj[i].push_back(u);
    }    
    preprocess_LCA();
    while(q--) {
        cin >> u >> k;
		int boss = u;
		for(int i=0; i<=20; i++)
		if(k & (1<<i))
		boss = jump[i][boss];
 
        cout << (boss==0 ? -1 : boss) << endl;
    }
}
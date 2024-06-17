#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define F first;
#define PB push_back;
#define MP make_pair;
#define mod 1000000007
int dfs(int node, vector<int>&child, vector<bool>&vis, vector<int>adj[])
{
	vis[node] =1;
	if(adj[node].size()==0)
	return 0;
	for(auto x: adj[node])
	{
		if(!vis[x])
		{
			child[node] += 1+ dfs(x, child, vis, adj);
		}
	}
	
	return child[node];
	
}
int main()
{
	int n;
	cin>>n;
	
	vector<int> adj[n];
	vector<int> child(n, 0);

	for(int i=1;i<n;i++)
	{
		int x;
		cin>>x;
		x--;
		adj[x].push_back(i);
		
	}
	
	vector<bool> vis(n, 0);
	for(int i=0;i<n;i++)
	{
		if(!vis[i])
		dfs(i, child, vis, adj);
	}
	
	for(int i=0;i<n;i++)
	cout<<child[i]<<" ";
}
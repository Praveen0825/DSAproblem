#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
#define int long long int
 
int n, m;
vector<int> degree;
priority_queue<int, vector<int>, greater<int>> noInDeg;
vector<vector<int>> g;
 
int32_t main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n, m;
	cin >> n >> m;
	g.resize(n+1);
	degree.resize(n+1);
 
	for(int i = 0; i < m; ++i)
	{
		int u, v;
		cin >> u >> v;
		g[u].push_back(v);
		++degree[v];
	}
 
	for(int i = 1; i <= n; ++i)
	{
		if(!degree[i])
			noInDeg.push(i);
	}
	
	vector<int> ans;
	while(!noInDeg.empty())
	{
		int u = noInDeg.top();
		noInDeg.pop();
		ans.push_back(u);
		for(auto v: g[u])
		{
			--degree[v];
			if(!degree[v]) noInDeg.push(v);
		}
	}
 
	if(ans.size() != n)
	{
		cout << "IMPOSSIBLE";
	}
	else
	{
		for(auto u: ans)
			cout << u << " ";
	}
}
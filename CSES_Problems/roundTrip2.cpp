
#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
#define int long long int
 
int n, m;
vector<set<int>> g;
 
vector<int> vis;
 
stack<int> recursionStack;
 
vector<bool> rsFlag;
 
bool dfs(int u)
{
	vis[u] = true;
	recursionStack.push(u);
	rsFlag[u] = true;
	for(auto v: g[u])
	{
		if(!vis[v])
			if(dfs(v))
				return true;
 
		if(rsFlag[v])
		{
			recursionStack.push(v);
			return true;
			//no more dfs;
		}
	}
	recursionStack.pop();
	rsFlag[u] = false;
	return false;
	//no cycle was detected
}
 
 
void visit_all()
{
	for(int u = 1; u <= n; ++u)
	{
		if(!vis[u])
		{
			if(dfs(u))
				break;
		}
	}
}
 
int32_t main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n >> m;
	g.resize(n+1);
	vis.resize(n+1);
	rsFlag.resize(n+1);
	for(int i = 0; i < m; ++i)
	{
		int u, v;
		cin >> u >> v;
		g[u].insert(v);
	}
	visit_all();
	if(recursionStack.empty())
	{		
		cout << "IMPOSSIBLE" << endl;
		return 0;
	}
 
	vector<int> ans;
	int temp = recursionStack.top();
	while(!recursionStack.empty())
	{
		ans.push_back(recursionStack.top());
		recursionStack.pop();
		if(ans.back() == temp and ans.size() != 1)
			break;
	}
	reverse(ans.begin(), ans.end());
	cout << ans.size() << endl;
	for(auto u: ans)
	{
		cout << u << " ";
	}
 
 
}


/*#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>

using std::cout;
using std::endl;
using std::vector;

int main() {
	int n, m;
	std::cin >> n >> m;

	vector<vector<int>> graph(n);
	for (int i = 0; i < m; i++) {
		int a, b;
		std::cin >> a >> b;
		graph[a - 1].push_back(b - 1);
	}

	vector<int> in_degree(n);
	for (const vector<int> &nodes : graph) {
		for (int node : nodes) { in_degree[node]++; }
	}

	std::queue<int> queue;
	for (int i = 0; i < n; i++) {
		if (in_degree[i] == 0) { queue.push(i); }
	}
	vector<int> top_sort;
	while (!queue.empty()) {
		int curr = queue.front();
		queue.pop();
		top_sort.push_back(curr);
		for (int next : graph[curr]) {
			if (--in_degree[next] == 0) { queue.push(next); }
		}
	}

	if (top_sort.size() != n) {
		for (int i = 0; i < top_sort.size()-1; i++) { cout << top_sort[i] + 1 << ' '; }
		cout << top_sort.back() + 1 << endl;
	} else {
		cout << "IMPOSSIBLE" << endl;
	}
}
*/
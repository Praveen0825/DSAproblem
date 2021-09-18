#include<bits/stdc++.h>
using namespace std;


int Find(int node, int parent[])
{
	if(node == parent[node])
	return node;
	
	return parent[node] = Find(parent[node], parent);
}

void Union(int u, int v, int parent[], vector<int>& rank)
{
	u = Find(u, parent);
	v = Find(v, parent);
	if(u==v)
	return;
	
	if(rank[u]>rank[v])
	{
		parent[v] = u;
	} 
	else if(rank[v]>rank[u])
	{
		parent[u] = v;
	}
	else
	{
		parent[v] = u;
		rank[u]++;
	}
}
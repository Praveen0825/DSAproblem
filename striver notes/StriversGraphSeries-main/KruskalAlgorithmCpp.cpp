#include<bits/stdc++.h>
using namespace std;
#define ll long long
struct node {
    ll u;
    ll v;
    ll wt; 
    node(ll first, ll second, ll weight) {
        u = first;
        v = second;
        wt = weight;
    }
};

bool comp(node a, node b) {
    return a.wt < b.wt; 
}

ll findPar(ll u, vector<ll> &parent) {
    if(u == parent[u]) return u; 
    return parent[u] = findPar(parent[u], parent); 
}

void merge(ll u, ll v, vector<ll> &parent, vector<ll> &rank) {
    u = findPar(u, parent);
    v = findPar(v, parent);
    if(rank[u] < rank[v]) {
    	parent[u] = v;
    }
    else if(rank[v] < rank[u]) {
    	parent[v] = u; 
    }
    else {
    	parent[v] = u;
    	rank[u]++; 
    }
}
int main(){
	ll N,m;
	cin >> N >> m;
	vector<node> edges; 
	for(ll i = 0;i<m;i++) {
	    ll u, v, wt;
	    cin >> u >> v >> wt; 
	    edges.push_back(node(u, v, wt)); 
	}
	sort(edges.begin(), edges.end(), comp); 
	
	vector<ll> parent(N);
	for(ll i = 0;i<N;i++) 
	    parent[i] = i; 
	vector<ll> rank(N, 0); 
	
	ll cost = 0;
	vector<pair<ll,ll>> mst; 
	for(auto it : edges) {
	    if(findPar(it.v, parent) != findPar(it.u, parent)) {
	        cost += it.wt; 
	        mst.push_back({it.u, it.v}); 
	        merge(it.u, it.v, parent, rank); 
	    }
	}
	cout << cost << endl;
	for(auto it : mst) cout << it.first << " - " << it.second << endl; 
	return 0;
}





/*

#include <bits/stdc++.h>
using namespace std;

const int MAX = 1e4+5;
int id[MAX] ,nodes,edges;
pair <long ,pair<int,int> > p[MAX];



void initialize(){
    for(int i=0;i<MAX;i++)
        id[i] = i;
}
int root(int x){
    while(id[x]!=x){
        id[x] = id[id[x]];
        x = id[x];
    }
    return x;
}
void union1(int x,int y){
    int p = root(x);
    int q = root(y);
    id[p] = id[q];
}
long Kruskal(pair <long ,pair<int,int> > p[]){
    int x,y;
    long cost,minimumCost = 0;
    for(int i=0;i<edges;i++){
        x = p[i].second.first;
        y = p[i].second.second;
        cost = p[i].first;
        if(root(x)!=root(y)){
            minimumCost += cost;
            union1(x,y);
        }
    }
    return minimumCost;
}
int main(void){
    int x,y;
    long weight,cost,minimumCost;
    initialize();
    cin>>nodes>>edges;
    for(int i=0;i<edges;i++){
        cin>>x>>y>>weight;
        p[i] = make_pair(weight,make_pair(x,y));
    }
    sort(p,p+edges);
    minimumCost = Kruskal(p);
    cout<<minimumCost<<endl;
    return 0;
}

*/
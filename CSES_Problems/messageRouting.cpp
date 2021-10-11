#include<bits/stdc++.h>
using namespace std;
vector<int> adj[200005];
vector<int> vis;


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
int a;
 vector<int> from(n+1);
queue<int> q;
   q.push(1);
   while(!q.empty()){
   	int p=q.front();
   	q.pop();
   	vis[p]=1;
   	if(p==n)break;
   	for(int aa:adj[p]){
   		if(vis[aa]==0){
   			from[aa]=p;
   			vis[aa]=1;
   			q.push(aa);
   		}
   	}
   }
  
   if(vis[n]==0){
   	cout<<"IMPOSSIBLE"<<endl;
   }
   else{
   	v.push_back(n);
   	a=n;
   	while(a!=1){
   		a=from[a];
   		v.push_back(a);
   	}
   	cout<<v.size()<<endl;
   	for(int i=v.size()-1;i>=0;i--){
   		cout<<v[i]<<" ";
 
   	}
   }

return 0;
}
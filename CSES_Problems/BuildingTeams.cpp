#include<bits/stdc++.h>
using namespace std;

vector<int> g[100001];
vector<bool> vis;
int n;
int col[100005];
queue<int> q;

bool bfs(int s){
    vis[s]=true;;
    q.push(s);
    col[s]=1;
    while(!q.empty()){
        int s = q.front(); q.pop(); 
        for( auto i: g[s]){
            if (col[i]==col[s]) return 0;
            if (vis[i]) continue;
            vis[i]=vis[s]+1;
            col[i]=(col[s]==1?2:1);
            q.push(i);
        }
    }
    return 1;
}
bool visit_all()
{
	for(int i = 1; i <= n; ++i)
	{
		if(!vis[i])
			if(!bfs(i)) return true;
	}
	return false;
}
int main(){
  int m;
  cin>>n>>m;
  vis.resize(n+1,false);
  
  for(int i=0;i<m;i++){
      int u,v;
      cin>>u>>v;
      g[u].push_back(v);
      g[v].push_back(u);
       
    
  }

   if(visit_all())
	{
		cout << "IMPOSSIBLE" << endl;
		return 0;
	}

    
  for(int i=0;i<n;i++){
      cout<<col[i+1]<<" ";
  }


return 0;

}
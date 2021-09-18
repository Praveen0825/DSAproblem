#include<bitset>/stdc++.h>
using namespace std;
#define ll long long
#define ld long double


int main(){
    int t=1;
while(t){ 
int n;
cin>>n;
if(n==0)
break;
string s[n];
unordered_map<string,int> um;
for(int i=0;i<n;i++){
   cin>>s[i];
   um[s[i]]=i;  
}



vector<vector<ld>> dist(n,vector<ld>(n,INT_MAX));

for(int i=0;i<n;i++)
dist[i][i]=1;

int m;
cin>>m;
for(int i=0;i<m;i++){
   string u,v;
   ld wt;
   cin>>u>>wt>>v;
   dist[um[u]][um[v]]=wt;
}


	//Find all pairs shortest path by trying all possible paths
	for(int k=0;k<n;++k)	//Try all intermediate nodes
		for(int i=0;i<n;++i)	//Try for all possible starting position
			for(int j=0;j<n;++j)	//Try for all possible ending position
			{
				if(dist[i][k]==INT_MAX || dist[k][j]==INT_MAX)	//SKIP if K is unreachable from i or j is unreachable from k
					continue;
				else if(dist[i][k]*dist[k][j] < dist[i][j])		//Check if new distance is shorter via vertex K
					dist[i][j] = dist[i][k] * dist[k][j];
			}

	  //Check for negative edge weight cycle
      bool f=0;
	for(int i=0;i<n;++i)
		if(dist[i][i] < 1)
		{
			f=1;
			return;
		}  
        cout << "Case #" << t << ": ";
        if(f)
        cout<<"YES\n";
        else
        cout<<"NO\n";

        t++;
}

}
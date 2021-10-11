#include<bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define pb push_back
#define vii vector<pair<int,int>>
int dx[]={0,0,1,-1};
 int dy[]={1,-1,0,0};
 string ds="RLDU";
 
 int n,m; 
 bool possible(int x,int y){
 	//cout<<n<<" "<<m<<" "<<x<<" "<<y<<" possible"<<endl;
 
     return (x<n&&x>=0&&y<m&&y>=0);
 }

 int main(){
   cin>>n>>m;
   vector<vector<int>> vis(n+1,vector<int>(m+1,-1));
   vector<vector<int>> grid(n,vector<int>(m));
   int a,b,c,d;
   for(int i=0;i<n;i++){
       for(int j=0;j<m;j++){
           char ch;
           cin>>ch;
           if(ch=='#')
           grid[i][j]=0;
           else if(ch=='.')
           grid[i][j]=1;
           else if(ch=='A')
           {
          a=i,b=j;
          grid[i][j]=1;
           }
           else 
           { grid[i][j]=3;
               c=i,d=j;}
       }
   }
    queue<pair<int,int>> q;
  q.push({a,b});
  vii from[n+1][m+1];
  from[a][b].pb({0,0});
  char ch[n+1][m+1];
  
  while(!q.empty()){
  	pair<int,int> p=q.front();
  	int x=p.fi;
  	int y=p.se;
 
  //	cout<<from[x][y][0].x<<" "<<from[x][y][0].y<<" "<<x<<" "<<y<<" : ";
  	q.pop();
  	vis[x][y]=1;
  	if(grid[x][y]==3)break;
  	for(int i=0;i<4;i++){
		int nx=x+dx[i],ny=y+dy[i];
		//cout<<x<<" "<<dx[i]<<","<<y<<" "<<dy[i]<<endl;
		if(!possible(nx,ny))continue;
		
 
		if(grid[nx][ny]==0||vis[nx][ny]!=-1)continue;
		//cout<<"("<<nx<<","<<ny<<") ";
		vis[nx][ny]=1;
		q.push({nx,ny});
		from[nx][ny].pb(p);
		ch[nx][ny]=ds[i];
	}
	//cout<<endl;
  }
  if(vis[c][d]==-1){
  	cout<<"NO"<<endl;
  	return 0;
  }
  else{
      string s="";
  	cout<<"YES"<<endl;
  	pair<int,int> p={c,d};
  	while(p.fi!=a||p.se!=b){
  		s+=ch[p.fi][p.se];
  		p=from[p.fi][p.se][0];
  	}
  	reverse(s.begin(),s.end());
  	cout<<s.size()<<endl;
  	cout<<s<<endl;
  }

     return 0;
 }
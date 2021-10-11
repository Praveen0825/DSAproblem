/*#include<bits/stdc++.h>
using namespace std;

int fx[] = {-1, 1, 0, 0};
int fy[] = {0, 0, 1, -1};
char go[] = {'U', 'D', 'R', 'L'};
int nex[1005][1005];
int main(){
    int n,m; cin>>n>>m;
    vector<string> grid(n);
    for (auto &i: grid)
        cin>>i;
    queue<pair<int,int>> q;
    int x,y;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            if (grid[i][j] == 'M')
                q.push({i,j});
            else if (grid[i][j] == 'A')
                x = i, y = j;
    q.push({x,y});
    nex[x][y] = -1;
    //reduce distances from all monsters and then human
    while(!q.empty()) {
        int x = q.front().first;
        int y= q.front().second;
        q.pop();
        if (grid[x][y] == 'A' && (x == 0 || x == n-1 || y == 0 || y == m-1)) {
            cout<<"YES"<<endl;
            string ans;
            int d = nex[x][y];
            while(d != -1) {
                ans += go[d];
                x -= fx[d];
                y -= fy[d];
                d = nex[x][y];
            }
            reverse(ans.begin(), ans.end());
            cout<<ans.size()<<endl;
            cout<<ans;
            return 0;
        }
        for (int i = 0; i < 4; i++) {
            int xx = x + fx[i], 
            yy = y + fy[i];
            if (xx<0 || xx>=n || yy<0 || yy>=m || grid[xx][yy] != '.' ) continue;
            else {
                grid[xx][yy] = grid[x][y];
                if (grid[xx][yy] == 'A') nex[xx][yy] = i;
                q.push({xx,yy});
            }
        }
    }
    cout<<"NO";
    return 0;
}   
*/

#include<bits/stdc++.h>
using namespace std;

#define fo(i,a,b) for(int i=a;i<b;i++)
#define vii vector<int,int>
#define pii pair<int,int>
#define x first
#define y second

const int N=1001;
int grid[N][N];
string maze[N];
int vis[N][N];
signed main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int i,j,x;
    cin>>n>>m;
 	string s;
 	vii mon;
 	int ax,ay;
 	fo(i,0,n){
 		cin>>s;
 		fo(j,0,m){
 			maze[i]=s;
 			if(s[j]=='A'){
 				ax=i;
 				ay=j;
 			}
 			if(s[j]=='M'){
 				mon.pb({i,j});
 			}
 		}
 	}
 	queue<pair<int,pii>> q;
 	_init(vis);
 
 	fo(i,0,mon.size()){
 		q.push({0,{mon[i].x,mon[i].y}});
 		vis[mon[i].x][mon[i].y]=1;
 	}
_init(grid);
 	while(q.size()>0){
 		pii p=q.front().y;
 		int lvl=q.front().x;
 		q.pop();
 		grid[p.x][p.y]=lvl;
 		fo(i,0,4){
 			int nx=p.x+dx[i],ny=p.y+dy[i];
 			if(!possible(nx,ny))continue;
 			if(maze[nx][ny]=='#')continue;
 			if(vis[nx][ny]!=-1)continue;
 			q.push({lvl+1,{nx,ny}});
 			vis[nx][ny]=1;
 
 		}
 	}
 	/*
 	fo(i,0,n){
 		fo(j,0,m){
 			cout<<grid[i][j]<<" ";
 		}
 		cout<<endl;
 	}
 	cout.flush();
 	*/
 	_init(vis);
 	pair<int,int> from[n+1][m+1];
 	char dir[n+1][m+1];
 	s="RLDU";
 	q.push({0,{ax,ay}});
 	pii to={-1,-1};
 	bool mm=mon.size()>0;
 	while(q.size()>0){
 		pii p=q.front().y;
 		int lvl=q.front().x;
 		q.pop();
 		if(grid[p.x][p.y]!=-1&&lvl>=grid[p.x][p.y]){
 			//cout<<p.x<<" "<<p.y<<" "<<lvl<<" "<<grid[p.x][p.y]<<endl;
 			continue;
 		}
 		
 		//cout<<p.x<<" "<<p.y<<":";
 		if(p.x==0||p.x==n-1||p.y==0||p.y==m-1){
 				to={p.x,p.y};
 				break;
 		}
 		fo(i,0,4){
 			int nx=p.x+dx[i],ny=p.y+dy[i];
 			if(!possible(nx,ny))continue;
 			if(maze[nx][ny]=='#')continue;
 			if(vis[nx][ny]!=-1)continue;
 			if(grid[nx][ny]!=-1&&grid[nx][ny]<=lvl)continue;
 			from[nx][ny]=p;
 			q.push({lvl+1,{nx,ny}});
 			vis[nx][ny]=1;
 			dir[nx][ny]=s[i];
 			//cout<<"("<<nx<<","<<ny<<") ";
 
 			if(nx==0||nx==n-1||ny==0||ny==m-1){
 				//cout<<lvl<<" "<<
 
 				to={nx,ny};
 				break;
 			}
 		}
 
 		if(to.x!=-1)break;
//cout<<endl;
 
 	}
 //	cout<<to.x<<" "<<to.y<<" "<<ax<<" "<<ay<<endl;
 	if(to.x==-1){
 		cout<<"NO"<<endl;
 		return 0;
 	}
    cout<<"YES"<<endl;
    s="";
    while(to.x!=ax||to.y!=ay){
    	s+=dir[to.x][to.y];
    	//cout<<to.x<<" "<<to.y 
    	to=from[to.x][to.y];
 
 
    }
    reverse(all(s));
    cout<<s.size()<<endl;
    cout<<s<<endl;
 
    
    return 0;
}
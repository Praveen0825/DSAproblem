#include<bits/stdc++.h>
using namespace std;
int n,m,L,R,sx,sy,ans=0;;
char a[2005][2005],v[2005][2005];
struct A{int x,y,l,r;};
deque<A> q;
void go(int x,int y,int l,int r,char t){
    if(x<1||x>n||y<1||y>m)return;
	if(a[x][y]=='.'&&!v[x][y]&&l<=L&&r<=R){
		v[x][y]=1;
		if(t) q.push_front(A{x,y,l,r});
		else q.push_back(A{x,y,l,r});
	}
}
int main(){
	scanf("%d%d%d%d%d%d",&n,&m,&sx,&sy,&L,&R);
	for(int i=1;i<=n;++i) 
    cin>>a[i]+1;
	q.push_front({sx,sy,0,0});v[sx][sy]=1;
    A u;
	while(q.size())
    {
		u=q.front();q.pop_front();++ans;
		go(u.x-1,u.y,u.l,u.r,1);
		go(u.x+1,u.y,u.l,u.r,1);
		go(u.x,u.y-1,u.l+1,u.r,0);
		go(u.x,u.y+1,u.l,u.r+1,0);
	}
    printf("%d",ans);
    return 0;
}
#include <bits/stdc++.h>
#define ll long long int
using namespace std;

     

int main(){
	int n,m;
	cin>>n>>m;
	vector<vector<char>> s(n,vector<char>(m));
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++) cin>>s[i][j];
	}
	int k;
	cin>>k;
	vector<vector<int>> ydir(m);
	vector<ll> a(m),total(m);
	for(int j=0;j<m;j++){
		for(int i=0;i<n;i++){
			if(s[i][j]=='#') ydir[j].push_back(i),total[j]+=i;
		}
		int sz=ydir[j].size();
		if(sz>1){
			vector<ll> suff(sz);
			suff[sz-1]=ydir[j][sz-1];
			for(int i=sz-2;i>=0;i--) suff[i]+=suff[i+1];
			for(int i=0;i<sz-1;i++) a[j]+=(suff[i+1]-(n-i-1)*ydir[j][i]);
		}
	}
	ll soln=0;
	for(int j=0;j<m-k;j++){
		ll tres=0;
		for(int i=j;i<=j+k;i++){
			tres+=a[i];
			for(int l=i+1;l<=j+k;l++){
				for(int x:ydir[i]){
					for(int y:ydir[l]) tres+=abs(y-x);
					tres+=((l-i)*((int)ydir[l].size()));
				}
			}
		}
		soln=max(soln,tres);
	} 
	cout<<soln<<endl;
	
	return 0;
	
}
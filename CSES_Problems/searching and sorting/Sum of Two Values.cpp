#include<bits/stdc++.h>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	//cin.tie(nullptr);
	int n,x;
    cin>>n>>x;
    int a[n];
    for(int i=0;i<n;i++)cin>>a[i];
    map<int,int> us;
    for(int i=0;i<n;i++){
        if(us.find(x-a[i])!=us.end()){
            cout<<us[x-a[i]]<<" "<<i+1;
            return 0;
        }
        us.insert({a[i],i+1});
    }
    cout<<"IMPOSSIBLE";
	return 0;
}
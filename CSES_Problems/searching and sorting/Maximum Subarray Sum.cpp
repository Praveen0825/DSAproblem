#include<bits/stdc++.h>

using namespace std;
#define max(a,b) a>b?a:b
#define min(a,b) a<b?a:b

#define ll long long
const int MAX_N = 2e5;



int main(){
	ios_base::sync_with_stdio(false);
	//cin.tie(nullptr);
	ll n;
    cin>>n;
    ll a[n];
    for(int i=0;i<n;i++)cin>>a[i];
    ll m=a[0],ans=a[0];
    for(ll i=1;i<n;i++){
        m=max(a[i],m+a[i]);
        ans=max(ans,m);
    }
    cout<<ans;
	return 0;
}
#include <bits/stdc++.h>
using namespace std;
#define ll long long

#define pb push_back
#define rsz resize
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
using pi = pair<int,int>;
#define f first
#define s second
#define mp make_pair
void setIO(string name = "") { 
	ios_base::sync_with_stdio(0); cin.tie(0); 
	
}
 
 bool check(vector<ll>& ar,ll k,ll m){
     ll s=0,c=1;
     for(ll i=0;i<ar.size();i++){
         if(ar[i]>m)return false;
         if(s+ar[i]>m){
             s=ar[i];
           c++;
         }
         else
         s+=ar[i];
         if(c>k)return false;
     }
     return c<=k;
 }

int main() {
	setIO();
	ll n; ll t; cin >> n >> t;
	vector<ll> ar(n);
    ll s=0,ma=0;
	for (ll i = 0; i < n; i++) {
		cin >> ar[i];
        s+=ar[i];
        ma=ma>ar[i]?ma:ar[i];
	}
	ll lo = ma; ll hi = s; ll ans = 0;
	while (lo <= hi) {
		ll mid = (lo + hi) /2;
		if (check(ar,t,mid)) {
			ans = mid;
			hi = mid-1;
		} else {
			lo = mid+1;
		}
	}
	cout << ans << "\n";
}
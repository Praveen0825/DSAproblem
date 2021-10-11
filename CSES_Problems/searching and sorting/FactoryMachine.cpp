#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vi = vector<int>;
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


int main() {
	setIO();
	int n; ll t; cin >> n >> t;
	vector<ll> k(n);
	for (int i = 0; i < n; i++) {
		cin >> k[i];
	}
	ll lo = 0; ll hi = 1e18; ll ans = 0;
	while (lo <= hi) {
		ll mid = (lo + hi) /2;
		ll sum = 0;
		for (int i = 0; i < n; i++) {
			sum += (mid / k[i]);
			if(sum >= t){ //deal with overflow
				break;
			}
		}
		if (sum >= t) {
			ans = mid;
			hi = mid-1;
		} else {
			lo = mid+1;
		}
	}
	cout << ans << "\n";
}
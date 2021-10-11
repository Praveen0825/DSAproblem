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
 

int main() {
	setIO();
	ll n; ll k; cin >> n >> k;
	vector<ll> ar(n);
    ll s=0,ma=0;
    multiset<ll> ms;
	for (ll i = 0; i < n; i++) {
		cin >> ar[i];
       
	}
    
    for(ll i=0;i<k;i++){
        ms.insert(ar[i]);
    }
    ll z=(k+1)/2;
    ll j=0;
    ll med;
    for(auto it=ms.begin();j<z;it++){
       if(j==z-1)
       med=*it;
       j++;
       //cout<<*it<<" qq  ";
    }
    auto itr = next(ms.begin(), z-1);
   cout<<*itr<<" ";

   for(int i=k;i<n;i++){
       ms.insert(ar[i]);
       if(ar[i]<*itr){
          itr--;
       }
       
       if(ar[i-k]<=*itr)
       itr++;
       
       ms.erase(ms.find(ar[i-k]));
       

       
       cout<<*itr<<" ";

   }

	
	
}
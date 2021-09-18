#include <bits/stdc++.h>

using namespace std;
#define ll long long
#define ld long double
#define ui unsigned int
#define ull unsigned ll
#define ls (u << 1)
#define rs (ls | 1)
#define mp                   make_pair
#define eb                   emplace_back
#define pb                   push_back
#define pf                   push_front
#define popb                 pop_back
#define popf                 pop_front
#define hashmap              unordered_map
#define hashset              unordered_set
#define lb                   lower_bound
#define ub                   upper_bound
#define all(a)               (a).begin(), (a).end()
#define rall(a)              (a).rbegin(), (a).rend()
#define fi                   first
#define se                   second
#define foi(n) for(ll i=0;i<n;i++)
#define foj(n) for(ll j=0;j<n;j++)
#define fok(n) for(ll k=0;k<n;k++)
#define forr(i,a,b) for(ll i=a;i<b;i++)
#define forrr(i,b,a) for(ll i=b;i>=a;i--)
#define forrrr(i,a,b,k) for(ll i=a;i<b;i=i+k)
#define graph          vector<vector<ll>>
#define sz(v) v.size()
#define max(a,b) a>b?a:b
#define min(a,b) a<b?a:b
typedef pair<int, int> pii;
typedef pair<ll, ll>   pll;
typedef vector<int>         vi;
typedef vector<ll>          vll;
typedef vector<string>      vs;
typedef vector<double>      vd;
typedef vector<pii>         vpii;
typedef vector<pll>         vpll;
typedef pair< ll, pll>      plll;
typedef vector<plll>      vplll;
typedef  vector<string>       vs;
typedef  vector<char>          vc;
typedef  vector<bool>            vb;
typedef  map<string, int>         msi;
typedef  map<int, int>          mii;
typedef  map<ll, ll>             mll;
typedef  map<ll, vll>             mvll;
typedef  map<char, ll>           mcl;
typedef map<pair<ll, ll>, ll>  mplll;
typedef  unordered_map<char, ll>           umcl;
typedef  unordered_map< ll, char>           umlc;
typedef  map<int, string>      mis;
typedef  pair<string, int>       psi;
typedef  pair<string, string>    pss;
typedef priority_queue <ll> pq;
typedef priority_queue<pii, vector<pii>, greater<pii> > pqq;
typedef priority_queue<ll, vector<ll>, greater<ll>> prq;
const ll MOD = 1000000007;
const ll modx = 998244353;

int d4x[4] = {1, 0, -1, 0}; int d4y[4] = {0, 1, 0, -1};
int d8x[8] = {0, 1, 1, 1, 0, -1, -1, -1};
int d8y[8] = {1, 1, 0, -1, -1, -1, 0, 1};
 
const ll oo = 1e18;

 



void solve() {
ll n,m,i,j,k;
cin>>n>>m;



vector<pair<ll,ll>> adj[n+1];
for(int i=0;i<m;i++){
    ll u,v,w; 
    cin>>u>>v>>w;
    adj[u].pb({v,w});
    adj[v].pb({u,w});
}
ll src=1;

priority_queue<pll,vector<pll >,greater<pll > > pq;
vector<ll> dist(n+1,INT_MAX);
dist[src]=0;
pq.push({0,src});

vll par(n+1,-1);
//ll par[n+1];
par[1]=1;

while(!pq.empty()){
		ll d=pq.top().fi;
        ll pre=pq.top().se;

		pq.pop();
		
		for( auto it = adj[pre].begin() ; it != adj[pre].end() ; it++){
			ll next = it->first;
			ll nextd = it->second;
			if( dist[next] > dist[pre] + nextd){
                par[next]=pre;
				dist[next] = dist[pre] + nextd;
				pq.push({dist[next], next});
			}
		}		
}
if(par[n]==-1){
    cout<<"-1"<<"\n";
    return;
}
vll ans;
ll z=par[n];
ans.pb(n);
ans.pb(z);
while(z!=1){
z=par[z];
ans.pb(z);
}
reverse(all(ans));
ll y=ans.size();
foi(y)
cout<<ans[i]<<" ";

}

 
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #else 
    //online
    #endif
 
    int tc=1 ;
   //cin >> tc;
    while(tc--) {
        //ddd++;
        //cout << "Case #" << ddd << ": ";
        solve();
    }
}

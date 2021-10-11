#include<bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
  int n;
  cin >> n;
  map<int,int> compress;
  vector<int> a(n),b(n),p(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i] >> b[i] >> p[i];
    b[i]++;
    compress[a[i]], compress[b[i]];
  }
 
  int coords = 0;
  for (auto&v : compress) {
    v.second = coords++;
  }

  vector<vector<pair<int,int>>> project(coords);
  for (int i = 0; i < n; i++) {
    project[ compress[a[i]] ].emplace_back( compress[b[i]], p[i] );
  }

  vector<long long> dp(coords+1, 0);
  for (int i = coords-1; i >=0; i--) {
    
      dp[i] = dp[i+1];
    
    for (auto p : project[i]) {
      dp[i] = max(dp[i], dp[p.first]+p.second);
    }
  }
  cout << dp[0] << endl;
}
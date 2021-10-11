#include<bits/stdc++.h>
using namespace std;
#define ll long long 

int main(){
   ll n;
   cin>>n;
   vector<ll> c(n);
   for(int i=0;i<n;i++)
    cin>>c[i];
  vector<vector<bool>> dp(n*1000+1,vector<bool>(n+1,false));
   dp[0][0]=true;
   //sort(c.begin(),c.end());
   for(ll i=1;i<=n;i++){
       for(ll j=0;j<=n*1000;j++){
           dp[j][i]=dp[j][i-1];
           if(c[i-1]<=j&&dp[j-c[i-1]][i-1]){
           dp[j][i]=true;
           }
       }
   }
   vector<ll> ans;
   for(ll i=1;i<=n*1000;i++){
       if(dp[i][n])
       ans.push_back(i);
   }
   cout<<ans.size()<<"\n";
   for(int i=0;i<ans.size();i++){
       cout<<ans[i]<<" ";
   }

    return 0;
}

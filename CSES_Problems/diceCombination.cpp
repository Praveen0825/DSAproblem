#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll mod=1e9+7;
ll dp[1000001];
ll  solve(int n){
    if(n==0)return 1;
    if(n==1)return 1;
    if(dp[n]!=-1)return dp[n];
    ll ans=0;
    for(int i=1;i<=min(n,6);i++){
       ans=(ans+solve(n-i))%mod;
    }
    return dp[n]=ans;
}
int main(){
   int n;
   cin>>n;
   memset(dp,-1,sizeof dp);
  cout<<solve(n);
}
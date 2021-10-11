#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main(){
    ll n,q;
    cin>>n>>q;
    ll dp[n+1];
    dp[0]=0;
    for(ll i=1;i<=n;i++){
        ll a;
        cin>>a;
        if(i==1)
        dp[i]=a;
        else
        dp[i]=dp[i-1]^a;
    }
    while(q--){
        ll l,r;
        cin>>l>>r;
        cout<<(dp[r]^dp[l-1])<<"\n";
    }
}
#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll mod=1e9+7;
int main(){
    int t;
    cin>>t;
    ll dp[1000002][2];
    dp[1000001][0]=dp[1000001][1]=1;
    for(int i=1000000;i>=2;i--){
        ll op1=(dp[i+1][1] + dp[i+1][0])%mod;
        ll op2=dp[i+1][0];
        ll op3=(2*dp[i+1][0])%mod;
        ll op4= dp[i+1][1];

        dp[i][0]= (op1+op2+op3)%mod;
        dp[i][1]= (op1+op4)%mod;
    }

    
    while(t--){
        ll n;
        cin>>n;
        cout<<(dp[1000000-n+2][1]+ dp[1000000-n+2][0])%mod<<"\n";
    }
}
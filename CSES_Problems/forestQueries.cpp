#include<bits/stdc++.h>
using namespace std;

int main(){
    int n,q;
    cin>>n>>q;
    vector<vector<int>> dp(n+1,vector<int>(n+1,0));
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
          char a;
          cin>>a;
          dp[i][j]=dp[i-1][j]+dp[i][j-1]-dp[i-1][j-1]+(a=='*');
        }
    }

    while(q--){
        int l1,r1,l2,r2;
        cin>>l1>>r1>>l2>>r2;
        int ans=dp[l2][r2]+dp[l1-1][r1-1]-dp[l1-1][r2]-dp[l2][r1-1];
      cout<<ans<<"\n";
    }
    return 0;
}
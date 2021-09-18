//how many number between 0 to R,
// which digit sum is equal to X.

#include<bits/stdc++.h>
using namespace std;
#define ll long long

ll dp[101][101][2];

ll solve(string& num,ll n,ll x,bool tight){
    int m=num.length();
    if(x<0)return 0;
    if(n==1){
        if(x>=0&&((tight&&x<= int(num[m-1]-'0')) ||(!tight&&x<=9)))
        return 1;
        return 0;
    }
     if(dp[n][x][tight]!=-1)
     return dp[n][x][tight];

     ll ans=0;
     ll ub=tight? (num[num.length()-n]-'0'):9;

     for(ll dig=0;dig<=ub;dig++){
         ans+= solve(num,n-1, x-dig, tight&&(dig==ub));
     }

     return dp[n][x][tight]=ans;

}
int main(){
    memset(dp,-1,sizeof dp);
    string R="32";
    cout<<solve(R,R.length(),7,1);
    return 0;
}




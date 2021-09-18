//how many number between L to R,
// which odd postion has odd digit and even position has even digit.

#include<bits/stdc++.h>
using namespace std;
#define ll long long

ll dp[20][2][2][2];

ll solve(string& num,ll n,bool even,bool leading0,bool tight){
    int m=num.length();
    if(n==0)return 1;
    
     if(dp[n][even][leading0][tight]!=-1)
     return dp[n][even][leading0][tight];

     ll ans=0;
     ll ub=tight? (num[num.length()-n]-'0'):9;
      if(even){
          vector<int> digits={0,2,4,6,8};
          for(int dig:digits){
              if(dig<=ub)
              ans+= solve(num,n-1, 0,0, tight&&(dig==ub));
          }
          return dp[n][even][leading0][tight]=ans;
      }
      else{
        vector<int> digits={1,3,5,7,9}; 
        if(leading0){
            ans+= solve(num,n-1, 0,1, 0);
        }
        for(int dig:digits){
              if(dig<=ub)
              ans+= solve(num,n-1, 1,0, tight&&(dig==ub));
          }
          return dp[n][even][leading0][tight]=ans;

      }
     
     

}
int main(){
    memset(dp,-1,sizeof dp);
    string L,R;
    ll l,r;
    cin>>l>>r;
    L=to_string(l-1);
    R=to_string(r);
    ll z=solve(R,R.length(),0,1,1);
    memset(dp,-1,sizeof dp);
    ll y= solve(L,L.length(),0,1,1);
    cout<<z-y;
    return 0;
}




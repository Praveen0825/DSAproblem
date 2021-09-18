#include<bits/stdc++.h>
using namespace std;

double prob[20][20];
double dp[(1<<19)];

double pMove(int prev_bitMask,int j,int& n){
    int k=__builtin_popcount(prev_bitMask);
    double den=k*(k-1)/2;
    double moveProbab=0;
    for(int fish=0;fish<n;fish++){
        if((1<<fish)&prev_bitMask)
        moveProbab=prob[fish+1][j+1];
    }
    return moveProbab/(1.0*den);
}

double solve(int bitMask,int& n){
    int alive= __builtin_popcount(bitMask);
    if(alive==n)
    return 1;
    if(dp[bitMask]> -0.9)
    return dp[bitMask];
    double ans=0;
    for(int fish=0;fish<n;fish++){
        if(!(bitMask & (1<<fish))){
         int prev_bitMask = bitMask^(1<<fish);
         double prev_day = solve(prev_bitMask,n);
         ans+= prev_day*pMove(prev_bitMask,fish,n);

        }
    }
    return dp[bitMask]=ans;
}


int main(){
    int t,n,m,x,i,j,k,q;
    t=1;
    while(t--){
        cin>>n;
        memset(dp,-1,sizeof dp);
        for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
        cin>>prob[i][j];

        for(int i=0;i<n;i++)
        cout<<solve((1<<i),n)<<" ";
    }
}
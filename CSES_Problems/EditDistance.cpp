#include<bits/stdc++.h>
using namespace std;
#define ll long long

int dp[5001][5001];
   int minDist(string& a, string& b, int i, int j) {
        if (i == -1) {
            return j + 1;
        }
        if (j == -1) {
            return i + 1;
        }
        if (dp[i][j] != -1) {
            return dp[i][j];
        }
        if (a[i] == b[j]) {
            dp[i][j] =  minDist(a, b, i - 1, j - 1);
            return dp[i][j];
        }
        else {
            int add = minDist(a, b, i, j - 1);
            int replace = minDist(a, b, i - 1, j - 1);
            int remove = minDist(a, b, i - 1, j);
            
            dp[i][j] =  1 + min(min(add, replace), remove);
            return dp[i][j];
        }
    }
    
    


    int main(){
        string s1,s2;
        cin>>s1>>s2;
        memset(dp,-1,sizeof dp);
        int n=s1.length(),m=s2.length();
        cout<<minDist(s1,s2,n-1,m-1);
        return 0;
    }
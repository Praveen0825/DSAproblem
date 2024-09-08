#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll mod = 1e9 + 7;
int main()
{
    int t;
    cin >> t;
    ll dp[1000002][2];
    dp[1000001][0] = dp[1000001][1] = 1;
    for (int i = 1000000; i >= 2; i--)
    {
        ll op1 = (dp[i + 1][1] + dp[i + 1][0]) % mod;
        ll op2 = dp[i + 1][0];
        ll op3 = (2 * dp[i + 1][0]) % mod;
        ll op4 = dp[i + 1][1];

        dp[i][0] = (op1 + op2 + op3) % mod;
        dp[i][1] = (op1 + op4) % mod;
    }

    while (t--)
    {
        ll n;
        cin >> n;
        cout << (dp[1000000 - n + 2][1] + dp[1000000 - n + 2][0]) % mod << "\n";
    }
}

/*
const int mod  = 1000000007;
int dp[1000001][2];
//0 both below tile are free (ek chada + ek chada + dono chade + dono band upar alag alag  + dono band upar ek )
//1 both below tile jud gaye (chade + band hogaye upar ek + band hogye upar do)

void fun(){
    dp[1][1] = 1;
    dp[1][0] = 1;
    for(int i=2;i<=1000001;i++){
        dp[i][0] = ((dp[i-1][0] * 4)%mod + dp[i-1][1]%mod) %mod;
        dp[i][1] = (dp[i-1][0]%mod + (2*dp[i-1][1])%mod) %mod;
    }
}

int32_t main(){
    fast
    int t=1;
    cin>>t;

    fun();
    while(t--){
        int n;cin>>n;
        cout<<(dp[n][1] + dp[n][0])%mod<<endl;
    }
    r*/
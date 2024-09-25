// Your task is to count the number of integers between a and b where no two adjacent digits are the same.
#include <bits/stdc++.h>
using namespace std;
#define ll long long

ll dp[20][10][2][2];

ll solve(string &num, ll n, int x, bool leading0, bool tight)
{
    int m = num.length();
    if (n == 0)
        return 1;

    if (x != -1 && dp[n][x][leading0][tight] != -1)
        return dp[n][x][leading0][tight];

    ll ans = 0;
    ll lb = 0;
    ll ub = tight ? (num[num.length() - n] - '0') : 9;

    for (ll dig = lb; dig <= ub; dig++)
    {
        if (dig == x && leading0 == 0)
            continue;
        ans += solve(num, n - 1, dig, leading0 & (dig == 0), tight & (dig == ub));
    }
    return dp[n][x][leading0][tight] = ans;
}
int main()
{
    memset(dp, -1, sizeof dp);
    string L, R;
    ll l, r;
    cin >> l >> r;
    L = to_string(l - 1);
    R = to_string(r);
    ll z = solve(R, R.length(), -1, 1, 1);
    memset(dp, -1, sizeof dp);
    ll y = solve(L, L.length(), -1, 1, 1);
    cout << z - y;
    return 0;
}

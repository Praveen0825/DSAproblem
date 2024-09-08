#include <bits/stdc++.h>
#pragma GCC target("popcnt")

using namespace std;
typedef long long ll;

int N;
ll ans;

int main()
{
    cin.sync_with_stdio(0);
    cin.tie(0);

    cin >> N;
    vector<bitset<3000>> B(N);
    for (int i = 0; i < N; i++)
        cin >> B[i];

    for (int i = 0; i < N; i++)
        for (int j = i + 1; j < N; j++)
        {
            int c = (B[i] & B[j]).count();
            ans += c * (c - 1) / 2;
        }

    cout << ans;
}
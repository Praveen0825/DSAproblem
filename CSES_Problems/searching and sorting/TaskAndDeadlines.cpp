#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

int main() {
    //Take inputs
    int n;
    cin >> n;
    vector<pair<int,int>> tasks(n);
    for (int i = 0; i < n; i++)
        cin >> tasks[i].first >> tasks[i].second;

    //Greedily sort them from fastest to slowest achievable task for maximum score
    sort(tasks.begin(), tasks.end());
    ll total = 0;
    ll ans = 0;
    for (auto i: tasks){
        total += i.first;
        ans += i.second - total;
    }

    //Output
    cout << ans;

    return 0;
}
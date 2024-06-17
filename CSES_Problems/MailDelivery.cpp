#include <iostream>
#include <vector>
#include <set>
using namespace std;

int m, n;
vector<int> res;
vector<set<int>> adj;

// euler circuit
void dfs(int curr)
{
    auto &edges = adj[curr];
    while (!edges.empty())
    {
        auto edge = *edges.begin();
        edges.erase(edge);
        adj[edge].erase(curr);
        dfs(edge);
    }
    res.push_back(curr);
}

int main()
{
    cin >> n >> m;
    adj.resize(n + 1);
    for (int i = 1; i <= m; ++i)
    {
        int x, y;
        cin >> x >> y;
        adj[x].insert(y);
        adj[y].insert(x);
    }

    for (int i = 1; i <= n; ++i)
    {
        if (adj[i].size() % 2)
        {
            cout << "IMPOSSIBLE\n";
            return 0;
        }
    }

    dfs(1);

    if (res.size() != m + 1)
    {
        cout << "IMPOSSIBLE\n";
        return 0;
    }

    for (auto &r : res)
        cout << r << ' ';
}
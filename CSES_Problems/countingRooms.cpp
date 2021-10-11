#include<bits/stdc++.h>
using namespace std;
int n, m;
void DFS(vector<vector<bool>> &mp, vector<vector<bool>> &visited, int i, int j)
{
    if (i < 0 || i >= n || j < 0 || j >= m || visited[i][j] || !mp[i][j]) return;
    visited[i][j] = true;
    DFS(mp, visited, i+1, j);
    DFS(mp, visited, i-1, j);
    DFS(mp, visited, i, j+1);
    DFS(mp, visited, i, j-1);
}
signed main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    cin >> n >> m;
    vector<vector<bool>> mp(n,vector<bool>(m, false)), visited(n,vector<bool>(m, false));
    for (int i = 0; i < n; ++i)
    {
        string str; cin >> str;
        for (int j = 0; j < m; ++j) mp[i][j] = (str[j] == '.');
    }
    int res = 0;
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < m; ++j)
        {
            if (visited[i][j] || !mp[i][j]) continue;
            DFS(mp, visited, i, j);
            res++;
        }
    }
    cout << res << '\n';
    return 0;
}

class Solution
{
public:
    int dirs[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
    bool findSafeWalk(vector<vector<int>> &g, int h)
    {
        int n = g.size(), m = g[0].size();
        vector<vector<int>> dp(n, vector<int>(m, 1e5));
        vector<vector<bool>> vis(n, vector<bool>(m, 0));
        vis[0][0] = 1;
        dp[0][0] = g[0][0];
        deque<pair<int, pair<int, int>>> dq;
        dq.push_back({0, {0, g[0][0]}});

        while (!dq.empty())
        {
            pair<int, pair<int, int>> p = dq.front();
            int a = p.first, b = p.second.first, c = p.second.second;
            dq.pop_front();
            if (a == n - 1 && b == m - 1)
                return c < h;

            for (auto dir : dirs)
            {
                int x = dir[0] + a;
                int y = dir[1] + b;
                if (x < 0 || y < 0 || x >= n || y >= m)
                    continue;
                int cost;
                if (!vis[x][y])
                {
                    if (g[x][y] == 0)
                        dq.push_front({x, {y, c}});
                    else
                        dq.push_back({x, {y, c + 1}});
                    vis[x][y] = 1;
                }
            }
        }
        return 0;
    }
};
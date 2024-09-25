class Solution
{
public:
    int fun(vector<vector<int>> &c)
    {
        sort(c.begin(), c.end(), [](vector<int> &a, vector<int> &b) -> bool
             { return a[0] == b[0] ? b[1] < a[1] : a[0] < b[0]; });
        vector<int> dp;
        for (auto &p : c)
        {
            int height = p[1];
            int left = lower_bound(dp.begin(), dp.end(), height) - dp.begin();
            if (left == dp.size())
                dp.push_back(height);
            dp[left] = height;
        }
        return dp.size();
    }

    int maxPathLength(vector<vector<int>> &c, int k)
    {
        vector<int> p = c[k];
        int n = c.size();
        vector<vector<int>> c1, c2;
        for (int i = 0; i < n; i++)
        {
            if (c[i][1] < p[1] && c[i][0] < p[0])
                c1.push_back(c[i]);
            if (c[i][1] > p[1] && c[i][0] > p[0])
                c2.push_back(c[i]);
        }
        sort(c1.begin(), c1.end());
        sort(c2.begin(), c2.end());
        int l1 = 0, l2 = 0;
        if (c1.size())
            l1 = fun(c1);
        if (c2.size())
            l2 = fun(c2);
        return l1 + l2 + 1;
    }
};

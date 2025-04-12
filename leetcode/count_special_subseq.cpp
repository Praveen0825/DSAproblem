class Solution
{
public:
    const int mod = 1e9 + 7;
    string removeOccurrences(string s, string p)
    {
        int n = s.length(), m = p.length();
        if (n < m)
            return s;
        long h = 1;
        for (int i = 0; i < m - 1; i++)
        {
            h = (h * 26) % mod;
        }
        long p_hash = 0, s_hash = 0;
        string ans = "";
        vector<long> hp(n + 1, 0);
        for (int i = 0; i < m; i++)
        {

            p_hash = (p_hash * 26 + p[i]) % mod;
            s_hash = (s_hash * 26 + s[i]) % mod;
            hp[i + 1] = s_hash;
            ans += s[i];
        }
        int l;
        for (int i = 0; i <= n - m; i++)
        {
            if (p_hash == s_hash && ans.size() >= m)
            {
                int j;
                l = ans.size();
                for (j = 0; j < m; j++)
                {
                    if (ans[l - m + j] != p[j])
                        break;
                }
                if (j == m)
                {
                    for (int k = 0; k < m; k++)
                        ans.pop_back();
                }
            }
            if (i == n - m)
                continue;
            char ch = s[i + m];
            l = ans.size();
            if (l < m)
            {
                hp[l + 1] = (hp[l] * 26 + ch) % mod;
            }
            else
            {
                hp[l + 1] = (26 * (hp[l] - ans[l - m] * h) + ch) % mod;
                if (hp[l + 1] < 0)
                    hp[l + 1] += mod;
            }
            ans += ch;
            s_hash = hp[l + 1];
        }
        return ans;
    }
};
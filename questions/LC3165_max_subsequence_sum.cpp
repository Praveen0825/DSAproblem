struct node
{
    // long long ans[0], ans[1], ans[2], ans[3];
    long long ans[4];
};

const int N = 50010;
node seg[4 * N];
long long a[N];

void build(int l, int r, int pos)
{
    if (l == r)
    {
        seg[pos].ans[0] = a[l];
        seg[pos].ans[1] = 0;
        seg[pos].ans[2] = 0;
        seg[pos].ans[3] = 0;
        return;
    }

    int mid = (l + r) / 2;
    build(l, mid, pos * 2);
    build(mid + 1, r, pos * 2 + 1);

    seg[pos].ans[0] = max({seg[pos * 2].ans[2] + seg[pos * 2 + 1].ans[1], seg[pos * 2].ans[0] + seg[pos * 2 + 1].ans[1], seg[pos * 2].ans[2] + seg[pos * 2 + 1].ans[0]});
    seg[pos].ans[1] = max({seg[pos * 2].ans[3] + seg[pos * 2 + 1].ans[1], seg[pos * 2].ans[1] + seg[pos * 2 + 1].ans[1], seg[pos * 2].ans[3] + seg[pos * 2 + 1].ans[0]});
    seg[pos].ans[2] = max({seg[pos * 2].ans[2] + seg[pos * 2 + 1].ans[3], seg[pos * 2].ans[0] + seg[pos * 2 + 1].ans[3], seg[pos * 2].ans[2] + seg[pos * 2 + 1].ans[2]});
    seg[pos].ans[3] = max({seg[pos * 2].ans[3] + seg[pos * 2 + 1].ans[3], seg[pos * 2].ans[1] + seg[pos * 2 + 1].ans[3], seg[pos * 2].ans[3] + seg[pos * 2 + 1].ans[2]});
}

void update(int pos)
{
    seg[pos].ans[0] = max({seg[pos * 2].ans[2] + seg[pos * 2 + 1].ans[1], seg[pos * 2].ans[0] + seg[pos * 2 + 1].ans[1], seg[pos * 2].ans[2] + seg[pos * 2 + 1].ans[0]});
    seg[pos].ans[1] = max({seg[pos * 2].ans[3] + seg[pos * 2 + 1].ans[1], seg[pos * 2].ans[1] + seg[pos * 2 + 1].ans[1], seg[pos * 2].ans[3] + seg[pos * 2 + 1].ans[0]});
    seg[pos].ans[2] = max({seg[pos * 2].ans[2] + seg[pos * 2 + 1].ans[3], seg[pos * 2].ans[0] + seg[pos * 2 + 1].ans[3], seg[pos * 2].ans[2] + seg[pos * 2 + 1].ans[2]});
    seg[pos].ans[3] = max({seg[pos * 2].ans[3] + seg[pos * 2 + 1].ans[3], seg[pos * 2].ans[1] + seg[pos * 2 + 1].ans[3], seg[pos * 2].ans[3] + seg[pos * 2 + 1].ans[2]});
}

void upd(int l, int r, int pos, int id, long long new_val)
{
    if (l == r)
    {
        a[l] = new_val;
        seg[pos].ans[0] = a[l];
        seg[pos].ans[1] = 0;
        seg[pos].ans[2] = 0;
        seg[pos].ans[3] = 0;
    }
    else
    {
        int m = (l + r) / 2;
        if (id <= m)
            upd(l, m, pos * 2, id, new_val);
        else
            upd(m + 1, r, pos * 2 + 1, id, new_val);
        update(pos);
    }
}

class Solution
{
public:
    int maximumSumSubsequence(vector<int> &nums, vector<vector<int>> &queries)
    {
        int n = nums.size();
        for (int i = 0; i < n; i++)
            a[i] = nums[i];
        build(0, n - 1, 1);
        long long ans = 0, md = 1e9 + 7;
        for (auto p : queries)
        {
            int pos = p[0];
            long long x = p[1];
            upd(0, n - 1, 1, pos, x);
            ans = (ans + max({seg[1].ans[0], seg[1].ans[1], seg[1].ans[2], seg[1].ans[3]})) % md;
        }
        ans %= md;
        return ans;
    }
};
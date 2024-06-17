#include <bits/stdc++.h>

using namespace std;
#define ll long long
ll allsum(ll n)
{
    return n * (n + 1) / 2;
}
// O(n^2) solution
ll fun1(vector<ll> a, int k)
{
    reverse(a.begin(), a.end());
    int i = 0;
    int n = a.size();
    // int t = k;
    ll ans = 0;
    for (; i < n; i++)
    {
        int t = k;
        ll cur = 0;
        ll s;
        int r;
        for (int j = i; j < n; j++)
        {
            if (a[j] < t)
            {
                s = allsum(a[j]);
                cur += s;
                t -= a[j];
            }
            else
            {
                r = a[j] - t;
                s = allsum(a[j]) - allsum(r);
                ans = max(ans, cur + s);
                break;
            }
        }
    }
    return ans;
}

// O(n) solution
ll fun(vector<ll> a, int k)
{
    reverse(a.begin(), a.end());
    int i = 0, j = 0;
    int n = a.size();
    int t = k;
    ll ans = 0, cur = 0;
    for (; i < n; i++)
    {
        int r = 0;
        ll s = 0;
        if (a[i] < t)
        {
            s = allsum(a[i]);
            cur += s;
            t -= a[i];
        }
        else
        {
            r = a[i] - t;
            s = allsum(a[i]) - allsum(r);
            ans = max(ans, cur + s);
            while (i > j && t + a[j] <= a[i])
            {
                t += a[j];
                r = a[i] - t;
                cur -= allsum(a[j]);
                j++;
                s = allsum(a[i]) - allsum(r);
                ans = max(ans, cur + s);
            }
            if (i > j)
            {
                cur -= allsum(a[j]);
                t += a[j];
                j++;
            }
            if (a[i] < t)
            {
                s = allsum(a[i]);
                cur += s;
                t -= a[i];
            }
            else
            {
                r = a[i] - t;
                s = allsum(a[i]) - allsum(r);
                ans = max(ans, cur + s);
            }
        }
    }
    return ans;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int k;
        int n;
        cin >> k;
        cin >> n;
        vector<ll> a(n);
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        cout << fun(a, k) << " " << fun1(a, k) << "\n";
    }
    return 0;
}
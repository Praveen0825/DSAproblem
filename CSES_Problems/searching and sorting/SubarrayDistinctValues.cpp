#include <bits/stdc++.h>
using namespace std;
#define ll long long

// output of this function -->numbers of subarrays which have number of different integers less than equal to k
ll fun(ll k, vector<ll> nums)
{
    if (k == 0)
        return 0;
    ll j = 0;
    ll count = 0;
    ll n = nums.size();
    ll total = 0;
    unordered_map<ll, ll> freq;
    for (ll i = 0; i < n; i++)
    {
        if (freq.find(nums[i]) != freq.end() || freq[nums[j]] == 0)
            count++;
        freq[nums[i]]++;
        if (count <= k)
            total += (i - j + 1); // (i-j+1) = number of subarrays ending at i-th position which contains number of different llegers less than or equal to k
        else
        {
            while (count > k)
            {
                freq[nums[j]]--;
                if (freq[nums[j]] == 0)
                {
                    count--;
                }
                j++;
            }
            total += (i - j + 1);
        }
    }
    return total;
}

int main()
{
    ll n;
    ll k;
    cin >> n >> k;
    vector<ll> ar(n);
    for (ll i = 0; i < n; i++)
    {
        cin >> ar[i];
    }
    cout << fun(k, ar);
}
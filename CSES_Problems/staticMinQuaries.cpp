#include<bits/stdc++.h>
using namespace std;
# define ll long long 
vector<ll> arr;
ll firstSetBit(ll x);
void update(ll i, ll val, ll &size, vector<ll> &count);
void insert(ll index, ll gap, ll &size, vector<ll> &count);
ll getSum(ll index, vector<ll> &count);

void BITree(vector<ll> &nums, ll &size, vector<ll> &count)
{
    size = nums.size();
    if (size > 0)
    {
        arr = nums;
        count.resize(size + 1, 0);
        for (ll i = 0; i < size; i++)
        {
            insert(i + 1, arr[i], size, count);
        }
    }
}

ll sumRange(ll i, ll j, vector<ll> &count)
{
    return getSum(j + 1, count) - (i == 0 ? 0 : getSum(i, count));
}

void update(ll i, ll val, ll &size, vector<ll> &count)
{
    ll gap = val - arr[i];
    arr[i] = val;
    insert(i + 1, gap, size, count);
}

ll getSum(ll index, vector<ll> &count)
{
    ll res = 0;
    while (index > 0)
    {
        res += count[index];
        index -= firstSetBit(index);
    }
    return res;
}

void insert(ll index, ll gap, ll &size, vector<ll> &count)
{
    while (index <= size)
    {
        count[index] += gap;
        index += firstSetBit(index);
    }
}

ll firstSetBit(ll x)
{
    return x & (-x);
}



int main()
{
    ll N, input;
    vector<ll> count;
    ll size;
    cin >> N;
    ll q;
    cin>>q;
    vector<ll> nums;
    while (N--)
    {
        cin >> input;
        nums.push_back(input);
    }
    BITree(nums, size, count);
    char ch;
    ll num1, num2, T;
    cin >> T;
    while (T--)
    {
        cin >> ch >> num1 >> num2;
        if (ch == 's')
            cout << sumRange(num1, num2, count) << " ";
        else
            update(num1, num2, size, count);
    }
}
#include <iostream>
#include <vector>
using namespace std;
#define ll long long

vector<vector<ll>> tree;
vector<vector<ll>> inp_matrix;
ll _row;
ll _col;
void BITree(vector<vector<ll>> &inp_matrix);
void updateTree(ll row, ll col, ll val);
ll sumRegion(ll &row1, ll &col1, ll &row2, ll &col2);
ll getSum(ll row, ll col);
ll firstSetBit(ll x);

void BITree(vector<vector<ll>> &inp_matrix)
{
    _row = inp_matrix.size();
    if (_row == 0)
        return;
    _col = inp_matrix[0].size();
    inp_matrix = vector<vector<ll>>(inp_matrix);
    tree = vector<vector<ll>>(_row + 1, vector<ll>(_col + 1, 0));
    for (ll i = 0; i < _row; i++)
        for (ll j = 0; j < _col; j++)
        {
            updateTree(i, j, inp_matrix[i][j]);
        }
}

ll sumRegion(ll &row1, ll &col1, ll &row2, ll &col2)
{
    return getSum(row2 + 1, col2 + 1) - getSum(row1, col2 + 1) - getSum(row2 + 1, col1) + getSum(row1, col1);
}

void update(ll &row, ll &col, ll &val, vector<vector<ll>> &inp_matrix)
{
    updateTree(row, col, val - inp_matrix[row][col]);
    inp_matrix[row][col] = val;
}

void updateTree(ll row, ll col, ll val)
{

    for (ll i = row + 1; i <= _row; i += firstSetBit(i))
        for (ll j = col + 1; j <= _col; j += firstSetBit(j))
        {
            tree[i][j] += val;
        }
}

ll getSum(ll row, ll col)
{
    ll sum = 0;
    for (ll i = row; i > 0; i -= firstSetBit(i))
        for (ll j = col; j > 0; j -= firstSetBit(j))
        {
            sum += tree[i][j];
        }
    return sum;
}

ll firstSetBit(ll x)
{
    return x & (-x);
}

int_fast8_t main()
{
    ll r, c, input;
    cin >> r >> c;
    vector<vector<ll>> inp_matrix;
    for (ll i = 0; i < r; i++)
    {
        vector<ll> row;
        for (ll j = 0; j < c; j++)
        {
            cin >> input;
            row.push_back(input);
        }
        inp_matrix.push_back(row);
    }
    BITree(inp_matrix);
    char ch;
    ll r1, c1, r2, c2, val, T;
    cin >> T;
    while (T--)
    {
        cin >> ch;
        if (ch == 's')
        {
            cin >> r1 >> c1 >> r2 >> c2;
            cout << sumRegion(r1, c1, r2, c2) << " ";
        }
        else
        {
            cin >> r1 >> c1 >> val;
            update(r1, c1, val, inp_matrix);
        }
    }
}
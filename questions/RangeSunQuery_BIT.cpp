#include <iostream>
#include <vector>
using namespace std;

vector<int> arr;
int firstSetBit(int x);
void update(int i, int val, int &size, vector<int> &count);
void insert(int index, int gap, int &size, vector<int> &count);
int getSum(int index, vector<int> &count);

void BITree(vector<int> &nums, int &size, vector<int> &count)
{
    size = nums.size();
    if (size > 0)
    {
        arr = nums;
        count.resize(size + 1, 0);
        for (int i = 0; i < size; i++)
        {
            insert(i + 1, arr[i], size, count);
        }
    }
}

int sumRange(int i, int j, vector<int> &count)
{
    return getSum(j + 1, count) - (i == 0 ? 0 : getSum(i, count));
}

void update(int i, int val, int &size, vector<int> &count)
{
    int gap = val - arr[i];
    arr[i] = val;
    insert(i + 1, gap, size, count);
}

int getSum(int index, vector<int> &count)
{
    int res = 0;
    while (index > 0)
    {
        res += count[index];
        index -= firstSetBit(index);
    }
    return res;
}

void insert(int index, int gap, int &size, vector<int> &count)
{
    while (index <= size)
    {
        count[index] += gap;
        index += firstSetBit(index);
    }
}

int firstSetBit(int x)
{
    return x & (-x);
}



int main()
{
    int N, input;
    vector<int> count;
    int size;
    cin >> N;
    vector<int> nums;
    while (N--)
    {
        cin >> input;
        nums.push_back(input);
    }
    BITree(nums, size, count);
    char ch;
    int num1, num2, T;
    cin >> T;
    while (T--)
    {
        cin >> ch >> num1 >> num2;
        if (ch == 's')
            cout << sumRange(num1, num2, count) << " ";
        else
            update(num1, num2, size, count);
    }
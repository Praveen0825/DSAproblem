/*
Problem Description

You are given three sorted arrays A, B, and C, each of size n, and an integer D. The task is to count the number of unique tuples (i, j, k) where:

i is an index in array A,
j is an index in array B,
k is an index in array C,
such that the following conditions are satisfied:

|A[i] - B[j]| ≤ D,  |A[i] - C[k]| ≤ D,  |B[j] - C[k]| ≤ D
Input

A, B, C: Lists of integers of length n, sorted in non-decreasing order.
D: An integer representing the maximum allowable absolute difference.
Output

An integer representing the count of all valid tuples (i, j, k) that satisfy the conditions.
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;
int min(int a, int b, int c)
{
    return min(a, min(b, c));
}

vector<pair<int, int>> mergeThreeSortedArr(vector<int> &A, vector<int> &B, vector<int> &C)
{
    int n = A.size(), m = B.size(), o = C.size();
    vector<pair<int, int>> merged;

    int i = 0, j = 0, k = 0;
    while (i < n || j < m || k < o)
    {
        int mn = INT_MAX;
        int a = (i < n) ? A[i] : INT_MAX;
        int b = (j < m) ? B[j] : INT_MAX;
        int c = (k < o) ? C[k] : INT_MAX;
        if (min(a, b, c) == a)
        {
            i++;
            merged.push_back({a, 0});
        }
        else if (min(a, b, c) == b)
        {
            j++;
            merged.push_back({b, 1});
        }
        else
        {
            k++;
            merged.push_back({c, 2});
        }
    }

    return merged;
}

int countTriplets(vector<int> &A, vector<int> &B, vector<int> &C, int d)
{

    vector<pair<int, int>> merged = mergeThreeSortedArr(A, B, C);
    int n = merged.size();
    // applying sliding window
    int triplets = 0;
    int start = 0;
    int cntAEle = 0;
    int cntBEle = 0;
    int cntCEle = 0;
    for (int end = 0; end < n; end++)
    {
        if (merged[end].second == 0)
            cntAEle++;
        else if (merged[end].second == 1)
            cntBEle++;
        else
            cntCEle++;
        // make the window valid
        while (start < end && merged[end].first - merged[start].first > d)
        {
            if (merged[start].second == 0)
            {
                cntAEle--;
            }
            else if (merged[start].second == 1)
            {
                cntBEle--;
            }
            else
            {
                cntCEle--;
            }
            start++;
        }

        // count the triplets formed with last character
        if (merged[end].second == 0)
            triplets += (cntBEle * cntCEle);
        else if (merged[end].second == 1)
            triplets += (cntAEle * cntCEle);
        else
            triplets += (cntBEle * cntAEle);
    }

    return triplets;
}

int main()
{
    vector<int> A = {1, 3, 5, 6};
    vector<int> B = {2, 3, 4, 7};
    vector<int> C = {2, 4, 7, 9};
    int d = 3;

    cout << countTriplets(A, B, C, d) << endl;
    // OP: 27

    return 0;
}
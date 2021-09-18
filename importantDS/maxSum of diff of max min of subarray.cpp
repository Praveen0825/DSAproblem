//split an array into different subarray such that sum of diiference of max and min of each subarray is max.

//O(n)

#include <bits/stdc++.h>

using namespace std;
#define max(a,b) a>b?a:b
#define min(a,b) a<b?a:b

long maximumSum_simplified(int A[],int len) {
        //int len = A.length;

        // maxSum[i+1] will be the max sum out of A[0..i] for selected `i`s.
        long maxSum[len + 1];
        // maxSum[0] = 0;  by Java default.
       //memset(maxSum,0,sizeof maxSum);
       for(int i=0;i<=len;i++)
       maxSum[i]=0;
        // A[start..end] will be a maximal increasing run or a maximal decreasing run.
        for (int start = 0, end; start < len - 1; start = end) {
            end = start + 1;
            if (A[end] <= A[start]) {
                while (end + 1 < len && A[end + 1] <= A[end]) end++;
                for (int i = max(end - 1, start + 1); i <= end; i++) {
                    maxSum[i + 1] = max(maxSum[start] + A[start] - A[i],
                            maxSum[start + 1] + A[start + 1] - A[i]);
                }
            } else {
                while (end + 1 < len && A[end + 1] >= A[end]) end++;
                for (int i = max(end - 1, start + 1); i <= end; i++) {
                    maxSum[i + 1] =max(maxSum[start] + A[i] - A[start],
                            maxSum[start + 1] + A[i] - A[start + 1]);
                }
            }
        }

        return maxSum[len];
    }
 
int main()
{  int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++)
    cin>>a[i];
    long ans=maximumSum_simplified(a,n);
    cout<<ans;
    return 0;
}


/*
//O(n^2) java
long[] dp = new long[N + 1];
 
for(int i = N-1;i >= 0; --i){
    dp[i] = 0;
    int min = A[i],max = A[i];
    for(int j = i; j < N; ++j){
        min = Math.min(min, A[j]);
        max = Math.max(max, A[j]);
        dp[i] = Math.max(dp[i],max - min + dp[j + 1]);
    }
}
 
print(dp[0])



*/


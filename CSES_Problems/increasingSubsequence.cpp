#include<bits/stdc++.h>
using namespace std;
#define ll long long

int lengthOfLIS(vector<int>& nums) {
        vector<int> sub;
        for (int x : nums) {
            if (sub.empty() || sub[sub.size() - 1] < x) {
                sub.push_back(x);
            } else {
                int it = lower_bound(sub.begin(), sub.end(), x)-sub.begin(); // Find the index of the smallest number >= x
                //cout<<*it<<" "<<x<<" a ";
                sub[it] = x; // Replace that number with x
            }
        }
        return sub.size();
    }


    int main(){
        int n;
        cin>>n;
        vector<int> a(n);
        for(int i=0;i<n;i++)
        cin>>a[i];
        cout<<lengthOfLIS(a);
    }
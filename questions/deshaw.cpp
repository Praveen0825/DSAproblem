#include<bits/stdc++.h>
using namespace std;
vector<long>  func(vector<string> s,int d,vector<int> k,vector<int>m ){
    vector<long long int> cal[d+1];
    for(int i=1;i<=k.size();i++){
        for(int j=0;j<s.size();j++){
            string ss=s.substr(d-i,i);
            long long v=stoll(ss);
            cal[i].push_back(v);
        }
        sort(cal.begin(),cal.end());
    }
    vector<long> ans;
    for(int i=0;i<k.size();i++){
        ans.push_back(cal[m[i]][k[i]-1]);
    }
    return ans;
}
int32_t main(){
    int n;
    // cin>>n;
    vector<int> e={1,2};
    vector<int> r={2,3};
    cout<<func(e,r);
}
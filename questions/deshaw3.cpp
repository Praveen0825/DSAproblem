#include<bits/stdc++.h>
using namespace std;
int func(vector<int> e,vector<int> r){
    int n=e.size();
    pair<int,int>v[n];
    for(int i=0;i<n;i++)
    {
        v[i]={min(e[i],r[i]),max(e[i],r[i])};
    }
    sort(v,v+n);
    int ans=1;
    priority_queue<int,vector<int>,greater<int>> pq;
    pq.push(v[0].second);
    for(int i=1;i<n;i++)
    {
        if(pq.top()>=v[i].first)
        {
            ans++;
            pq.push(v[i].second);
        }
        else
        {
            pq.pop();
            pq.push(v[i].second);
        }
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
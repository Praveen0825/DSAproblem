#include<bits/stdc++.h>
using namespace std;

int findCheapestPrice(int n, vector<vector<int>>& a, int s, int sink, int k) {
       vector<vector<int>> ad[n];
        vector<int> dist(n+1, INT_MAX);
        for(auto v:a){
            ad[v[0]].push_back({v[1],v[2]});
        }
        priority_queue<tuple<int,int,int>,vector<tuple<int,int,int>>,
        greater<tuple<int,int,int>>> pq;
        pq.push(make_tuple(0,s,0));
        while(!pq.empty()){
           auto [co,no,st]=pq.top();
            pq.pop();
            
            if(no==sink)return co;
            if(dist[no]<st) continue;
                 dist[no]=st;
            if(st>k)continue;
            
            for(auto adj:ad[no]){
               
             pq.push(make_tuple(co+adj[1],adj[0],st+1));   
            }
        }
      return -1; 
    }

    int main(){
      return 0;  
    }
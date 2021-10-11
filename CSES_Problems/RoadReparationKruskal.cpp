#include <bits/stdc++.h>
using namespace std;
#define ll long long
const ll MAX = 1e5+5;
ll id[MAX] ,nodes,edges;
pair <ll ,pair<ll,ll> > p[2*MAX];



void initialize(){
    for(ll i=0;i<MAX;i++)
        id[i] = i;
}
ll root(ll x){
    while(id[x]!=x){
        id[x] = id[id[x]];
        x = id[x];
    }
    return x;
}
void union1(ll x,ll y){
    ll p = root(x);
    ll q = root(y);
    id[p] = id[q];
}
ll Kruskal(pair <ll ,pair<ll,ll> > p[]){
    ll x,y;
    ll cnt=0;
    ll cost,minimumCost = 0;
    for(ll i=0;i<edges;i++){
        x = p[i].second.first;
        y = p[i].second.second;
        cost = p[i].first;
        if(root(x)!=root(y)){
            cnt++;
            minimumCost += cost;
            union1(x,y);
        }
    }
    if(cnt>=nodes-1)
    return minimumCost;
    else{
        return -1;
    }
}
int main(){
    ll x,y;
    ll weight,cost,minimumCost;
    initialize();
    cin>>nodes>>edges;
    for(ll i=0;i<edges;i++){
        cin>>x>>y>>weight;
        p[i] = make_pair(weight,make_pair(x,y));
    }
    sort(p,p+edges);
    minimumCost = Kruskal(p);
    if(minimumCost==-1){
        cout<<"IMPOSSIBLE";
    }
    else
    cout<<minimumCost;
    return 0;
}
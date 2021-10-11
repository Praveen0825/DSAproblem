#include<bits/stdc++.h>
using namespace std;
#define ll int

ll n;
vector<ll> t;

void build(ll a[], ll v, ll tl, ll tr) {
    if (tl == tr) {
        t[v] = a[tl];
       // cout<<v<<":  "<<t[v]<<" ";
    } else {
        ll tm = (tl + tr) / 2;
       // cout<<tm<<" ";
        build(a, v*2+1, tl, tm);
        build(a, v*2+2, tm+1, tr);
        t[v] = t[v*2+1]+t[v*2+2];
       
    }
    // cout<<v<<":  "<<t[v]<<" ";
}

ll querie(ll v, ll tl, ll tr, ll l, ll r) {
    //outside the range
    if(r<tl || tr<l)
    return 0;
    //inside the range
    if(l<=tl && tr<=r)
    return t[v];
    //partially present in range
    ll tm=(tl+tr)/2;
     ll p1=querie(v*2+1, tl, tm, l,r);
     ll p2=querie(v*2+2, tm+1, tr, l, r);
     return p1+p2;

   
}

void update(ll v, ll tl, ll tr, ll pos, ll new_val) {
    if (tl == tr) {
        t[v] = new_val;
    } else {
        ll tm = (tl + tr) / 2;
        if (pos <= tm)
            update(v*2+1, tl, tm, pos, new_val);
        else
            update(v*2+2, tm+1, tr, pos, new_val);
        t[v] = t[v*2+1] + t[v*2+2];
    }
}


int main(){
  cin>>n;
  t.resize(4*n+1,0);
  vector<int> v(n);
  for(int i=0;i<n;i++){
      
      cin>>v[i]; 
  }
  int p[n];
  for(int i=0;i<n;i++)
  p[i]=1;
  build(p,0,0,n-1);
  for(int i=0;i<n;i++){
     int x;
        cin >> x;
        int lo = 0, hi = n - 1;
        while(lo!=hi)
        {
            int mid = (lo+hi)/2;
            int till_mid = querie(0,0,n-1,0,mid);
            if(till_mid > x)
                hi = mid - 1;
            else if(till_mid < x)
                lo = mid + 1;
            else
            {
                if(p[mid]){
                    lo = mid;
                    break;
                }
                else hi = mid - 1;
            }
        }
        p[lo] = 0;
        update(0,0,n-1,lo, 0);
        cout << v[lo] <<' ';
  }

    return 0;
}
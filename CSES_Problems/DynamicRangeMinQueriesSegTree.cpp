#include<bits/stdc++.h>
using namespace std;



int n;
vector<int> t;

void build(int a[], int v, int tl, int tr) {
    if (tl == tr) {
        t[v] = a[tl];
       // cout<<v<<":  "<<t[v]<<" ";
    } else {
        int tm = (tl + tr) / 2;
       // cout<<tm<<" ";
        build(a, v*2+1, tl, tm);
        build(a, v*2+2, tm+1, tr);
        t[v] = min(t[v*2+1],t[v*2+2]);
       
    }
    // cout<<v<<":  "<<t[v]<<" ";
}

int querie(int v, int tl, int tr, int l, int r) {
    //outside the range
    if(r<tl || tr<l)
    return INT_MAX;
    //inside the range
    if(l<=tl && tr<=r)
    return t[v];
    //partially present in range
    int tm=(tl+tr)/2;
     int p1=querie(v*2+1, tl, tm, l,r);
     int p2=querie(v*2+2, tm+1, tr, l, r);
     return min(p1,p2);
}

void update(int v, int tl, int tr, int pos, int new_val) {
    if (tl == tr) {
        t[v] = new_val;
    } else {
        int tm = (tl + tr) / 2;
        if (pos <= tm)
            update(v*2+1, tl, tm, pos, new_val);
        else
            update(v*2+2, tm+1, tr, pos, new_val);
        t[v] = min(t[v*2+1],t[v*2+2]);
    }
}

int main(){
  cin>>n;
  int q;
  cin>>q;
  int a[n];
  for(int i=0;i<n;i++)
  cin>>a[i];
  t.resize(4*n+1,INT_MAX);
  build(a,0,0,n-1);
 
  while (q--){
      int p,l,r;
      cin>>p>>l>>r;
      if(p==1){
          update(0,0,n-1,l-1,r);
      }
      else
      {int ans=querie(0, 0, n-1, l-1, r-1);
      cout<<ans<<"\n";}
  }
  
  

    return 0;
}

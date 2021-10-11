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
        t[v] = max(t[v*2+1],t[v*2+2]);
       
    }
    // cout<<v<<":  "<<t[v]<<" ";
}


void updateQuerie(int v, int tl, int tr, int val) {
    if (tl == tr) {
        t[v]-= val;
        cout<<tl+1<<" ";
    } else {
        int tm = (tl + tr) / 2;
        if (t[v*2+1]>=val)
            updateQuerie(v*2+1, tl, tm, val);
        else
            updateQuerie(v*2+2, tm+1, tr, val);
        t[v] = max(t[v*2+1],t[v*2+2]);
    }
}

int main(){
  cin>>n;
  int q;
  cin>>q;
  int a[n];
  for(int i=0;i<n;i++)
  cin>>a[i];
  t.resize(4*n+1,0);
  build(a,0,0,n-1);
 
  while (q--){
      int p;
      cin>>p;
      if (t[0] < p) cout << "0 ";
      else
      updateQuerie(0,0,n-1,p);
      
  }
  
  

    return 0;
}

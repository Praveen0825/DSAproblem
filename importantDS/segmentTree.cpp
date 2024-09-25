#include<bits/stdc++.h>
using namespace std;

int MAXN=200001;

int n, t[4*MAXN];

void build(int a[], int v, int tl, int tr) {
    if (tl == tr) {
        t[v] = a[tl];
    } else {
        int tm = (tl + tr) / 2;
        build(a, v*2+1, tl, tm);
        build(a, v*2+2, tm+1, tr);
        t[v] = t[v*2+1] + t[v*2+2];
    }
}

int sum(int v, int tl, int tr, int l, int r) {
    //outside the range
    if(r<tl || tr<l)
    return 0;
    //inside the range
    if(l<=tl && tr<=r)
    return t[v];
    //partially present in range
    int tm=(tl+tr)/2;
     return sum(v*2+1, tl, tm, l,r)
           + sum(v*2+2, tm+1, tr, l, r);

   /* if (l > r) 
        return 0;
    if (l == tl && r == tr) {
        return t[v];
    }
    int tm = (tl + tr) / 2;
    return sum(v*2, tl, tm, l, min(r, tm))
           + sum(v*2+1, tm+1, tr, max(l, tm+1), r);*/
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
        t[v] = t[v*2+1] + t[v*2+2];
    }
}

int main(){


    return 0;
}
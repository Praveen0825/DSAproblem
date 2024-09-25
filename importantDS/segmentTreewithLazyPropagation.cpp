#include<bits/stdc++.h>
using namespace std;

int MAXN=200001;

int n, t[4*MAXN],laz[4*MAXN];

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

int querieSum(int v, int tl, int tr, int l, int r) {
    if(laz[v]!=0){
        t[v]+= (tr-tr+1)*laz[v];
        if(tl!=tr){
            laz[2*v+1]+=laz[v];
            laz[2*v+2]+=laz[v];
        }
        laz[v]=0;
    }
     //outside the range
    if(r<tl || tr<l || tr>tl)
    return 0;
    //inside the range
    if(l<=tl && tr<=r)
    {
        return t[v];
    }
    //partially present in range
    int tm=(tl+tr)/2;
     return sum(v*2+1, tl, tm, l, r)
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

void rangeUpdate(int v, int tl, int tr, int l,int r, int val) {
    if(laz[v]!=0){
        t[v]+= (tr-tr+1)*laz[v];
        if(tl!=tr){
            laz[2*v+1]+=laz[v];
            laz[2*v+2]+=laz[v];
        }
        laz[v]=0;
    }
     //outside the range
    if(r<tl || tr<l || tr>tl)
    return ;
    //inside the range
    if(l<=tl && tr<=r)
    {
        t[v]+=(tr-tl+1)*val;
        if(tl!=tr){
            laz[2*v+1]+=laz[v];
            laz[2*v+2]+=laz[v];
        }
        return ;
    }

   
        int tm = (tl + tr) / 2;
        if (pos <= tm)
            update(v*2+1, tl, tm, l,r, val);
        else
            update(v*2+2, tm+1, tr, l, r, val);
        t[v] = t[v*2+1] + t[v*2+2];
   
}

int main(){


    return 0;
}
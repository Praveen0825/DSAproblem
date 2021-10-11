#include<bits/stdc++.h>
using namespace std;
#define ll long long

ll findSmallest(ll arr[], ll n)
{
   ll res = 1; 
 
   for (ll i = 0; i < n && arr[i] <= res; i++)
       res = res + arr[i];
 
   return res;
}

int main(){
 ll n;
 cin>>n;
 ll a[n];
 for(ll i=0;i<n;i++){
     cin>>a[i];
 }
sort(a,a+n);
ll ans=findSmallest(a,n);
cout<<ans;

return 0;
}
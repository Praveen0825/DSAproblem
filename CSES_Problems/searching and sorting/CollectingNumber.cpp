#include<bits/stdc++.h>
using namespace std ;
int main(){
  int n,ans=1 ;
  cin >> n ;
  vector<int>a(n),b(n+1,1);
  for(int &x:a)
    cin >> x ;
  b[a[0]]=0 ;
  for(int i=1;i<n;i++)
    ans+=b[a[i]-1],b[a[i]]=0 ;
  cout << ans  ;
}
#include<bits/stdc++.h>
using namespace std ;
int main(){
  int n,ans=1 ;
  cin >> n ;
  vector<int>a(n),b(n+1);
  for(int &x:a)
    cin >> x ;
    for(int i=0;i<n;i++){
      b[a[i]]=i;
    }
    int l=0;
 
  for(int i=1;i<=n;i++)
   { if(l>b[i])
        ans++;
        l=b[i];
    }
  cout << ans  ;
}

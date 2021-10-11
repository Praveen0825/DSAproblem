#include <bits/stdc++.h>

using namespace std;
#define ll long long
const int MAX_N = 2e5;

/*	
 * Variables used for the current problem
 * n: number of applicants
 * m: number of apartments
 * k: max diff between desired and actual size
 * a and b: arrays for applicants and apartments respectively
 */



int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	ll n,x;
    cin>>n>>x;
    vector<ll> a(n);
    for(ll i=0;i<a.size();i++)cin>>a[i];
    sort(a.begin(),a.end());
    ll i=0,j=n-1;
    ll ans=0;
    while(i<=j){
        if(a[i]+a[j]>x){
          ans++;
          j--;
        }
        else
        {
            ans++;
            i++;
            j--;
        }
    }
    cout<<ans;
	return 0;
}
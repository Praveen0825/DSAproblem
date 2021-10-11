#include <bits/stdc++.h>

using namespace std;
#define ll long long

int main(){
    ll n,sum;cin>>n>>sum;
    vector<ll>v(n);
    for(int i=0;i<n;++i)
    	cin>>v[i];
    ll m=0,cnt=0;
    map<ll,ll>mp;
    for(int i=0;i<n;++i)
    {
    	m+=v[i];
    	if(m==sum)cnt++;
    	if(mp.count(m-sum))
    	{
    		cnt+=mp[m-sum];
		}
		mp[m]++;
	}
	cout<<cnt<<endl;
    return 0;
}
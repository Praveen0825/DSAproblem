







#include<bits/stdc++.h>
#define ll long long
#define vi vector<ll> 
#define ld long double
#define s second
#define f first
#define pb push_back
const ll abcd=1e9+7;
using namespace std;
/*long long binpow(long long a, long long b) {
    a %= abcd;
    long long res = 1;
    while (b > 0) {
        if (b & 1)
            res = res * a % abcd;
        a = a * a % abcd;
        b >>= 1;
    }
    return res;
}*/
ll binpow(ll x,ll y)
{
	if(y==0)
	return 1;
	if(y==1)
	return x;
	if(y%2==0)
	{
		ll p=binpow(x,y/2);
		return (p*p)%abcd;
	}
	ll p=binpow(x,(y-1)/2);
	p*=p;
	p%=abcd;
	p*=x;
	p%=abcd;
	return p;
}

ll int fun1(ll n,ll k,ll i)
{
	if(i>k)
	return 1;
	ll int x=binpow(2,n-1);
	return ((1+x)*fun1(n,k,i+1))%abcd;
}
ll int fun2(ll n,ll k,ll i)
{
	if(i>k)
	return 1;
	ll int x=binpow(2,n*(k-i));
	return (x+((binpow(2,n-1)-1)*fun2(n,k,i+1))%abcd)%abcd;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll t;
    cin>>test;
    while(test--)
    {
    	ll n,qer;
    	cin>>n>>qer;

    	if(n%2!=0)
    	{
    		cout<<fun1(n,qer,1)<<"\n";
		}
		else
		{
			cout<<fun2(n,qer,1)<<"\n";
		}
	}
    return 0;
}
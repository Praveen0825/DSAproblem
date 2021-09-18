#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define F first;
#define PB push_back;
#define MP make_pair;
#define mod 1000000007

//using ll = long long;
//using ld = long double;
//__int128_t

int main()
{
	int n;
	cin>>n;
	int arr[n][n];
	
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		cin>>arr[i][j];
	}
	
	int k;
	cin>>k;
	while(k--)
	{
		int u, v, wt;
		cin>>u>>v>>wt;
		u--, v--;
		arr[u][v] = min(arr[u][v], wt);
		arr[v][u] = min(arr[v][u], wt);
		

		for(int i=0;i<n;i++)
		{
			for(int j=0;j<n;j++)
			{
					arr[i][j] = min(arr[i][j], arr[i][u]+arr[u][j]);
			}
		}
		
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<n;j++)
			{
					arr[i][j] = min(arr[i][j], arr[i][v]+arr[v][j]);
			}
		}
		
		
		

		ll sum=0;
		for(int i=0;i<n;i++)
		{
			for(int j=i+1;j<n;j++)
			{
				sum+=arr[i][j];
			}
		}
		cout<<sum<<" ";
	}
}
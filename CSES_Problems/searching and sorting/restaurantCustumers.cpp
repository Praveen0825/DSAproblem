#include<bits/stdc++.h>

using namespace std;
#define ll long long
const int MAX_N = 2e5;



int main(){
	ios_base::sync_with_stdio(false);
	//cin.tie(nullptr);
	int n;
    cin>>n;
    map<int,int> mp;
    int ar[n][2];
    for(int i=0;i<n;i++){
        cin>>ar[i][0]>>ar[i][1];
        mp[ar[i][0]]=1;
        mp[ar[i][1]]=1;
    }
    int k=0;
     map<int, int>::iterator it;
   for(it = mp.begin(); it != mp.end(); ++it){
      // cout<<k<<" ";
      it->second=k;
      k++;
   }
   int m=mp.size();
   vector<int> v(m+1,0);
   for(int i=0;i<n;i++){
       v[mp[ar[i][0]]]++;
       if(mp[ar[i][1]]<m)
       v[mp[ar[i][1]]]--;
   }
   int ans=0;
   //cout<<v[0]<<" ";
   for(int i=1;i<=m;i++) 
   {   
      v[i]=v[i-1]+v[i];
      ans=max(ans,v[i]);
      //cout<<v[i]<<" ";
   }

    cout<<ans;
	return 0;
}
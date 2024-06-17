#include<bits/stdc++.h>
using namespace std;

void permute(long p[],long n, int l, int r,vector<int>& ar ) { 
	int i; 
	if (l == r) {
            long z=1,s=0;
            for(int i=0;i<n;i++){
            s+=p[i]/z;
            z=z*2;}
          ar.push_back(s); } 
	else{ 
		for (i = l; i <= r; i++) 
		{ 
			swap(p[l], p[i]); 
			permute(p,n, l+1, r,ar); 
			swap(p[l], p[i]);  
		}  } 
} 
void solution(long n,long p[],long q,long quer[],long ans[]){
        sort(p,p+n,greater<int>());
          vector<int> ar;
          permute(p,n,0,n-1,ar);
          sort(ar.begin(),ar.end());
          for(int i=0;i<q;i++){
             long it=lower_bound(ar.begin(),ar.end(),quer[i])-ar.begin();
             ans[i]=n-i;
          }  }



int main(){
    return 0;
}
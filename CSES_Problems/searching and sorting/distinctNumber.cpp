#include<bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n;
    cin>>n;
    set<int> s;
    for(int i=0;i<n;i++){
        int a;
        cin>>a;
        s.insert(a);
    }
    cout<<s.size();
    return 0;
}
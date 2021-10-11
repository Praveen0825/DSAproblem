#include <bits/stdc++.h>

using namespace std;

int N;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
        
      int n;cin>>n;
    vector<int>v(n);
    for(int i=0;i<n;++i)
    {
    	cin>>v[i];
	}
	stack<int>s;
	for(int i=0;i<n;++i)
	{	
		while(!s.empty() and v[s.top()]>=v[i])
		{
			s.pop();
		}
		if(s.empty())
		{
			cout<<0<<" ";
		}
		else
		{
			cout<<s.top()+1<<" ";
		}
		s.push(i);
	}

	/*cin >> N;
	stack<pair<int, int>> stack;
	stack.push({0, 0});

	for(int i = 1; i <= N; ++i) {
		int a; cin >> a;
		while(!stack.empty() && stack.top().first >= a) stack.pop();
		cout << stack.top().second << " ";
		stack.push({a, i});
	}*/
    return 0;
}
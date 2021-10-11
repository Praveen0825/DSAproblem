#include <iostream>
#include <vector>

using namespace std;


int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int N;
	cin >> N;

	vector<long long> M(N);
	long long psums = 0;
	M[psums] = 1;
	for (int i = 0; i < N; i++) {
		int a;
		cin >> a;
		psums += a;
		// Remember to account for negative sums
		M[(psums % N + N) % N]++;
	}

	long long ans = 0;
	for (long long x : M) {
		/*
		 * Calculating the # of pairs.
		 * This calculates the pairs without
		 * duplicates and reverse groups.
		 */
		ans += x * (x - 1) / 2;
	}
	cout << ans << endl;
}
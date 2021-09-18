#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using cd = complex<ld>;

const int N = 50000;

bool isPrime[N];
vector<int> primes;

void precalc() {
  fill(isPrime + 2, isPrime + N, true);
  for (int i = 2; i * i < N; i++) {
    for (int j = i * i; j < N; j += i) {
      isPrime[j] = false;
    }
  }
  for (int i = 2; i < N; i++) {
    if (isPrime[i]) {
      primes.push_back(i);
    }
  }
}

int calcPrime(int n) {
  int res = 0;
  for (int i : primes) {
    if (i * i > n) {
      break;
    }
    while (n % i == 0) {
      n /= i;
      res++;
    }
  }
  if (n > 1) {
    res++;
  }
  return res;
}
int main(){
     precalc();
    int n;
    cout<<"enter number:";
    cin>>n;
     cout<<calcPrime(n)<<"\n";
  return 0;

}
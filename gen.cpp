#include <bits/stdc++.h>
using namespace std;

#define int long long
#define accuracy chrono::steady_clock::now().time_since_epoch().count()

mt19937 rng(accuracy);

int rand(int l, int r) {
  uniform_int_distribution<int> ludo(l, r);
  return ludo(rng);
}

signed main() {
  srand(accuracy);
  int t = 1;
  // t = rand(1, 10), cout << t << '\n';
	while (t--) {
		int N = 1e5;
		int a = rand(0, N), b = rand(0, N);
		cout << a << ' ' << b << '\n';
	}
}

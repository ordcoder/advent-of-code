#include <bits/stdc++.h>
using namespace std;

int main() {
	uint64_t n, ans = 0;
	while (cin >> n) {
		for (int t = 0; t < 2000; ++t) {
			n = (n ^ (n <<  6)) % 16777216;
			n = (n ^ (n >>  5)) % 16777216;
			n = (n ^ (n << 11)) % 16777216;
		}
		ans += n;
	}
	cout << ans << '\n';
}

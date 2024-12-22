#include <bits/stdc++.h>
using namespace std;

int main() {
	int64_t n, ans = 0;
	unordered_map<int, int64_t> ban, ana;
	while (cin >> n) {
		int p = n % 10, h = 0;
		for (int t = 0; t < 2000; ++t) {
			n = (n ^ (n <<  6)) % 16777216;
			n = (n ^ (n >>  5)) % 16777216;
			n = (n ^ (n << 11)) % 16777216;
			h = (h * 20 + n % 10 - p + 10) % 160000;
			if (t > 2) ban.emplace(h, n % 10);
			p = n % 10;
		}
		for (const auto [k, v]: ban) ana[k] += v;
		ban.clear();
	}
	for (const auto [_, v]: ana) ans = max(ans, v);
	cout << ans << '\n';
}

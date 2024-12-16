#include <bits/stdc++.h>
using namespace std;

int main() {
	unordered_map<int64_t, int64_t> cnt0, cnt1;
	int64_t a;
	while (cin >> a) ++cnt0[a];
	for (int t = 0; t < 75; ++t) {
		cnt1.clear();
		for (const auto [k, v]: cnt0) {
			if (k == 0) {
				cnt1[1] += v;
				continue;
			}
			assert(k > 0);
			int64_t ten = 1;
			while (ten * ten * 10 <= k) ten *= 10;
			if (ten * ten <= k) {
				cnt1[k * 2024] += v;
			} else {
				cnt1[k / ten] += v;
				cnt1[k % ten] += v;
			}
		}
		swap(cnt0, cnt1);
	}
	int64_t ans = 0;
	for (const auto [k, v]: cnt0) ans += v;
	cout << ans << '\n';
}

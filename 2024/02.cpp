#include <bits/stdc++.h>
using namespace std;

bool safe_inc(span<int64_t> r) {
	for (size_t i = 1; i < r.size(); ++i) {
		if (!(r[i-1] < r[i] && r[i] <= r[i-1] + 3)) {
			return false;
		}
	}
	return true;
}

bool safe_dec(span<int64_t> r) {
	for (size_t i = 1; i < r.size(); ++i) {
		if (!(r[i-1] > r[i] && r[i] >= r[i-1] - 3)) {
			return false;
		}
	}
	return true;
}

int main() {
	string s;
	int64_t ans = 0;
	while (getline(cin, s)) {
		istringstream ss(s);
		vector<int64_t> r;
		copy(istream_iterator<int64_t>(ss), istream_iterator<int64_t>(), back_inserter(r));
		bool ok = false;
		for (size_t i = 0; i <= r.size(); ++i) {
			vector<int64_t> rr(r);
			if (i < rr.size()) rr.erase(begin(rr) + i);
			if (safe_inc(rr) || safe_dec(rr)) {
				ok = true;
				break;
			}
		}
		if (ok) ++ans;
	}
	cout << ans << '\n';
}

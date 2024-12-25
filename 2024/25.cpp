#include <bits/stdc++.h>
using namespace std;

int main() {
	vector<vector<int>> keys, locks;
	while (true) {
		vector<int> kl(5, -1);
		bool iskey = false;
		for (string s; getline(cin, s) && !s.empty();) {
			iskey = s == "#####";
			for (int i = 0; i < 5; ++i) kl[i] += s[i] == '#';
		}
		if (kl[0] < 0) break;
		(iskey ? keys : locks).emplace_back(move(kl));
	}
	int ans = 0;
	for (const auto &key: keys) for (const auto &lock: locks) {
		bool ok = true;
		for (int i = 0; i < 5; ++i) if (key[i] + lock[i] > 5) ok = false;
		ans += ok;
	}
	cout << ans << '\n';
}

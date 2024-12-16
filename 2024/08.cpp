#include <bits/stdc++.h>
using namespace std;

int main() {
	vector<string> m;
	vector<pair<int, int>> ant[128];
	string s;
	while (getline(cin, s)) {
		for (int x = 0; x < int(s.size()); ++x) {
			if (s[x] != '#') ant[uint8_t(s[x])].emplace_back(int(m.size()), x);
		}
		m.emplace_back(move(s));
	}

	vector<string> node(m);
	for (uint8_t c = 0; c < 128; ++c) {
		for (auto it = cbegin(ant[c]); it != cend(ant[c]); ++it) {
			for (auto jt = it + 1; jt != cend(ant[c]); ++jt) {
				int y = it->first, x = it->second;
				while (0 <= y && y < int(m.size()) && 0 <= x && x < int(m[y].size())) {
					node[y][x] = c;
					y += it->first - jt->first;
					x += it->second - jt->second;
				}
				y = jt->first; x = jt->second;
				while (0 <= y && y < int(m.size()) && 0 <= x && x < int(m[y].size())) {
					node[y][x] = c;
					y += jt->first - it->first;
					x += jt->second - it->second;
				}
			}
		}
	}

	int ans = 0;
	for (const string &n: node) for (char c: n) if (c != '.') ++ans;
	cout << ans << '\n';
}

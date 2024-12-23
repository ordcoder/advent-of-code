#include <bits/stdc++.h>
using namespace std;

bool con[26*26][26*26];

int enc(const char *s) {
	return 26 * (s[0] - 'a') + s[1] - 'a';
}

string dec(int e) {
	return string{char('a' + e / 26), char('a' + e % 26)};
}

struct Vcomp {
	bool operator()(const vector<int> &v0, const vector<int> &v1) const {
		return v0.size() != v1.size() ? v0.size() < v1.size() : v0 < v1;
	}
};

int main() {
	string s;
	while (cin >> s) {
		int fr = enc(s.data()), to = enc(s.data() + 3);
		con[fr][to] = con[to][fr] = true;
	}
	set<vector<int>, Vcomp> comp{vector<int>{}};
	vector<int> ans;
	for (auto it = begin(comp); it != end(comp); it = comp.erase(it)) {
		const vector<int> &c = *it;
		if (c.size() > ans.size()) ans = c;
		for (int a = 0; a < 26 * 26; ++a) {
			bool ok = true;
			for (int b: c) if (!con[a][b]) { ok = false; break; }
			if (!ok) continue;
			vector<int> d(c.size() + 1);
			copy(begin(c), end(c), begin(d));
			d.back() = a;
			sort(begin(d), end(d));
			comp.emplace(move(d));
		}
	}
	for (int a: ans) cout << dec(a) << ',';
	cout << '\n';
}

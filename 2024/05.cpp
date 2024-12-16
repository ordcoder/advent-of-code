#include <bits/stdc++.h>
using namespace std;

unordered_set<int> vis;
vector<pair<int, int>> rules;
unordered_map<int, vector<int>> inc;
vector<int> ord;
unordered_map<int, int> revord;
vector<int> pages;
unordered_map<int, int> pos;

void dfs(int n) {
	if (vis.count(n)) return;
	if (pos.find(n) == end(pos)) return;
	for (int ri: inc[n]) {
		dfs(rules[ri].first);
	}
	revord[n] = int(ord.size());
	ord.emplace_back(n);
	vis.insert(n);
}

int main() {
	string s;
	while (getline(cin, s)) {
		if (s.size() == 0) break;
		istringstream ss(s);
		int l, r;
		ss >> l >> r;
		inc[r].emplace_back(int(rules.size()));
		rules.emplace_back(l, r);
	}

	int64_t ans = 0;
	while (getline(cin, s)) {
		istringstream ss(s);
		pages.clear();
		pos.clear();
		int p;
		while (ss >> p) {
			pos[p] = int(pages.size());
			pages.emplace_back(p);
		}

		bool ok = true;
		for (const auto &r: rules) {
			auto li = pos.find(r.first);
			auto ri = pos.find(r.second);
			if (li != end(pos) && ri != end(pos) && li->second >= ri->second) {
				ok = false;
				break;
			}
		}

		if (!ok) {
			vis.clear();
			ord.clear();
			revord.clear();
			for (int p: pages) dfs(p);
			assert(pages.size() == ord.size());
			ans += ord[ord.size() / 2];
		}
	}
	cout << ans << '\n';
}

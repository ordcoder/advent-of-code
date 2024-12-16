#include <bits/stdc++.h>
using namespace std;

vector<string> m;
const size_t dy[4] = {size_t(-1), 0, 1, 0}, dx[4] = {0, size_t(-1), 0, 1};

int64_t bfs(vector<vector<int64_t>> &vis, size_t i, size_t j) {
	vis[i][j] = 1;
	queue<pair<size_t, size_t>> q;
	q.emplace(i, j);
	int64_t res = 0;
	while (!q.empty()) {
		i = q.front().first;
		j = q.front().second;
		q.pop();
		if (m[i][j] == '0') {
			res += vis[i][j];
			continue;
		}
		for (int d = 0; d < 4; ++d) {
			size_t ti = i + dy[d], tj = j + dx[d];
			if (ti >= m.size() || tj >= m[ti].size() || m[ti][tj] + 1 != m[i][j]) continue;
			if (vis[ti][tj] == 0) q.emplace(ti, tj);
			vis[ti][tj] += vis[i][j];
		}
	}
	return res;
}

int main() {
	string s;
	while (getline(cin, s)) {
		m.emplace_back(move(s));
	}

	int64_t ans = 0;
	for (size_t i = 0; i < m.size(); ++i) for (size_t j = 0; j < m[i].size(); ++j) if (m[i][j] == '9') {
		vector<vector<int64_t>> vis(m.size(), vector<int64_t>(m[i].size(), 0));
		ans += bfs(vis, i, j);
	}
	cout << ans << '\n';
}

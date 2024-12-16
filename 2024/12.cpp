#include <bits/stdc++.h>
using namespace std;

const int dy[4] = {-1, 0, 1, 0}, dx[4] = {0, -1, 0, 1};
vector<string> m;
vector<vector<int8_t>> vis;

void dfs(int y, int x, int64_t &area, int64_t &perim) {
	assert(!vis[y][x]);
	vis[y][x] = 1;
	++area;
	for (int d = 0; d < 4; ++d) {
		int ny = y + dy[d], nx = x + dx[d];
		if (ny < 0 || ny >= int(m.size()) || nx < 0 || nx >= int(m[ny].size()) || m[ny][nx] != m[y][x]) {
			if (y > 0 && m[y-1][x] == m[y][x] && (ny-1 < 0 || nx < 0 || nx >= int(m[ny-1].size()) || m[ny-1][nx] != m[y][x])) continue;
			if (x > 0 && m[y][x-1] == m[y][x] && (ny < 0 || ny >= int(m.size()) || nx-1 < 0 || m[ny][nx-1] != m[y][x])) continue;
			++perim;
		} else if (!vis[ny][nx]) {
			dfs(ny, nx, area, perim);
		}
	}
}

int main() {
	string s;
	while (getline(cin, s)) m.emplace_back(move(s));
	vis.resize(m.size(), vector<int8_t>(m[0].size(), 0));
	int64_t ans = 0;
	for (int y = 0; y < int(m.size()); ++y) {
		for (int x = 0; x < int(m[y].size()); ++x) {
			if (vis[y][x]) continue;
			int64_t area = 0, perim = 0;
			dfs(y, x, area, perim);
			ans += area * perim;
		}
	}
	cout << ans << '\n';
}

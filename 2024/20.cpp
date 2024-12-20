#include <bits/stdc++.h>
using namespace std;

const int dy[4] = {-1, 0, 1, 0}, dx[4] = {0, -1, 0, 1};
vector<string> m;

void bfs(int y, int x, vector<vector<int>> &dist) {
	dist[y][x] = 0;
	queue<pair<int, int>> q;
	q.emplace(y, x);
	while (!q.empty()) {
		tie(y, x) = q.front();
		q.pop();
		for (int d = 0; d < 4; ++d) {
			int ny = y + dy[d], nx = x + dx[d];
			if (m[ny][nx] == '#' || dist[y][x] + 1 >= dist[ny][nx]) continue;
			dist[ny][nx] = dist[y][x] + 1;
			q.emplace(ny, nx);
		}
	}
}

int main() {
	copy(istream_iterator<string>(cin), istream_iterator<string>(), back_inserter(m));
	int sy = 0, sx = 0, ey = 0, ex = 0;
	for (int i = 0; i < int(m.size()); ++i) for (int j = 0; j < int(m[i].size()); ++j) {
		if (m[i][j] == 'S') tie(sy, sx) = tie(i, j);
		else if (m[i][j] == 'E') tie(ey, ex) = tie(i, j);
	}
	assert(m[sy][sx] == 'S' && m[ey][ex] == 'E');
	vector<vector<int>> sdist(m.size(), vector<int>(m[0].size(), INT_MAX/4));
	vector<vector<int>> edist(sdist);
	bfs(sy, sx, sdist);
	bfs(ey, ex, edist);
	int t = sdist[ey][ex];
	assert(t < INT_MAX/4 && t == edist[sy][sx]);
	int ans = 0;
	for (int y = 0; y < int(m.size()); ++y) for (int x = 0; x <int(m[y].size()); ++x) {
		for (int ny = max(0, y - 20); ny < min(int(m.size()), y + 21); ++ny)
		for (int nx = max(0, x - 20 + abs(ny - y)); nx < min(int(m[ny].size()), x + 21 - abs(ny - y)); ++nx) {
			int nt = sdist[y][x] + abs(ny - y) + abs(nx - x) + edist[ny][nx];
			if (nt + 100 <= t) ++ans;
		}
	}
	cout << ans << '\n';
}

#include <bits/stdc++.h>
using namespace std;

const int dx[4] = {0, -1, 0, 1}, dy[4] = {-1, 0, 1, 0};
int sz;

pair<int, int> getp(int x, int y, vector<vector<pair<int, int>>> &par) {
	if (par[x][y] == make_pair(x, y)) return make_pair(x, y);
	return par[x][y] = getp(par[x][y].first, par[x][y].second, par);
}

void unite(int x, int y, int nx, int ny, vector<vector<pair<int, int>>> &par) {
	if (rand() & 1) {
		swap(x, nx);
		swap(y, ny);
	}
	auto [px, py] = getp(x, y, par);
	par[px][py] = getp(nx, ny, par);
}

void dfs(int x, int y, vector<vector<int>> &vis, vector<vector<pair<int, int>>> &par) {
	vis[x][y] = 1;
	for (int d = 0; d < 4; ++d) {
		int nx = x + dx[d], ny = y + dy[d];
		if (nx < 0 || nx >= sz || ny < 0 || ny >= sz || vis[nx][ny]) continue;
		unite(x, y, nx, ny, par);
		dfs(nx, ny, vis, par);
	}
}

int main() {
	char c;
	int x, y;
	vector<pair<int, int>> obst;
	while (cin >> x >> c >> y) obst.emplace_back(x, y);
	sz = obst.size() == 25 ? 7 : 71;
	int t = obst.size() == 25 ? 12 : 1024;
	vector<vector<int>> vis(sz, vector<int>(sz, numeric_limits<int>::max()/2));
	for (int i = 0; i < t; ++i) vis[obst[i].first][obst[i].second] = -1;
	vis[0][0] = 0;
	queue<pair<int, int>> q;
	q.emplace(0, 0);
	while (!q.empty()) {
		auto [x, y] = q.front();
		q.pop();
		if (x == sz - 1 && y == sz - 1) break;
		for (int d = 0; d < 4; ++d) {
			int nx = x + dx[d], ny = y + dy[d];
			if (nx < 0 || nx >= sz || ny < 0 || ny >= sz || vis[nx][ny] < 0 || vis[nx][ny] <= vis[x][y] + 1) continue;
			vis[nx][ny] = vis[x][y] + 1;
			q.emplace(nx, ny);
		}
	}
	cout << vis[sz - 1][sz - 1] << '\n';

	for (auto &v: vis) v.assign(sz, 0);
	for (auto o: obst) --vis[o.first][o.second];
	vector<vector<pair<int, int>>> par(sz, vector<pair<int, int>>(sz));
	for (int x = 0; x < sz; ++x) for (int y = 0; y < sz; ++y) par[x][y] = make_pair(x, y);
	for (int x = 0; x < sz; ++x) for (int y = 0; y < sz; ++y) if (!vis[x][y]) dfs(x, y, vis, par);
	assert(vis[0][0] > 0 && vis[sz-1][sz-1] > 0);
	assert(getp(0, 0, par) != getp(sz-1, sz-1, par));
	for (int i = int(obst.size()) - 1; i >= 0; --i) {
		int x = obst[i].first, y = obst[i].second;
		assert(vis[x][y] < 0);
		if (++vis[x][y]) continue;
		for (int d = 0; d < 4; ++d) {
			int nx = x + dx[d], ny = y + dy[d];
			if (nx < 0 || nx >= sz || ny < 0 || ny >= sz || vis[nx][ny] < 0) continue;
			unite(x, y, nx, ny, par);
		}
		if (getp(0, 0, par) == getp(sz-1, sz-1, par)) {
			cout << x << ',' << y << '\n';
			break;
		}
	}
}

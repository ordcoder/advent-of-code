#include <bits/stdc++.h>
using namespace std;

const int dx[4] = {0, -1, 0, 1}, dy[4] = {-1, 0, 1, 0};

int main() {
	char c;
	int x, y;
	vector<pair<int, int>> obst;
	while (cin >> x >> c >> y) obst.emplace_back(x, y);
	int sz = obst.size() == 25 ? 7 : 71;
	int t = obst.size() == 25 ? 12 : 1024;
	vector<vector<int>> vis(sz, vector<int>(sz, numeric_limits<int>::max()/2));
	vis[0][0] = 0;
	queue<pair<int, int>> q;
	q.emplace(0, 0);
	while (!q.empty()) {
		auto [x, y] = q.front();
		q.pop();
		if (x == sz - 1 && y == sz - 1) break;
		for (int d = 0; d < 4; ++d) {
			int nx = x + dx[d], ny = y + dy[d];
			if (nx < 0 || nx >= sz || ny < 0 || ny >= sz || vis[nx][ny] <= vis[x][y] + 1) continue;
			if (find(begin(obst), begin(obst) + t, make_pair(nx, ny)) != begin(obst) + t) continue;
			vis[nx][ny] = vis[x][y] + 1;
			q.emplace(nx, ny);
		}
	}
	cout << vis[sz - 1][sz - 1] << '\n';
}

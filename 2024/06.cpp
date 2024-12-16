#include <bits/stdc++.h>
using namespace std;

const int dy[4] = {-1, 0, 1, 0}, dx[4] = {0, 1, 0, -1};

int main() {
	int sy = -1, sx = -1, sd = 0;
	string s;
	vector<string> m;
	while (getline(cin, s)) {
		for (int i = 0; i < int(s.size()); ++i) {
			if (s[i] == '^') {
				assert(sy == -1 && sx == -1);
				sy = int(m.size());
				sx = i;
			}
		}
		m.emplace_back(move(s));
	}
	assert(sy != -1 && sx != -1);

	int ans = 0;
	for (int oy = 0; oy < int(m.size()); ++oy) {
		for (int ox = 0; ox < int(m[oy].size()); ++ox) {
			if (m[oy][ox] != '.') continue;

			vector<vector<char>> vis(m.size());
			for (auto &v: vis) v.resize(m[0].size());
			vis[sy][sx] |= 1 << sd;

			int y = sy, x = sx, d = sd;

			while (true) {
				int ty = y + dy[d], tx = x + dx[d];
				if (ty < 0 || ty >= int(m.size())) break;
				if (tx < 0 || tx >= int(m[ty].size())) break;
				if (m[ty][tx] == '#' || (ty == oy && tx == ox)) {
					d = (d + 1) % 4;
				} else {
					assert(m[ty][tx] == '.' || m[ty][tx] == '^');
					y = ty;
					x = tx;
				}
				if (vis[y][x] & (1 << d)) {
					++ans;
					break;
				}
				vis[y][x] |= 1 << d;
			}
		}
	}

	cout << ans << '\n';
}

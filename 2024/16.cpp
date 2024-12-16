#include <bits/stdc++.h>
using namespace std;

vector<string> m;
vector<int64_t> score;
const int dy[4] = {-1, 0, 1, 0}, dx[4] = {0, -1, 0, 1};
int ey = -1, ex = -1;

struct Pos {
	int y, x, d;
	int enc() const { return d + 4 * (y + int(m.size()) * x); }
	int64_t sc() const { return score[enc()]; }
	bool operator<(const Pos &p) const {
		return make_tuple(sc(), y, x, d) < make_tuple(p.sc(), p.y, p.x, p.d);
	}
};

int64_t dijkstra(int sy, int sx) {
	score.assign(m.size() * m[0].size() * 4, numeric_limits<int64_t>::max() / 2);
	set<Pos> q;
	q.emplace(Pos{sy, sx, 3});
	score[begin(q)->enc()] = 0;
	while (!q.empty()) {
		Pos p = *begin(q);
		q.erase(begin(q));
		if (m[p.y][p.x] == 'E') {
			ey = p.y;
			ex = p.x;
			return p.sc();
		}
		if (m[p.y][p.x] == '#') continue;
		for (const auto &np: {Pos{p.y, p.x, (p.d + 3) % 4}, Pos{p.y, p.x, (p.d + 1) % 4}, Pos{p.y + dy[p.d], p.x + dx[p.d], p.d}}) {
			int64_t ns = p.sc() + (np.d == p.d ? 1 : 1000);
			if (ns >= score[np.enc()]) continue;
			q.erase(np);
			score[np.enc()] = ns;
			q.insert(np);
		}
	}
	assert(!"no end");
	return -1;
}

int64_t dfs(int ey, int ex, int64_t sc) {
	vector<vector<int8_t>> vis(m.size(), vector<int8_t>(m[0].size(), 0));
	int64_t res = 0;
	queue<Pos> q;
	for (int d = 0; d < 4; ++d) {
		Pos p{ey, ex, d};
		score[p.enc()] = sc;
		q.push(p);
	}
	while (!q.empty()) {
		Pos p = q.front();
		q.pop();
		if (vis[p.y][p.x] & (1 << p.d)) continue;
		if (!vis[p.y][p.x]) ++res;
		vis[p.y][p.x] |= 1 << p.d;
		for (const auto &pp: {Pos{p.y, p.x, (p.d + 3) % 4}, Pos{p.y, p.x, (p.d + 1) % 4}, Pos{p.y - dy[p.d], p.x - dx[p.d], p.d}}) {
			int64_t ps = p.sc() - (pp.d == p.d ? 1 : 1000);
			if (m[pp.y][pp.x] == '#') continue;
			if (pp.sc() != ps) continue;
			q.push(pp);
		}
	}
	return res;
}

int main() {
	int sy = -1, sx = -1;
	for (string s; getline(cin, s); m.emplace_back(move(s))) {
		auto it = s.find('S');
		if (it != string::npos) {
			sy = int(m.size());
			sx = int(it);
		}
	}
	assert(sy != -1 && sx != -1);
	int64_t ans = dijkstra(sy, sx);
	cout << ans << '\n';
	ans = dfs(ey, ex, ans);
	cout << ans << '\n';
}

#include <bits/stdc++.h>
using namespace std;

vector<string> m;

bool dfs(int y, int x, int dy, bool commit) {
	assert(m[y][x] == '[');
	assert(m[y][x + 1] == ']');
	if (m[y + dy][x] == '.') {
		if (m[y + dy][x + 1] == '.') {
			if (commit) {
				swap(m[y + dy][x], m[y][x]);
				swap(m[y + dy][x + 1], m[y][x + 1]);
			}
			return true;
		} else if (m[y + dy][x + 1] == '#') {
			assert(!commit);
			return false;
		} else {
			bool b = dfs(y + dy, x + 1, dy, commit);
			if (commit) {
				assert(b);
				assert(m[y + dy][x] == '.' && m[y + dy][x + 1] == '.');
				swap(m[y + dy][x], m[y][x]);
				swap(m[y + dy][x + 1], m[y][x + 1]);
			}
			return b;
		}
	} else if (m[y + dy][x] == '#') {
		assert(!commit);
		return false;
	} else if (m[y + dy][x] == '[') {
		bool b = dfs(y + dy, x, dy, commit);
		if (commit) {
			assert(b);
			assert(m[y + dy][x] == '.' && m[y + dy][x + 1] == '.');
			swap(m[y + dy][x], m[y][x]);
			swap(m[y + dy][x + 1], m[y][x + 1]);
		}
		return b;
	} else if (m[y + dy][x + 1] == '.') {
		bool b = dfs(y + dy, x - 1, dy, commit);
		if (commit) {
			assert(b);
			assert(m[y + dy][x] == '.' && m[y + dy][x + 1] == '.');
			swap(m[y + dy][x], m[y][x]);
			swap(m[y + dy][x + 1], m[y][x + 1]);
		}
		return b;
	} else if (m[y + dy][x + 1] == '#') {
		assert(!commit);
		return false;
	} else {
		bool bl = dfs(y + dy, x - 1, dy, commit);
		bool br = dfs(y + dy, x + 1, dy, commit);
		if (commit) {
			assert(bl && br);
			assert(m[y + dy][x] == '.' && m[y + dy][x + 1] == '.');
			swap(m[y + dy][x], m[y][x]);
			swap(m[y + dy][x + 1], m[y][x + 1]);
		}
		return bl && br;
	}
}

const char dirstr[5] = "<v>^";
const int dy[4] = {0, 1, 0, -1}, dx[4] = {-1, 0, 1, 0};

int main() {
	int y = -1, x = -1;
	for (string s; getline(cin, s) && !s.empty(); m.emplace_back(move(s))) {
		int l = int(s.size());
		s.resize(2 * l);
		for (int i = l - 1; i >= 0; --i) {
			if (s[i] == '#' || s[i] == '.') {
				s[2 * i] = s[2 * i + 1] = s[i];
			} else if (s[i] == 'O') {
				s[2 * i] = '[';
				s[2 * i + 1] = ']';
			} else if (s[i] == '@') {
				y = int(m.size());
				x = 2 * i;
				s[2 * i] = s[i];
				s[2 * i + 1] = '.';
			} else assert(!"bad char");
		}
	}
	assert(y >= 0 && x >= 0);
	for (string s; getline(cin, s);) for (char c: s) {
		int d = strchrnul(dirstr, c) - dirstr;
		assert(d < 4);
		if (dy[d] != 0) {
			int sx = 0;
			switch (m[y + dy[d]][x + dx[d]]) {
			case '#':
				continue;
			case '.':
				break;
			case ']':
				sx = 1; // fallthrough
			case '[':
				if (!dfs(y + dy[d], x + dx[d] - sx, dy[d], false)) continue;
				dfs(y + dy[d], x + dx[d] - sx, dy[d], true);
				break;
			default:
				assert(!"bad char");
			}
			assert(m[y + dy[d]][x + dx[d]] == '.');
			swap(m[y + dy[d]][x + dx[d]], m[y][x]);
			y += dy[d];
			x += dx[d];
			continue;
		}
		int by = y, bx = x;
		do {
			by += dy[d];
			bx += dx[d];
		} while (m[by][bx] == '[' || m[by][bx] == ']');
		if (m[by][bx] != '.') continue;
		for (; by != y || bx != x; (by -= dy[d]), (bx -= dx[d]))
			swap(m[by][bx], m[by - dy[d]][bx - dx[d]]);
		y += dy[d];
		x += dx[d];
	}

	int64_t ans = 0;
	for (int i = 0; i < int(m.size()); ++i) {
		for (int j = 0; j < int(m[i].size()); ++j) {
			if (m[i][j] == '[') ans += 100 * i + j;
		}
	}
	cout << ans << '\n';
}

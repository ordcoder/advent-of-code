#include <bits/stdc++.h>
using namespace std;

const int dy[8] = {1, 1, 1, 0, -1, -1, -1, 0};
const int dx[8] = {1, 0, -1, -1, -1, 0, 1, 1};

vector<string> f;

char at(int y, int x) {
	if (y < 0 || y >= int(f.size())) return '.';
	const string &s = f[y];
	if (x < 0 || x >= int(s.size())) return '.';
	return s[x];
}

int main() {
	string s;
	while (getline(cin, s)) {
		f.emplace_back(move(s));
	}
	int ans = 0;
	for (int y = 1; y + 1 < int(f.size()); ++y) {
		for (int x = 1; x + 1 < int(f[y].size()); ++x) {
			if (f[y][x] != 'A') continue;
			for (int d0: {0, 4}) {
				if (f[y - dy[d0]][x - dx[d0]] != 'M') continue;
				if (f[y + dy[d0]][x + dx[d0]] != 'S') continue;
				for (int d1: {2, 6}) {
					if (f[y - dy[d1]][x - dx[d1]] != 'M') continue;
					if (f[y + dy[d1]][x + dx[d1]] != 'S') continue;
					++ans;
				}
			}
		}
	}
	cout << ans << '\n';
}

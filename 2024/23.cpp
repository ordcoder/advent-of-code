#include <bits/stdc++.h>
using namespace std;

bool con[26*26][26*26];

int enc(const char *s) {
	return 26 * (s[0] - 'a') + s[1] - 'a';
}

int main() {
	string s;
	while (cin >> s) {
		int fr = enc(s.data()), to = enc(s.data() + 3);
		con[fr][to] = con[to][fr] = true;
	}
	int ans = 0;
	for (int a = 26 * ('t' - 'a'); a < 26 * ('u' - 'a'); ++a) {
		for (int b = 0; b < 26 * 26; ++b) {
			if (b / 26 + 'a' == 't' && b <= a) continue;
			for (int c = b + 1; c < 26 * 26; ++c) {
				if (c / 26 + 'a' == 't' && c <= a) continue;
				if (con[a][b] && con[a][c] && con[b][c]) ++ans;
			}
		}
	}
	cout << ans << '\n';
}

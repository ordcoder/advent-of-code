#include <bits/stdc++.h>
using namespace std;

int main() {
	int64_t w, h, n;
	cin >> w >> h >> n;
	assert((w == 101 && h == 103) || (w == 11 && h == 7));
	vector<int64_t> px(n), py(n), vx(n), vy(n);
	int64_t q0 = 0, q1 = 0, q2 = 0, q3 = 0;
	for (int64_t i = 0; i < n; ++i) {
		cin >> px[i] >> py[i] >> vx[i] >> vy[i];
		int64_t x = (px[i] + 100 * vx[i]) % w; if (x < 0) x += w;
		int64_t y = (py[i] + 100 * vy[i]) % h; if (y < 0) y += h;
		if (y < h/2) {
			if (x < w/2) ++q0;
			else if (x > w/2) ++q1;
		} else if (y > h/2) {
			if (x < w/2) ++q2;
			else if (x > w/2) ++q3;
		}
	}
	cout << (q0*q1*q2*q3) << '\n';

	string s;
	for (int t = 0; getline(cin, s); ++t) {
		while (t % w != 69 % w || t % h != 12 % h) ++t;
		cout << t << "\n";
		vector<string> f(h, string(w, '.'));
		for (int64_t i = 0; i < n; ++i) {
			int64_t x = (px[i] + t * vx[i]) % w; if (x < 0) x += w;
			int64_t y = (py[i] + t * vy[i]) % h; if (y < 0) y += h;
			f[y][x] = '*';
		}
		for (const auto &fs: f) cout << fs << "\n";
	}
}

#include <bits/stdc++.h>
using namespace std;

int main() {
	int64_t ans = 0, ax, ay, bx, by, x, y;
	while (cin >> ax >> ay >> bx >> by >> x >> y) {
		x += 10000000000000;
		y += 10000000000000;
		/* a * ax + b * bx = x
		 * a * ay + b * by = y
		 * b * (bx * ay - ax * by) = x * ay - y * ax */
		int64_t rhs = x * ay - y * ax;
		int64_t lhs = bx * ay - ax * by;
		assert(lhs != 0 || rhs != 0);
		if (lhs == 0 && rhs != 0) continue;
		if (rhs % lhs != 0) continue;
		int64_t b = rhs / lhs;
		rhs = ax ? x - b * bx : (ay ? y - b * by : 0);
		lhs = ax ? ax : (ay ? ay : 1);
		if (rhs % lhs != 0) continue;
		int64_t a = rhs / lhs;
		if (a < 0 || b < 0) continue;
		ans += 3 * a + b;
	}
	cout << ans << '\n';
}

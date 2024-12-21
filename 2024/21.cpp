#include <bits/stdc++.h>
using namespace std;

struct Cost { int64_t gul, u, gur, r, gdr, d, gdl, l, ul, ru, rd, dl; } cost[26];

int main() {
	cost[0] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
	for (int i = 1; i < 26; ++i) {
		cost[i].u = cost[i-1].l + cost[i-1].r + 2;
		cost[i].r = cost[i-1].d + cost[i-1].u + 2;
		cost[i].d = cost[i-1].gdl + cost[i-1].gur + 4;
		cost[i].l = cost[i-1].dl + cost[i-1].ru + 6;
		cost[i].ul = cost[i-1].l + cost[i-1].dl + cost[i-1].ru + 6;
		cost[i].ru = cost[i-1].d + cost[i-1].gul + cost[i-1].r + 4;
		cost[i].rd = cost[i-1].d + cost[i-1].l + cost[i-1].gur + 4;
		cost[i].dl = cost[i-1].gdl + cost[i-1].l + cost[i-1].ru + 6;
		cost[i].gul = min(cost[i].ul, cost[i-1].dl + cost[i-1].ru + cost[i-1].r + 6);
		cost[i].gur = min(cost[i].ru, cost[i-1].l + cost[i-1].gdr + cost[i-1].u + 4);
		cost[i].gdr = min(cost[i].rd, cost[i-1].gdl + cost[i-1].r + cost[i-1].u + 4);
		cost[i].gdl = min(cost[i].dl, cost[i-1].dl + cost[i-1].r + cost[i-1].gur + 6);
	}
	string code;
	int64_t ans = 0;
	while (cin >> code) {
		int y = 3, x = 2, icode = -1;
		istringstream ss(code);
		ss >> icode;
		for (char c: code) {
			const char *keypad = "789456123 0A";
			int ty = (strchr(keypad, c) - keypad) / 3, tx = (strchr(keypad, c) - keypad) % 3;
			ans += icode * (abs(ty - y) + abs(tx - x) + 1);
			const Cost &C = cost[25]; // for pt1: cost[2]
			if (ty < y) {
				if (tx < x) ans += icode * (y < 3 || tx > 0 ? C.gul : C.ul);
				else if (tx > x) ans += icode * C.gur;
				else ans += icode * C.u;
			} else if (ty > y) {
				if (tx < x) ans += icode * C.gdl;
				else if (tx > x) ans += icode * (ty < 3 || x > 0 ? C.gdr : C.rd);
				else ans += icode * C.d;
			} else {
				if (tx < x) ans += icode * C.l;
				else if (tx > x) ans += icode * C.r;
			}
			tie(y, x) = make_pair(ty, tx);
		}
	}
	cout << ans << '\n';
}

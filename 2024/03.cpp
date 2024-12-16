#include <bits/stdc++.h>
using namespace std;

int main() {
	int64_t ans = 0;
	char c;
	int64_t p = 0, l = 0, r = 0;
	bool enabled = true;
	while (cin >> c) {
		if (c == 'm') {
			p = 1;
			l = r = 0;
		} else if (c == 'u' && p == 1) {
			p = 2;
		} else if (c == 'l' && p == 2) {
			p = 3;
		} else if (c == '(' && p == 3) {
			p = 4;
		} else if (c >= '0' && c <= '9' && p >= 4 && p <= 6) {
			l = 10 * l + int64_t(c - '0');
			++p;
		} else if (c == ',' && p >= 5 && p <= 7) {
			p = 8;
		} else if (c >= '0' && c <= '9' && p >= 8 && p <= 10) {
			r = 10 * r + int64_t(c - '0');
			++p;
		} else if (c == ')' && p >= 9 && p <= 11) {
			if (enabled) ans += l * r;
			p = 0;
		} else if (c == 'd') {
			p = 100;
		} else if (c == 'o' && p == 100) {
			p = 101;
		} else if (c == '(' && p == 101) {
			p = 102;
		} else if (c == ')' && p == 102) {
			enabled = true;
			p = 0;
		} else if (c == 'n' && p == 101) {
			p = 112;
		} else if (c == '\'' && p == 112) {
			p = 113;
		} else if (c == 't' && p == 113) {
			p = 114;
		} else if (c == '(' && p == 114) {
			p = 115;
		} else if (c == ')' && p == 115) {
			enabled = false;
			p = 0;
		} else {
			p = 0;
		}
	}
	cout << ans << '\n';
}

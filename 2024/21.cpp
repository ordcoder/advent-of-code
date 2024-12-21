#include <bits/stdc++.h>
using namespace std;

const char *key2[8][3] = {
	{"v<<A>>^", "v<A<A>>^", "vAA^<A>A"}, // ul
	{"v<A>^", "<Av<A>>^", "vA^A"}, // ru
	{"v<A>^", "v<<A>>^", "vA^<A>A"}, // rd
	{"v<A<A>>^", "v<<A>>^", "vAA^<A>A"}, // dl
	{"v<A<AA>>^", "vA^<A>", "vA^A"}, // lu?
	{"v<<a>>^", "vA<A>^", "<A>A"}, // ur=
	{"v<A<A>>^", "vA^", "<A>A"}, // dr?
	{"v<A<AA>>^", "vA^", "vA^<A>A"}, // ld?
};
const char *lin2[4][2] = {
	{"v<<A>>^", "vA^A"}, // u
	{"v<A>^", "<A>A"}, // r
	{"v<A<A>>^", "vA^<A>A"}, // d
	{"v<A<AA>>^", "vAA^<A>A"}, // l
};

int y, x, yk1, xk1, yk0, xk0, slen;
string out;

void interp(char c, int ri, int &ry, int &rx) {
	switch (c) {
	case 'A': if (ri == 2) {
		out.push_back("789456123 0A"[3*ry+rx]);
	} else {
		interp(" ^A<v>"[3*ry+rx], ri+1, (ri ? y : yk1), (ri ? x : xk1));
	}; break;
	case '^': --ry; break;
	case '<': --rx; break;
	case 'v': ++ry; break;
	case '>': ++rx; break;
	default: assert(!"bad cmd");
	}
	assert(0 <= ry && ry < (ri == 2 ? 4 : 2));
	assert(0 <= rx && rx < 3);
}

void emit(char c, int cnt) {
	while (cnt --> 0) {
		cerr << c;
		++slen;
		interp(c, 0, yk0, xk0);
	}
}
void emit(const char *s) {
	while (*s) emit(*s++, 1);
}
void emit(const char *(&ar)[2], int c) {
	emit(ar[0]); emit('A', c); emit(ar[1]);
}
void emit(const char *(&ar)[3], int c0, int c1) {
	emit(ar[0]); emit('A', c0); emit(ar[1]); emit('A', c1); emit(ar[2]);
}

int main() {
	string code;
	int64_t ans = 0;
	while (cin >> code) {
		istringstream ss(code);
		int ty, tx, icode = -1;
		ss >> icode;
		y = 3; x = 2;
		yk1 = 0; xk1 = 2;
		yk0 = 0; xk0 = 2;
		slen = 0;
		out.clear();
		for (char c: code) {
			if (c >= '1' && c <= '9') {
				ty = 2 - (c - '1') / 3;
				tx = (c - '1') % 3;
			} else if (c == '0') {
				ty = 3;
				tx = 1;
			} else if (c == 'A') {
				ty = 3;
				tx = 2;
			} else assert(!"bad code");
			if (ty < y) {
				if (tx < x) (y < 3 || tx > 0) ? emit(key2[4], x - tx, y - ty) : emit(key2[0], y - ty, x - tx);
				else if (tx > x) emit(key2[1], tx - x, y - ty);
				else emit(lin2[0], y - ty);
			} else if (ty > y) {
				if (tx < x) emit(key2[7], x - tx, ty - y);
				else if (tx > x) (ty < 3 || x > 0) ? emit(key2[6], ty - y, tx - x) : emit(key2[2], tx - x, ty - y);
				else emit(lin2[2], ty - y);
			} else {
				if (tx < x) emit(lin2[3], x - tx);
				else if (tx > x) emit(lin2[1], tx - x);
				else emit('A', 1);
			}
		}
		assert(out == code);
		cerr << ": " << out << "\n";
		ans += icode * slen;
	}
	cout << ans << '\n';
}

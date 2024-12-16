#include <bits/stdc++.h>
using namespace std;

int main() {
	string s;
	uint64_t ans = 0;
	while (getline(cin, s)) {
		istringstream ss(s);
		uint64_t lhs, v;
		char c;
		ss >> lhs >> c >> v;
		assert(c == ':');
		unordered_set<uint64_t> s0, s1;
		s0.insert(v);
		while (ss >> v) {
			for (uint64_t v0: s0) {
				uint64_t v1 = v0 + v;
				if (v1 >= v0 && v1 >= v && v1 <= lhs) s1.insert(v1);
				v1 = v0 * v;
				if (v1 >= v0 && v1 >= v && v1 <= lhs) s1.insert(v1);
				uint64_t ten = 10;
				while (ten <= v) ten *= 10;
				v1 = v0 * ten + v;
				if (v1 >= v0 && v1 >= v && v1 <= lhs) s1.insert(v1);
			}
			swap(s0, s1);
			s1.clear();
		}
		if (s0.count(lhs)) ans += lhs;
	}
	cout << ans << '\n';
}

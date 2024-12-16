#include <bits/stdc++.h>
using namespace std;

int main() {
	int64_t a, b;
	vector<int64_t> v0;
	unordered_map<int64_t, int64_t> v1;
	while (cin >> a >> b) {
		v0.emplace_back(a);
		++v1[b];
	}
	int64_t d = 0;
	for (int64_t a: v0) {
		auto it = v1.find(a);
		if (it == end(v1)) continue;
		d += a * it->second;
	}
	cout << d << '\n';
}

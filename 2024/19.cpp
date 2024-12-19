#include <bits/stdc++.h>
using namespace std;

int main() {
	vector<string> towels;
	string s;
	getline(cin, s);
	istringstream ss(s);
	copy(istream_iterator<string>(ss), istream_iterator<string>(), back_inserter(towels));
	int64_t ans = 0;
	while (cin >> s) {
		vector<int64_t> reach(s.size() + 1);
		reach[0] = 1;
		for (size_t i = 0; i < s.size(); ++i) if (reach[i]) {
			for (const string &t: towels) {
				if (i + t.size() <= s.size() && !s.compare(i, t.size(), t)) {
					reach[i + t.size()] += reach[i];
				}
			}
		}
		ans += reach[s.size()];
	}
	cout << ans << '\n';
}

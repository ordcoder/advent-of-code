#include <bits/stdc++.h>
using namespace std;

int main() {
	string s;
	cin >> s;
	vector<int> disk;
	vector<size_t> file;
	map<int, set<size_t>> space;
	for (int i = 0; 2 * i < int(s.size()); ++i) {
		file.emplace_back(disk.size());
		for (char c = '0'; c < s[2 * i]; ++c) disk.emplace_back(i);
		if (2 * i + 1 >= int(s.size())) break;
		space[int(s[2 * i + 1] - '0')].insert(disk.size());
		for (char c = '0'; c < s[2 * i + 1]; ++c) disk.emplace_back(-1);
	}

	for (int f = int(file.size()) - 1; f >= 0; --f) {
		size_t from = file[f];
		int len = int(s[2 * f] - '0');
		auto lb = space.lower_bound(len);
		if (lb == end(space)) continue;
		assert(!lb->second.empty());
		for (auto it = lb; it != end(space); ++it) {
			assert(!it->second.empty());
			if (*begin(it->second) < *begin(lb->second)) lb = it;
		}
		size_t to = *begin(lb->second);
		if (from <= to) continue;
		int left = lb->first - len;
		for (int i = 0; i < len; ++i) {
			assert(disk[from + i] == f);
			assert(disk[to + i] == -1);
			swap(disk[from + i], disk[to + i]);
		}
		lb->second.erase(to);
		if (lb->second.empty()) space.erase(lb);
		if (left > 0) space[left].insert(to + len);
	}

	uint64_t sum = 0;
	for (size_t i = 0; i < disk.size(); ++i) {
		if (disk[i] < 0) continue;
		sum += i * uint64_t(disk[i]);
	}
	cout << sum << '\n';
}

#include <bits/stdc++.h>
using namespace std;

struct Val {
	int val;
	string typ, lft, rgh;
};
map<string, Val> values;

void eval(Val &v) {
	if (v.val >= 0) return;
	auto l = values.find(v.lft);
	auto r = values.find(v.rgh);
	assert(l != end(values) && r != end(values));
	eval(l->second);
	eval(r->second);
	if (v.typ == "AND") v.val = (l->second.val & r->second.val);
	else if (v.typ == "OR") v.val = (l->second.val | r->second.val);
	else if (v.typ == "XOR") v.val = (l->second.val ^ r->second.val);
	else assert(!"bad typ");
}

int main() {
	string s, nam, arr;
	while (getline(cin, s) && !s.empty()) {
		istringstream ss(s);
		Val v{-1, "LIT", "", ""};
		ss >> nam >> v.val;
		values.emplace(move(nam), move(v));
	}
	while (getline(cin, s)) {
		istringstream ss(s);
		Val v{-1, "", "", ""};
		ss >> v.lft >> v.typ >> v.rgh >> arr >> nam;
		values.emplace(move(nam), move(v));
	}
	for (auto &[_, v]: values) eval(v);
	uint64_t ans = 0, sh = 0;
	for (auto it = values.lower_bound("z"); it != end(values) && it->first[0] == 'z'; ++it) ans |= uint64_t(it->second.val) << sh++;
	cout << ans << '\n';
}

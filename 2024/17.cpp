#include <bits/stdc++.h>
using namespace std;

vector<uint64_t> prg;

bool dfs(size_t i, uint64_t ans) {
	for (uint64_t to = ans + 8; ans < to; ++ans) {
		uint64_t v = (ans & 7) ^ 3;
		uint64_t b = v ^ ((ans >> v) & 7) ^ 5;
		if (b != prg[i]) continue;
		if (!i) return cout << ans << '\n', true;
		if (dfs(i - 1, ans << 3)) return true;
	}
	return false;
}

int main() {
	uint64_t reg[8] = {0, 1, 2, 3, 0, 0, 0, 0}, inst, op, ip = 0;
	for (int i = 4; i < 7; ++i) cin >> reg[i];
	while (cin >> inst) prg.emplace_back(inst);
	while (ip < prg.size()) {
		inst = prg[ip++];
		op = prg[ip++];
		switch (inst) {
		case 0: reg[4] >>= min(reg[op], 63ul); break;
		case 1: reg[5] ^= op; break;
		case 2: reg[5] = reg[op] & 7; break;
		case 3: if (reg[4]) ip = op; break;
		case 4: reg[5] ^= reg[6]; break;
		case 5: cout << (reg[op] & 7) << ','; break;
		case 6: reg[5] = reg[4] >> min(reg[op], 63ul); break;
		case 7: reg[6] = reg[4] >> min(reg[op], 63ul); break;
		default: assert(!"bad inst");
		}
	}
	cout << "\nReg A B C: " << reg[4] << ' ' << reg[5] << ' ' << reg[6] << '\n';
	bool b = dfs(prg.size() - 1, 0);
	assert(b);
}

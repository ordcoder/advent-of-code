#include <bits/stdc++.h>
using namespace std;

int main() {
	uint32_t reg[8] = {0, 1, 2, 3, 0, 0, 0, 0};
	for (int i = 4; i < 7; ++i) cin >> reg[i];
	vector<uint32_t> prg;
	uint32_t inst, op;
	while (cin >> inst >> op) {
		prg.emplace_back(inst);
		prg.emplace_back(op);
	}
	uint32_t ip = 0;
	while (ip < prg.size()) {
		inst = prg[ip++];
		op = prg[ip++];
		switch (inst) {
		case 0: reg[4] >>= reg[op]; break;
		case 1: reg[5] ^= op; break;
		case 2: reg[5] = reg[op] & 7; break;
		case 3: if (reg[4]) ip = op; break;
		case 4: reg[5] ^= reg[6]; break;
		case 5: cout << (reg[op] & 7) << ','; break;
		case 6: reg[5] = reg[4] >> reg[op]; break;
		case 7: reg[6] = reg[4] >> reg[op]; break;
		default: assert(!"bad inst");
		}
	}
	cout << '\n';
	cout << "Reg: " << reg[4] << ' ' << reg[5] << ' ' << reg[6] << '\n';
}

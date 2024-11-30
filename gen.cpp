#include <bits/stdc++.h>
using namespace std;

#define int long long
#define accuracy chrono::steady_clock::now().time_since_epoch().count()

mt19937 rng(accuracy);

int rand(int l, int r) {
  uniform_int_distribution<int> ludo(l, r);
  return ludo(rng);
}

vector<string> atoms = {
	"H", "He", "Li", "Be", "B", "C", "N", "O", "F", "Ne",
	"Na", "Mg", "Al", "Si", "P", "S", "Cl", "Ar", "K", "Ca",
	"Sc", "Ti", "V", "Cr", "Mn", "Fe", "Co", "Ni", "Cu", "Zn",
	"Ga", "Ge", "As", "Se", "Br", "Kr", "Rb", "Sr", "Y", "Zr",
	"Nb", "Mo", "Tc", "Ru", "Rh", "Pd", "Ag", "Cd", "In", "Sn",
	"Sb", "Te", "I", "Xe", "Cs", "Ba", "La", "Ce", "Pr", "Nd",
	"Pm", "Sm", "Eu", "Gd", "Tb", "Dy", "Ho", "Er", "Tm", "Yb",
	"Lu", "Hf", "Ta", "W", "Re", "Os", "Ir", "Pt", "Au", "Hg",
	"Tl", "Pb", "Bi", "Po", "At", "Rn", "Fr", "Ra", "Ac", "Th",
	"Pa", "U", "Np", "Pu", "Am", "Cm", "Bk", "Cf", "Es", "Fm",
	"Md", "No", "Lr", "Rf", "Db", "Sg", "Bh", "Hs", "Mt", "Ds",
	"Rg", "Cn", "Nh", "Fl", "Mc", "Lv", "Ts", "Og"
};

signed main() {
  srand(accuracy);
  int t = 1;
  // t = rand(1, 10), cout << t << '\n';
  while (t--) {
		int k = rand(1, 15), n = rand(k, 15);
		cout << n << ' ' << k << '\n';
		for (int i = 0; i < n; i++) {
			int x = rand(1, 100);
			cout << atoms[x] << ' ';
		}
		cout << '\n';
		for (int i = 0; i < k; i++) {
			int x = rand(1, 100);
			cout << atoms[x] << ' ';
		}
		cout << '\n';
  }
}

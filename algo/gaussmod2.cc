template<typename T>
struct Gauss {
	int bits;
	vector<T> table;
	int rank = 0;  // track rank for efficiency
	vector<T> p; // To store independent vectors after rebuilding
	bool built = false;
	Gauss() : bits(60) {
		table = vector<T>(bits, 0);
	}
	Gauss(int _bits) : bits(_bits) {
		table = vector<T>(bits, 0);
	}
	// Return rank/size of basis
	int basis_size() {
		return rank;
	}
	// Check if x can be obtained from the basis
	bool can(T x) {
		for (int i = bits - 1; i >= 0; i--) {
			if (!(x >> i & 1)) continue;
			if (!table[i]) return false;
			x ^= table[i];
		}
		return true;
	}
	void add(T x) {
		for (int i = bits - 1; i >= 0; i--) {
			if (!(x >> i & 1)) continue;  // Skip if bit i is 0
			if (!table[i]) {
				table[i] = x;
				rank++;
				return;
			}
			x ^= table[i];  // Eliminate this bit using XOR
		}
		// x became 0 (linearly dependent)
	}
	T get_max_xor() {
		T ans = 0;
		for (int i = bits - 1; i >= 0; i--) {
			if ((ans ^ table[i]) > ans) {
				ans ^= table[i];
			}
		}
		return ans;
	}
	void merge(Gauss& other) {
		for (int i = bits - 1; i >= 0; i--) {
			if (other.table[i]) {
				add(other.table[i]);
			}
		}
	}
	// Convert basis to Reduced Row Echelon Form (Diagonalize)
	void rebuild() {
		for (int i = bits - 1; i >= 0; i--) {
			// For each vector table[i], try to eliminate bits j < i
			for (int j = i - 1; j >= 0; j--) {
				// If table[i] has bit j set, and we have a basis vector for j
				if (table[i] && table[j] && (table[i] >> j & 1)) {
					table[i] ^= table[j];
				}
			}
		}

		// Extract non-zero basis vectors into a compact list
		p.clear();
		for (int i = 0; i < bits; i++) {
			if (table[i]) p.push_back(table[i]);
		}
		built = true;
	}
	// Find the k-th smallest distinct XOR sum (1-based index)
	// k=1 returns 0 (if we consider empty set sum)
	T kth_smallest(long long k) {
		if (!built) rebuild();
		if (k > (1LL << p.size())) return -1; 

		k--; // Convert to 0-based for bitwise logic

		T ans = 0;
		for (int i = 0; i < p.size(); i++) {
			// If the i-th bit of k is set, XOR with the i-th basis vector
			if ((k >> i) & 1) {
				ans ^= p[i];
			}
		}
		return ans;
	}
	// Find the k-th largest distinct XOR sum (1-based index)
	T kth_largest(long long k) {
		if (!built) rebuild();
		long long total_count = (1LL << p.size());
		if (k > total_count) return -1;
		return kth_smallest(total_count - k + 1);
	}
};
// Gauss<long long> g(60);
// g.add(x);
// g.get_max_xor();

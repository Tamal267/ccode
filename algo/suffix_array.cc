class SuffixArray {
	private:
		string s;
		int n;
		vector<int> sa, rank, lcp;

		void build_sa() {
			sa.resize(n);
			vector<int> c(n), cnt(n);
			for (int i = 0; i < n; i++) sa[i] = i;
			sort(sa.begin(), sa.end(), [&](int a, int b) {
					return s[a] < s[b];
					});

			c[sa[0]] = 0;
			for (int i = 1; i < n; i++) {
				c[sa[i]] = c[sa[i-1]] + (s[sa[i]] != s[sa[i-1]]);
			}
			for (int k = 0; (1 << k) < n; k++) {
				for (int i = 0; i < n; i++) {
					sa[i] = (sa[i] - (1 << k) + n) % n;
				}
				fill(cnt.begin(), cnt.end(), 0);
				for (int i = 0; i < n; i++) {
					cnt[c[sa[i]]]++;
				}
				for (int i = 1; i < n; i++) {
					cnt[i] += cnt[i-1];
				}
				vector<int> sa_new(n);
				for (int i = n-1; i >= 0; i--) {
					sa_new[--cnt[c[sa[i]]]] = sa[i];
				}
				sa = sa_new;
				vector<int> c_new(n);
				c_new[sa[0]] = 0;
				for (int i = 1; i < n; i++) {
					pair<int, int> prev = {c[sa[i-1]], c[(sa[i-1] + (1 << k)) % n]};
					pair<int, int> curr = {c[sa[i]], c[(sa[i] + (1 << k)) % n]};
					c_new[sa[i]] = c_new[sa[i-1]] + (prev != curr);
				}
				c = c_new;
			}
		}
		// lcp(sa[i], sa[i + 1])
		void build_lcp() {
			rank.resize(n);
			lcp.resize(n);
			for (int i = 0; i < n; i++) {
				rank[sa[i]] = i;
			}
			int k = 0;
			for (int i = 0; i < n; i++) {
				if (rank[i] == n-1) {
					k = 0;
					continue;
				}
				int j = sa[rank[i] + 1];
				while (i + k < n && j + k < n && s[i+k] == s[j+k]) {
					k++;
				}
				lcp[rank[i]] = k;
				if (k > 0) k--;
			}
		}
	public:
		SuffixArray(const string& str) : s(str) {
			n = s.size();
			build_sa();
			build_lcp();
		}

		const vector<int>& get_sa() const { return sa; }
		const vector<int>& get_lcp() const { return lcp; }
		const vector<int>& get_rank() const { return rank; }

		int find(const string& pattern) {
			int m = pattern.size();
			int l = 0, r = n - 1;
			while (l <= r) {
				int mid = (l + r) / 2;
				int cmp = s.compare(sa[mid], min(n - sa[mid], m), pattern);
				if (cmp == 0) return sa[mid];
				else if (cmp < 0) l = mid + 1;
				else r = mid - 1;
			}
			return -1;
		}
		int count_occurrences(const string& pattern) {
			int m = pattern.size();
			// Find lower bound
			int low = 0, high = n - 1;
			while (low <= high) {
				int mid = (low + high) / 2;
				if (s.compare(sa[mid], min(n - sa[mid], m), pattern) < 0) {
					low = mid + 1;
				} else {
					high = mid - 1;
				}
			}
			int first = low;
			// Find upper bound
			low = 0, high = n - 1;
			while (low <= high) {
				int mid = (low + high) / 2;
				if (s.compare(sa[mid], min(n - sa[mid], m), pattern) <= 0) {
					low = mid + 1;
				} else {
					high = mid - 1;
				}
			}
			int last = high;
			return max(0, last - first + 1);
		}
		long long distinct_substrings() {
			long long total = (long long)n * (n + 1) / 2;
			for (int i = 0; i < n - 1; i++) {
				total -= lcp[i];
			}
			return total;
		}
};


vector<int> g[N];
int par[N], dep[N], sz[N];

void dfs(int u, int p = 0) {
	sz[u] = 1, par[u] = p;
	dep[u] = dep[p] + 1;
	int mx = 0;
	for (auto &v: g[u]) {
		if (v == p) continue;
		dfs(v, u);
		sz[u] += sz[v];
		if (sz[v] > mx) {
			mx = sz[v];
			swap(v, g[u][0]);
		}
	}
}

int T, head[N], st[N], en[N];

void dfs_hld(int u, int p = 0) {
	st[u] = ++T;
	// arr[T] = a[u];
	head[u] = (p != 0 && g[p][0] == u) ? head[p] : u;
	for (auto v: g[u]) {
		if (v == p) continue;
		dfs_hld(v, u);
	}
	en[u] = T;
}

int lca(int a, int b) {
	for (; head[a] != head[b]; b = par[head[b]]) {
		if (dep[head[a]] > dep[head[b]]) swap(a, b);
	}
	if (dep[a] > dep[b]) swap(a, b);
	return a;
}

int n;

// process node u upto it's ancestor a
// if excl is true, a won't process
i64 chain_process(int a, int u, bool excl = false) {
	i64 ans = 0;
	for (; head[u] != head[a]; u = par[head[u]]) {
		ans = ans + query(1, 1, n, st[head[u]], st[u]);	
	}
	ans = ans + query(1, 1, n, st[a] + excl, st[u]);	
	return ans;
}

// process path from node u to v
// if excl is true, lca won't process
i64 path_process(int a, int b, bool excl = false) {
	i64 ans = 0;
	for (; head[a] != head[b]; b = par[head[b]]) {
		if (dep[head[a]] > dep[head[b]]) swap(a, b);
		ans = ans + query(1, 1, n, st[head[b]], st[b]);
	}
	if (dep[a] > dep[b]) swap(a, b);
	ans = ans + query(1, 1, n, st[a] + excl, st[b]);
	return ans;
}
/*
	 dfs(1);
	 head[1] = 1;
	 dfs_hld(1);
	 build(1, 1, n);
*/

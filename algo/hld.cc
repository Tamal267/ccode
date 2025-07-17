vector<int> g[N];
int par[N][LG + 1], dep[N], sz[N];

void dfs(int u, int p = 0) {
  par[u][0] = p;
  dep[u] = dep[p] + 1;
  sz[u] = 1;
  for (int i = 1; i <= LG; i++) par[u][i] = par[par[u][i - 1]][i - 1];
  if (p) g[u].erase(find(g[u].begin(), g[u].end(), p));
  for (auto &v : g[u]) if (v != p) {
      dfs(v, u);
      sz[u] += sz[v];
      if(sz[v] > sz[g[u][0]]) swap(v, g[u][0]);
    }
}

int lca(int u, int v) {
  if (dep[u] < dep[v]) swap(u, v);
  for (int k = LG; k >= 0; k--) if (dep[par[u][k]] >= dep[v]) u = par[u][k];
  if (u == v) return u;
  for (int k = LG; k >= 0; k--) if (par[u][k] != par[v][k]) u = par[u][k], v = par[v][k];
  return par[u][0];
}

int kth(int u, int k) {
  assert(k >= 0);
  for (int i = 0; i <= LG; i++) if (k & (1 << i)) u = par[u][i];
  return u;
}

int T, head[N], st[N], en[N];

void dfs_hld(int u) {
  st[u] = ++T;
	arr[T] = a[u]; // modify accordingly
  for (auto v : g[u]) {
    head[v] = (v == g[u][0] ? head[u] : v);
    dfs_hld(v);
  }
  en[u] = T;
}

int n;

i64 query_up(int u, int v) {
  i64 ans = 0;
  while(head[u] != head[v]) {
    ans = ans + query(1, 1, n, st[head[u]], st[u]);
    u = par[head[u]][0];
  }
  ans = ans + query(1, 1, n, st[v], st[u]);
  return ans;
}
i64 query(int u, int v) {
  int l = lca(u, v);
  i64 ans = query_up(u, l);
  if (v != l) ans = ans + query_up(v, kth(v, dep[v] - dep[l] - 1));
  return ans;
}
/*
 	dfs(1);
	head[1] = 1;
	dfs_hld(1);
	build(1, 1, n);
*/

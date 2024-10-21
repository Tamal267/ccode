class DisjointSet {
  vector<int> parent, sz;

 public:
  DisjointSet(int n) {
    sz.resize(n + 1);
    parent.resize(n + 2);
    for (int i = 1; i <= n; i++) parent[i] = i, sz[i] = 1;
  }
  int findUPar(int u) { return parent[u] == u ? u : parent[u] = findUPar(parent[u]); }
  void unionBySize(int u, int v) {
    int a = findUPar(u);
    int b = findUPar(v);
    if (sz[a] < sz[b]) swap(a, b);
    if (a != b) {
      parent[b] = a;
      sz[a] += sz[b];
    }
  }
};
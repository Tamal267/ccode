#include <bits/stdc++.h>
using namespace std;

#define int long long
#define accuracy chrono::steady_clock::now().time_since_epoch().count()

mt19937 rng(accuracy);

int rand(int l, int r) {
  uniform_int_distribution<int> ludo(l, r);
  return ludo(rng);
}

// Function to generate a random tree
vector<pair<int, int>> generate_tree(int n) {
    vector<pair<int, int>> edges;
    for (int i = 2; i <= n; ++i) {
        int parent = rand(1, i-1);
        edges.emplace_back(parent, i);
    }
    
    // Shuffle the edges to make it more random
    shuffle(edges.begin(), edges.end(), rng);
    return edges;
}

signed main() {
    srand(accuracy);
    
    // Generate random n (number of vertices)
    int n = rand(1, 20); // Smaller n for testing, can increase to 5e5 for max case
    cout << n << '\n';
    
    // Generate the tree edges
    auto edges = generate_tree(n);
    for (auto [u, v] : edges) {
        cout << u << ' ' << v << '\n';
    }
    
    // Generate random q (number of queries)
    int q = rand(1, 10); // Smaller q for testing, can increase to 5e5 for max case
    cout << q << '\n';
    
    // Generate the queries
    for (int i = 0; i < q; ++i) {
        int ci = rand(1, 3); // Operation type
        int vi = rand(1, n); // Vertex
        cout << ci << ' ' << vi << '\n';
    }
    
    return 0;
}

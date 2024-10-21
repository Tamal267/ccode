const int N = 505;
int capacity[N][N];
int vis[N], p[N];
int n, m;

int bfs(int s, int t) {
  memset(vis, 0, sizeof vis);
  queue<int> qu;
  qu.push(s);
  vis[s] = 1;
  while (!qu.empty()) {
    int u = qu.front();
    qu.pop();
    for (int i = 0; i <= n + m + 2; i++) {
      if (capacity[u][i] > 0 && !vis[i]) {
        p[i] = u;
        vis[i] = 1;
        qu.push(i);
      }
    }
  }
  return vis[t] == 1;
}

int maxflow(int s, int t) {
  int cnt = 0;
  while (bfs(s, t)) {
    int cur = t;
    while (cur != s) {
      int prev = p[cur];
      capacity[prev][cur] -= 1;
      capacity[cur][prev] += 1;
      cur = prev;
    }
    cnt++;
  }
  return cnt;
}
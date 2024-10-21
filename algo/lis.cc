void lis(vector<int> &v) {
  int n = v.size();
  vector<int> dp(n + 1, 1), hash(n);
  int mx = 1, lastInd = 0;
  for (int i = 0; i < n; i++) {
    hash[i] = i;
    for (int prev = 0; prev < i; prev++) {
      if (v[i] > v[prev] && 1 + dp[prev] > dp[i]) {
        dp[i] = 1 + dp[prev];
        hash[i] = prev;
      }
    }
    if (mx < dp[i]) {
      mx = dp[i];
      lastInd = i;
    }
  }
  vector<int> printSeq;
  printSeq.push_back(v[lastInd]);
  while (hash[lastInd] != lastInd) {
    lastInd = hash[lastInd];
    printSeq.push_back(v[lastInd]);
  }
  reverse(printSeq.begin(), printSeq.end());
  cout << mx << "\n";
  for (int i : printSeq) cout << i << " ";
  cout << "\n";
}
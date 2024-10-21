string s, t;
vector<vector<int>> dp(3003, vector<int>(3003, -1));
vector<vector<int>> mark(3003, vector<int>(3003));

int f(int i, int j) {
  if (i < 0 || j < 0) return 0;
  if (dp[i][j] != -1) return dp[i][j];
  int res = 0;
  if (s[i] == t[j]) {
    mark[i][j] = 1;
    res = 1 + f(i - 1, j - 1);
  }
  else {
    int iC = f(i - 1, j);
    int jC = f(i, j - 1);
    if (iC > jC) mark[i][j] = 2;
    else mark[i][j] = 3;
    res = max(iC, jC);
  }
  return dp[i][j] = res;
}

void printWay(int i, int j) {
  if (i < 0 || j < 0) return;
  if (mark[i][j] == 1) printWay(i - 1, j - 1), cout << s[i];
  else if (mark[i][j] == 2) printWay(i - 1, j);
  else if (mark[i][j] == 3) printWay(i, j - 1);
}
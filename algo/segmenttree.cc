constexpr int N = 100005;
int arr[N], seg[N];

void build(int ind, int low, int high) {
  if (low == high) {
    seg[ind] = arr[low];
    return;
  }
  int mid = (low + high) / 2;
  build(2 * ind + 1, low, mid);
  build(2 * ind + 2, mid + 1, high);
  seg[ind] = seg[2 * ind + 1] + seg[2 * ind + 2];
}
int query(int ind, int low, int high, int l, int r) {
  if (low >= l && high <= r) return seg[ind];
  if (low > r || high < l) return 0;
  int mid = (low + high) / 2;
  int left = query(2 * ind + 1, low, mid, l, r);
  int right = query(2 * ind + 2, mid + 1, high, l, r);
  return left + right;
}
void update(int ind, int low, int high, int node, int val) {
  if (low == high) {
    seg[ind] = val;
    return;
  }
  int mid = (low + high) / 2;
  if (low <= node && node <= mid) update(2 * ind + 1, low, mid, node, val);
  else update(2 * ind + 2, mid + 1, high, node, val);
  seg[ind] = seg[2 * ind + 1] + seg[2 * ind + 2];
}
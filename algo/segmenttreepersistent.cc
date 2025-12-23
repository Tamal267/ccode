const int N = 2e5 + 5;
int arr[N];
struct Node {
	i64 val;
	Node* lc;
	Node* rc;
};

Node* versions[N];

Node* build(int l, int r) {
	if (l == r) {
		Node* node = new Node();
		node->val = arr[l];
		node->lc = NULL;
		node->rc = NULL;
		return node;
	}
	int mid = (l + r) / 2;
	Node* node = new Node();
	node->lc = build(l, mid);
	node->rc = build(mid + 1, r);
	node->val = node->lc->val + node->rc->val;
	return node;
}

i64 query(Node* node, int l, int r, int ql, int qr) {
	if (l > qr || r < ql) return 0;
	if (ql <= l && r <= qr) return node->val;
	int mid = (l + r) / 2;
	auto left = query(node->lc, l, mid, ql, qr);
	auto right = query(node->rc, mid + 1, r, ql, qr);
	return (left + right);
}

Node* update(Node* node, int l, int r, int ind, int val) {
	if (l == r) {
		Node* newnode = new Node();
		newnode->val = val;
		newnode->lc = NULL;
		newnode->rc = NULL;
		return newnode;
	}
	int mid = (l + r) / 2;
	Node* newnode = new Node();
	if (l <= ind && ind <= mid) {
		newnode->lc = update(node->lc, l, mid, ind, val);
		newnode->rc = node->rc;
	} else {
		newnode->lc = node->lc;
		newnode->rc = update(node->rc, mid + 1, r, ind, val);
	}
	newnode->val = newnode->lc->val + newnode->rc->val;
	return newnode;
}

void solve() {
	int n, q;
	cin >> n >> q;
	for (int i = 1; i <= n; i++) cin >> arr[i];
	int v = 1;
	versions[v] = build(1, n);

	while (q--) {
		int ty;
		cin >> ty;
		if (ty == 1) {
			int k, a, x;
			cin >> k >> a >> x;
			versions[k] = update(versions[k], 1, n, a, x);
		} else if (ty == 2) {
			int k, a, b;
			cin >> k >> a >> b;
			i64 ans = query(versions[k], 1, n, a, b);
			cout << ans << '\n';
		} else {
			int k;
			cin >> k;
			v++;
			versions[v] = versions[k];
		}
	}
}


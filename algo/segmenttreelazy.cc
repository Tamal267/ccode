const int N = 1e5 + 5;
int arr[N], seg[N << 2], lz[N << 2];

void pull(int node, int l, int r) {
	seg[node] = seg[node << 1] + seg[node << 1 | 1];
}

void push(int node, int l, int r) {
	int mid = (l + r) >> 1;
	lz[node << 1] += lz[node];
	seg[node << 1] += lz[node] * (mid - l + 1);
	lz[node << 1 | 1] += lz[node];
	seg[node << 1 | 1] += lz[node] * (r - mid);
	lz[node] = 0;
}

void build(int node, int l, int r) {
	if(l == r) {
		seg[node] = arr[l];
		lz[node] = 0;
		return;
	}
	int mid = (l + r) >> 1;
	build(node << 1, l, mid);
	build(node << 1 | 1, mid + 1, r);
	pull(node, l, r);
}

void update(int node, int l, int r, int ql, int qr, int val) {
	if(qr < l || r < ql) return;
	if(ql <= l && r <= qr) {
		seg[node] += val;
		lz[node] += val;
		return;
	}
	
	push(node, l, r);
	
	int mid = (l + r) >> 1;
	update(node << 1, l, mid, ql, qr, val);
	update(node << 1 | 1, mid + 1, r, ql, qr, val);
	
	pull(node, l, r);
}

int query(int node, int l, int r, int ql, int qr) {
	if(qr < l || r < ql) return 0;
	if(ql <= l && r <= qr) return seg[node];
	
	push(node, l, r);
	
	int mid = (l + r) >> 1;
	return query(node << 1, l, mid, ql, qr) + query(node << 1 | 1, mid + 1, r, ql, qr);
}
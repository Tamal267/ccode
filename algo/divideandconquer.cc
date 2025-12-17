int cost(int l, int r) {
	// Calculated the cost
}

void f(int k, int l, int r, int optL, int optR) {
	if (l > r) return;
	int mid = (l + r) / 2;

	int bestVal = -inf, bestOpt = optL;

	for (int i = optL; i <= min(mid, optR); i++) {
		int val = dp[k - 1][i - 1] + cost(i, mid);
		if (val > bestVal) {
			bestVal = val;
			bestOpt = i;
		}
	}

	dp[k][mid] = bestVal;

	f(k, l, mid - 1, optL, bestOpt);
	f(k, mid + 1, r, bestOpt, optR);
}

// for (int i = 1; i <= k; i++) {
// Clear variables
// f(i, 1, n, 1, n);
// }

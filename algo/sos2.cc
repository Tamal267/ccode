const int MAXN = 1 << 20, MLOG = 20;    
int dp[MAXN], freq[MAXN];

// Sum over subsets (SOS Down)
void forward1() {
	for (int bit = 0; bit < MLOG; bit++)
		for (int i = 0; i < MAXN; i++)
			if (i & (1 << bit)) dp[i] += dp[i ^ (1 << bit)];
}

void backward1() {
	for (int bit = 0; bit < MLOG; bit++)
		for (int i = MAXN - 1; i >= 0; i--)
			if (i & (1 << bit)) dp[i] -= dp[i ^ (1 << bit)];
}

// Sum over supersets (SOS Up)
void forward2() {
	for (int bit = 0; bit < MLOG; bit++)
		for (int i = MAXN - 1; i >= 0; i--)
			if (i & (1 << bit)) dp[i ^ (1 << bit)] += dp[i];
}

void backward2() {
	for (int bit = 0; bit < MLOG; bit++)
		for (int i = 0; i < MAXN; i++)
			if (i & (1 << bit)) dp[i ^ (1 << bit)] -= dp[i];
}

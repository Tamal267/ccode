int maxSubArraySum(vector<int> &a) {
	int size = a.size();
	int maxTill = INT_MIN, maxEnd = 0;
	for (int i = 0; i < size; i++) {
		maxEnd = maxEnd + a[i];
		if (maxTill < maxEnd) maxTill = maxEnd;
		if (maxEnd < 0) maxEnd = 0;
	}
	return maxTill;
}
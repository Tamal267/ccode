int minSubarraySum(vector<int> &arr) {
	int n = arr.size();
	int min_current = arr[0];
	int min_global = arr[0];

	for (int i = 1; i < n; i++) {
		min_current = min(arr[i], min_current + arr[i]);
		min_global = min(min_global, min_current);
	}

	return min_global;
}

int maxSubarraySum(vector<int> &arr) {
	int n = arr.size();
	int max_current = arr[0];
	int max_global = arr[0];

	for (int i = 1; i < n; i++) {
		max_current = max(arr[i], max_current + arr[i]);
		max_global = max(max_global, max_current);
	}

	return max_global;
}


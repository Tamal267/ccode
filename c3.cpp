// Author:           Syed Tamal
// Created:          18 Aug 2023  21:00:11

#include <bits/stdc++.h>
using namespace std;
#define int long long
#ifdef ONPC
#include "mydebug.h"
#else
#define debug(...) 1
#endif

int n, a[3][4], dp[5005], d1[25000005], ansn, ans1;
int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n;
    for (int i = 1; i <= 3; i++) cin >> a[1][i];
    for (int i = 1; i <= 3; i++) cin >> a[2][i];
    for (int i = 1; i <= 3; i++) {
        for (int j = 0; j <= n; j++) {
            if (n - (j + a[1][i]) >= 0) {
                dp[j + a[1][i]] = max(dp[j + a[1][i]], dp[j] + a[2][i]);
            }
        }
    }
    for (int j = 0; j <= n; j++) ansn = max(ansn, dp[j] + n - j);
    for (int i = 1; i <= 3; i++) {
        for (int j = 0; j <= ansn; j++) {
            if (n - (j + a[2][i]) >= 0) {
                d1[j + a[2][i]] = max(d1[j + a[2][i]], d1[j] + a[1][i]);
            }
        }
    }
    for (int j = 0; j <= ansn; j++) ans1 = max(ans1, d1[j] + ansn - j);
    cout << ans1 << "\n";
}

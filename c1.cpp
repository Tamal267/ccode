// Author:           Syed Tamal
// Created:          22 Aug 2023  23:31:29

#include <bits/stdc++.h>
using namespace std;
#define int long long
#ifdef ONPC
#include "/mydebug.h"
#else
#define debug(...) 1
#endif

const int N = 1000005;
int two[N], five[N];
void compute() {
    for (int i = 2; i < N; i += 2) {
        int num = i;
        while (num % 2 == 0) {
            two[i]++;
            num /= 2;
        }
    }
    for (int i = 5; i < N; i += 5) {
        int num = i;
        while (num % 5 == 0) {
            five[i]++;
            num /= 5;
        }
    }
    for(int i=1;i<N;i++){
        two[i] += two[i-1];
        five[i] += five[i-1];
    }
}

void solve() {
    int n, r, p, q;
    cin >> n >> r >> p >> q;
    int t = two[n] - two[r] - two[n - r];
    int f = five[n] - five[r] - five[n - r];
    int x = 0, y = 0;
    int num = p;
    while (num % 2 == 0) {
        x++;
        num /= 2;
    }
    num = p;
    while (num % 5 == 0) {
        y++;
        num /= 5;
    }
    x *= q, y *= q;
    t += x, f += y;
    cout<<min(t, f)<<"\n";
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    compute();
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cout<<"Case "<<i<<": ";
        solve();
    }
}

/******************************************************************************
* Author:           Syed Tamal
* Created:          16 Jul 2023  19:35:40 
******************************************************************************/
#include <bits/stdc++.h>
using namespace std;
#define fastio ios::sync_with_stdio(false); cin.tie(nullptr);
#define int long long

mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());

inline int gen_random(int l, int r) {
    return uniform_int_distribution<int>(l, r)(rng);
}

int32_t main(){
    fastio
    int t = gen_random(1, 10000);
    cout<<t<<"\n";
    while(t--){
        int n = gen_random(1,1000), m = gen_random(1, 1000);
        cout<<n<<" "<<m<<"\n";
    }
}


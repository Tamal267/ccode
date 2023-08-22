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
    int t = gen_random(1, 100);
    cout<<t<<"\n";
    while(t--){
        int n = gen_random(1, 100), k = gen_random(1, 100);
        cout<<n<<" "<<k<<"\n";
        for(int i=0;i<n;i++) cout<<gen_random(1, 100)<<" ";
        cout<<"\n";
    }
}

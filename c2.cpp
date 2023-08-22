// Author:           Syed Tamal
// Created:          21 Aug 2023  19:25:55 

#include <bits/stdc++.h>
using namespace std;
#define int long long
#ifdef ONPC
#include "/mydebug.h"
#else
#define debug(...) 1
#endif

int32_t main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m, x, y;
    cin>>n>>m>>x>>y;
    int mn = INT_MAX;
    for(int a=0;;a++){
        if(n - m*a < 0) break;
        int X = (a)*y + (n - m*a)*x;
        mn = min(mn, X);
        // debug(a, mn);
    }
    cout<<mn<<"\n";
}

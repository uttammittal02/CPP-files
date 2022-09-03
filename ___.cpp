#include <stack>
#include <iomanip>
#include <ios>
#include <iterator>
#include <inttypes.h>
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <numeric>
#include <vector>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <queue>
#include <ctime>
#include <cassert>
#include <complex>
#include <string>
#include <cstring>
#include <chrono>
#include <random>
#include <bitset>
#include <climits>
#include <tuple>
#include <functional>
using namespace std;
#define cout std::cout
// #include<bits/stdc++.h>

// #include<ext/pb_ds/assoc_container.hpp>
// #include<ext/pb_ds/tree_policy.hpp>

// using namespace __gnu_pbds;
// using namespace std;

// typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> pbds;

// MOD_DEFINE
// MOD_DEFINE
struct SegTree{
    // query zero based, lazy propagation implememted.
    // Update adds delta to the range l, r 
    // query returns max value in the range l, r and the index at which it occurs.

    // nodes 1 based (dw if only using superficially)
    int N;
    vector<pair<int, int> > t;
    vector<int> a;
    vector<int> lazy; 

    
    SegTree(vector<int> &a){
        this->a = a;
        N = a.size();
        t = vector<pair<int, int> > (4 * N + 5);
        lazy = vector<int> (4 * N + 5);
        build(1, 0, N - 1);
    }

    void build(int v, int tl, int tr) {
        if(tl == tr) 
            t[v].first = a[tl], t[v].second = tl;
        
        else {
                int tm = (tl + tr) / 2;
                
                build(v * 2, tl, tm);
                
                build(v * 2 + 1, tm + 1, tr);

                t[v] = min(t[v * 2], t[v * 2 + 1]);
        }
    }
    void push(int v) {
        t[v * 2].first += lazy[v];
        lazy[v * 2] += lazy[v];
        t[v * 2 + 1].first += lazy[v];
        lazy[v * 2 + 1] += lazy[v];
        lazy[v] = 0;
    }


    void Update(int l, int r, int delta){
        update(1, 0, N - 1, l, r, delta);
    }

    void update(int v, int tl, int tr, int l, int r, int addend) {
        if (l > r) 
            return;
        if (l == tl && tr == r) {
            t[v].first += addend;
            lazy[v] += addend;
        } else {
                push(v);
                int tm = (tl + tr) / 2;
                update(v * 2, tl, tm, l, min(r, tm), addend);
                update(v * 2 + 1, tm + 1, tr, max(l, tm + 1), r, addend);
                
                t[v] = min(t[v * 2], t[v * 2 + 1]);

        }
    }
    pair<int, int> Query(int l, int r){
        return query(1, 0, N - 1, l, r);
    }

    pair<int, int> query(int v, int tl, int tr, int l, int r) {
        if (l > r)
            return make_pair(INT32_MIN, -1);
        if (l <= tl && tr <= r)
            return t[v];
        push(v);
        int tm = (tl + tr) / 2;
        pair<int, int> f = query(v * 2, tl, tm, l, min(r, tm)), s = query(v * 2 + 1, tm + 1, tr, max(l, tm + 1), r); 
        
        return min(f, s);
    }
};
void slv(){
        int n; cin >> n; 
        vector<int> a(n);

        for(int i = 0; i < n; i++) a[i] = INT32_MAX;

        SegTree T(a); 

        int q; cin >> q; 

        // cout << "GI" << T.Query(0, 0).second << endl; cout.flush();


        for(int i = 0; i < q; i++){
            int t; cin >> t; 
        // cout << "OK" << endl; cout.flush();

            if(t == 1){
                int id, v; cin >> id >> v; 

                // T.Update(id, id, -a[id] + v);

                // a[id] = v;
            }
            else{
                int cnt = 0; 
                int l, r, w; cin >> l >> r >> w; 

                r--;
                for(; ; cnt++){
                    cout << "OK" << endl; cout.flush();
                    pair<int ,int> t = T.Query(l, r);

                    if(t.first > w) break;

                    T.Update(t.second, t.second, -a[t.second]);
                    T.Update(t.second, t.second, INT32_MAX);

                    a[t.second] = INT32_MAX;
                }
                cout << cnt << endl;
            }
        }
}

int32_t main(){

        slv();
        
        return 0;
}
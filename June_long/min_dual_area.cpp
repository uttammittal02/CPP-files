#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cmath>
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
#include <functional>
#define infinity 999999999999999999
#define sz(v) ((int)(v).size())
#define all(v) (v).begin(),(v).end()
#define MOD_DEFINE const int MOD = 1e9 + 7;
#define And &&
#define Or ||
#define ff first 
#define ss second
#define endl '\n'
#define space " "
#define int long long
#define pii pair<int, int>
#define vi vector<int>
#define pb(n) push_back(n)
#define mii map<int, int>
#define test_cases_loop int t; cin >> t; while(t--)
#define FIO ios_base::sync_with_stdio(false); cin.tie(NULL);
#define loop(var, initial, final) for(int var=initial; var < final; var++)
using namespace std;

bool comp_y(pii a, pii b){
    // return a.first < b.first;
    return a.second < b.second;
}

int32_t main(){
    test_cases_loop{
        int n;
        cin>>n;
        vector <pair<int, int> > coordinates;
        loop(i, 0, n){
            pair<int, int> p;
            int x, y;
            cin>>x>>y;
            p.first = x; p.second = y;
            coordinates.push_back(p);
        }
        if (n==1) {cout<<0<<endl; continue;}
        sort(all(coordinates));
        vi prefix_max(n);
    vi prefix_min(n);
    prefix_max[0] = prefix_min[0] = coordinates[0].ss;
    vi suffix_min(n);
    vi suffix_max(n);
    suffix_max[n-1] = suffix_min[n-1] = coordinates[n-1].ss;
    loop(i, 1, n){
        prefix_max[i] = max(prefix_max[i-1], coordinates[i].ss);
        prefix_min[i] = min(prefix_min[i-1], coordinates[i].ss);
        suffix_max[n-i-1] = max(suffix_max[n-i], coordinates[n-i-1].ss);
        suffix_min[n-i-1] = min(suffix_min[n-i], coordinates[n-i-1].ss);
        }
    int ans = infinity;
    loop(i, 0, n-1){
        int partition = coordinates[i].ff;
        int next_partition = coordinates[i+1].ff;
        int area = abs((partition - coordinates[0].ff) * (prefix_max[i] - prefix_min[i])) + abs((coordinates[n-1].ff - next_partition) * (suffix_max[i+1] - suffix_min[i+1]));
        ans = min(ans, area);
        // cout<<partition<<space<<coordinates[0].ff<<space<<prefix_max[i]<<space<<prefix_min[i]<<space<<coordinates[n-1].ff<<space<<next_partition<<space<<suffix_max[i+1]<<space<<suffix_min[i+1]<<endl;
        // cout<<ans<<endl;
    }
    // cout<<endl;
        sort(all(coordinates), comp_y);
        
    prefix_max[0] = prefix_min[0] = coordinates[0].ff;
    
    suffix_max[n-1] = suffix_min[n-1] = coordinates[n-1].ff;
    loop(i, 1, n){
        prefix_max[i] = max(prefix_max[i-1], coordinates[i].ff);
        prefix_min[i] = min(prefix_min[i-1], coordinates[i].ff);
        suffix_max[n-i-1] = max(suffix_max[n-i], coordinates[n-i-1].ff);
        suffix_min[n-i-1] = min(suffix_min[n-i], coordinates[n-i-1].ff);
        }
    loop(i, 0, n-1){
        int partition = coordinates[i].ss;
        int next_partition = coordinates[i+1].ss;
        int area = abs((partition - coordinates[0].ss) * (prefix_max[i] - prefix_min[i])) + abs((coordinates[n-1].ss - next_partition) * (suffix_max[i+1] - suffix_min[i+1]));
        ans = min(ans, area);
    }
        cout<<ans<<endl;
    }
    return 0;
}
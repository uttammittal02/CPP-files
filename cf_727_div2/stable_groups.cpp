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

#define And &&
#define oOr ||
#define endl '\n'
#define sp " "
#define int long long
#define infinity 999999999999999999
#define sz(v) ((int)(v).size())
#define all(v) (v).begin(),(v).end()
#define MOD 1000000007;
#define pii pair<int, int>
#define usi unordered_set<int>
#define osi set<int>
#define vi vector<int>
#define pb(n) push_back(n)
#define mii map<int, int>
#define test int t; cin >> t; while(t--)
#define FIO ios_base::sync_with_stdio(false); cin.tie(NULL);
#define loop(var, initial, final) for(int var=initial; var < final; var++)
using namespace std;

int32_t main(){
    int n, k, x;
    cin>>n>>k>>x;
    vi arr(n);
    int temp = k;
    loop(i, 0, n){
        cin>>arr[i];
    }
    sort(all(arr));
    vi diff;
    loop(i, 1, n){
        if (arr[i] - arr[i-1] > x) diff.pb(arr[i] - arr[i-1]);
    }
    int groups = sz(diff) + 1;
    sort(all(diff));
    int cnt = 0;
    loop(i, 0, sz(diff)){
        if((diff[i] - 1)/x <= (k-cnt)) cnt += (diff[i] - 1)/x, groups--;
        // if (cnt == k) break;
    }
    cout<<groups<<endl;
    return 0;
}
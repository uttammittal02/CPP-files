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
#define Or ||
#define endl '\n'
#define space " "
#define int long long
#define infinity 999999999999999999
#define sz(v) ((int)(v).size())
#define all(v) (v).begin(),(v).end()
// #define Mod_define const int MOD = 1000000007;
#define mod 1000000007
#define pii pair<int, int>
#define usi unordered_set<int>
#define osi set<int>
#define vi vector<int>
#define pb(n) push_back(n)
#define mii map<int, int>
#define test_cases_loop int t; cin >> t; while(t--)
#define FIO ios_base::sync_with_stdio(false); cin.tie(NULL);
#define loop(var, initial, final) for(int var=initial; var < final; var++)
using namespace std;

// int power(int a, int b){
//     int ans = 1;
//     if (b == 1) {return (a % mod);}
//     if (b == 0) return 1;
//     // int k = (int) b/2;
//     float k = (float) b/2;
//     return ((power(a, b/2) * power(a, ceil(k))) % mod);
// }

int power(int x, int y)
{
    int temp;
    if( y == 0)
        return 1;
    if (y == 1) return x%mod;
    temp = power(x, y / 2);
    if (y % 2 == 0)
        return ((temp * temp)%mod);
    return (((x * temp)%mod * temp)%mod);
}



int32_t main(){
    vi dp;
    int ans_ = 1;
    loop(i, 0, (int)1e6 + 1){
        dp.pb(ans_);
        ans_ *= 2;
        ans_ %= mod;
    }
    test_cases_loop{
        int n, m;
        cin>>n>>m;
        int ans = power((dp[n] - 1), m);
        cout<<ans<<endl;
    }
    return 0;
}
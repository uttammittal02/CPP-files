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

#define YES cout << "YES" << endl;
#define Yes cout << "Yes" << endl;
#define NO cout << "NO" << endl;
#define No cout << "No" << endl;
#define infinity 999999999999999999
#define float long double
#define sz(v) ((int)(v).size())
#define all(v) (v).begin(), (v).end()
#define MOD (int)1000000007
#define endl '\n'
#define sp ' '
#define int long long
#define pii pair<int, int>
#define vi vector<int>
#define pb(n) push_back(n)
#define mii map<int, int>
#define umii unordered map<int, int>
#define test_cases_loop \
	int t;              \
	cin >> t;           \
	loop(tc, 1, t + 1)
#define FIO                           \
	ios_base::sync_with_stdio(false); \
	cin.tie(NULL);cout.tie(NULL);
#define find_ele(ele, set) set.find(ele) != set.end()
#define loop(var, initial, final) for (int var = initial; var < final; var++)
#define rloop(var, init, end) for (int var = init; var >= end; var--)
#define ff first
#define ss second
#define iter(itr, start, end) for (itr = start; itr != end; itr++)
#define yesno(var) cout << (var ? "YES" : "NO") << endl;
#define vpii vector<pii>
#define prt(x) cout << x.first << ' ' << x.second << endl;
#define vrt(x) for (int i = 0; i < x.size(); i++) cout << x[i] << ' ';
typedef long long ll;

using namespace std;

vector<int> divisors(int n)
{
	vector<int> ans;
	ans.pb(1);
	for (int i = 2; i <= sqrt(n); i++)
	{
		if (n % i == 0)
		{
			ans.pb(i);
			if (n / i != i)
				ans.pb(n / i);
		}
	}
	ans.pb(n);
	return ans;
}
void precision_print(float n, int p)
{
	cout << fixed << setprecision(p) << n << endl;
	return;
}

int ceil_(int n, int k)
{
	return n/k + (bool)(n%k);
}
template<typename T>
T power(T x, T y, int p) { 
    T res = 1;      // Initialize result 
  
    x = x % p;  // Update x if it is more than or 
                // equal to p 
    // cout <<"x= "<< x << endl;
    while (y > 0) 
    { 
        // If y is odd, multiply x with result 
        if (y & 1) 
            res = (res*x) % p; 
  
        // y must be even now 
        y = y>>1; // y = y/2 
        x = (x*x) % p; 
    } 
    // cout << "res" << res << endl;
    return res; 
} 
template<typename T>
T modInverse(T n, T p){
    return power(n, p-2, p)%p; 
} 
//--------------------------------------------------------------------------------------------------------//
//--------------------------------------------------------------------------------------------------------//
//--------------------------------------------------------------------------------------------------------//
//--------------------------------------------------------------------------------------------------------//
//--------------------------------------------------------------------------------------------------------//
vector <vi > dp;
int dfs(int n, int m){
    if (!m) return dp[n][m] = 0;
    if (n == m) return dp[n][m] = 1;
    if (dp[n][m] != -1)
        return dp[n][m];
    dp[n][m] = (((dfs(n - 1, m) + dfs(n - 1, m - 1)) % MOD) * modInverse(2ll, MOD)) % MOD;
    // cout << dp[n][m] << sp << n << sp << m << endl; 
    return dp[n][m];
    // return 0;
}

void solve()
{
	int n, m, k; cin >> n >> m >> k;
    dp = vector<vi > (n + 1, vi(m + 1, -1));
    if (n == m){
        cout << (n*k) % MOD << endl;
        return;
    }
    int ans = 0;
	while(m){
        ans += dfs(n, m);
        // cout << n << sp << m << endl;
        // cout << ans << endl;
        n --, m --;
        ans %= MOD;
    }
    cout << (k * ans) % MOD << endl;
}

int32_t main()
{
	FIO
		test_cases_loop
	{
		// cout << "Case #" << tc << ": ";
		solve();
	}
	return 0;
}

//--------------------------------------------------------------------------------------------------------//
//--------------------------------------------------------------------------------------------------------//
//--------------------------------------------------------------------------------------------------------//
//--------------------------------------------------------------------------------------------------------//
//--------------------------------------------------------------------------------------------------------//
//--------------------------------------------------------------------------------------------------------//

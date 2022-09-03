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
	while (t--)
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
vector<T> sieve(T n){
	vector<int> prime(n+1, 1);
    prime[1] = prime[0] = 0;
	for(int i = 2; i*i<=n; i++){
		if(prime[i]){
			for(int j = 2; j*i<=n; j++){
				prime[i*j] = 0;
			}
		}
	}
	// vector<T> ans;
	// for(int i = 2; i<=n;i++){
	// 	if(prime[i]) ans.pb(i);
	// }
	return prime;
}
//--------------------------------------------------------------------------------------------------------//
//--------------------------------------------------------------------------------------------------------//
//--------------------------------------------------------------------------------------------------------//
//--------------------------------------------------------------------------------------------------------//
//--------------------------------------------------------------------------------------------------------//

vector <vi > dp;
vi vis;
vi isprime;
int dfs(vi &arr, int idx, int e){
    if (idx >= sz(arr))
        return -1;
    if (vis[idx])
        return dp[idx][1];
    if (idx < e)
        dp[idx][0] = 0;
    else
        dp[idx][0] = (arr[idx - e] == 1? (dp[idx - e][0] + 1) : 0ll);
    if (idx >= e and arr[idx] == 1){
        if (vis[idx - e])
            dp[idx][1] = max(0ll, dp[idx - e][1] - 1);
        
        else
            dp[idx][1] = (idx + e < sz(arr) and arr[idx+e] == 1)? dfs(arr, idx + e, e) + 1 : 0ll;

    } 
    else{
        if (idx + e >= sz(arr) or arr[idx + e] != 1)
            dp[idx][1] = 0;
        else
            dp[idx][1] = dfs(arr, idx + e, e) + 1;
    }
    vis[idx] = 1;
    // cout << idx << sp << e << sp << dp[idx][1] << endl;
    return dp[idx][1];
}

void solve()
{
	int n, e;
	cin >> n >> e;
    dp = vector<vi >(n, vi(2));
	vi arr(n);
    vis = vi(n);
	loop(i, 0, n)
	{
		cin >> arr[i];
	}
    loop(i, 0, n)
        dfs(arr, i, e);
    int ans = 0;
    loop(i, 0, n){
        // cout << dp[i][0] << sp << dp[i][1] << endl;
    }
    loop(i, 0, n){
        if (isprime[arr[i]]){
            // if (dp[i][0] or dp[i][1])
            ans += ((dp[i][0] + 1) * (dp[i][1] + 1) - 1);
        }
    }
    cout << ans << endl;
}

int32_t main()
{
	FIO
    isprime = sieve((int)1e6);
		test_cases_loop
	{
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
// dp[i][0] = number of 1's behind i
// dp[i][1] = number of 1's after i
// dp[i][0] = arr[i - e] == 1 ? dp[i - e][0] + 1 : 0
// dp[i][1] = arr[i] == 1 ? dp[i - e][1] - 1 : find recursively
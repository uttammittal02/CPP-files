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
//--------------------------------------------------------------------------------------------------------//
//--------------------------------------------------------------------------------------------------------//
//--------------------------------------------------------------------------------------------------------//
//--------------------------------------------------------------------------------------------------------//
//--------------------------------------------------------------------------------------------------------//

int sgn(int x){
    if(x < 0) return -1;
    if(x > 0) return 1;
    return 0;
}

void solve()
{
	int n;
	cin >> n;
	
	vi arr(n);
	loop(i, 0, n)
	{
		cin >> arr[i];
	}
    vector <vi > dp(n, vi(2)), curr(n, vi(2)), len(n, vi(2));
    dp[0][0] = -infinity;
    dp[0][1] = sgn(arr[0]);
    curr[0][1] = arr[0];
    len[0][1] = 1;
    loop(i, 1, n){
        if (dp[i-1][0] - sgn(curr[i - 1][0]) * len[i - 1][0] + sgn(curr[i - 1][0] + arr[i]) * (len[i - 1][0] + 1) >= dp[i-1][1] - sgn(curr[i - 1][1]) * len[i - 1][1] + sgn(curr[i - 1][1] + arr[i]) * (len[i - 1][1] + 1)){
            dp[i][0] = dp[i-1][0] - sgn(curr[i - 1][0]) * len[i - 1][0] + sgn(curr[i - 1][0] + arr[i]) * (len[i - 1][0] + 1);
            curr[i][0] = curr[i-1][0] + arr[i];
            len[i][0] = len[i-1][0] + 1;
        }
        else{
            // cout << i << sp;
            dp[i][0] = dp[i-1][1] - sgn(curr[i - 1][1]) * len[i - 1][1] + sgn(curr[i - 1][1] + arr[i]) * (len[i - 1][1] + 1);
            curr[i][0] = curr[i-1][1] + arr[i];
            len[i][0] = len[i-1][1] + 1;
        }
        dp[i][1] = max(dp[i-1][0], dp[i-1][1]) + sgn(arr[i]);
        curr[i][1] = arr[i];
        len[i][1] = 1;
    }
    loop(i, 0, n){
        cout << dp[i][0] << sp << dp[i][1] << endl;
    }
    // cout << endl;
    // loop(i, 0, n){
    //     cout << len[i][0] << sp << len[i][1] << endl;
    // }
    cout << max(dp[n-1][0], dp[n-1][1]) << endl;
}

int32_t main()
{
	FIO
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
// 1 3 9
// 2 6 10
// 5 7 11
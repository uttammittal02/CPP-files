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

void solve()
{
	int n;
	cin >> n;
	int k; cin >> k;
	vector <vi > arr(n, vi(k)), v(n, vi(2));
	vector <vi > dp(n, vi(2, infinity));
    loop(i, 0, n)
    {
        loop(j, 0, k)
        {
            cin >> arr[i][j];
        }
        sort(all(arr[i]));
        v[i][0] = arr[i][0];
        v[i][1] = arr[i][k - 1];
    }
    dp[0][0] = infinity;
    dp[0][1] = v[0][1];
    loop(idx, 1, n){
		dp[idx][0] = min(dp[idx - 1][0] + abs(v[idx][1] - v[idx - 1][0]) + abs(v[idx][1] - v[idx][0]), dp[idx - 1][1] + abs(v[idx - 1][1] - v[idx][1]) + abs(v[idx][1] - v[idx][0]));
		dp[idx][1] = min(dp[idx - 1][0] + abs(v[idx][0] - v[idx - 1][0]) + abs(v[idx][1] - v[idx][0]), dp[idx - 1][1] + abs(v[idx - 1][1] - v[idx][0]) + abs(v[idx][1] - v[idx][0]));

	}
    cout << min(dp.back()[0], dp.back()[1]) << endl;
}

int32_t main()
{
	FIO
	test_cases_loop
	{
		cout << "Case #" << tc << ": ";
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
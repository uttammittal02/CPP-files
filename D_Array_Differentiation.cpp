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

#define endl '\n'
#define int long long
#define vi vector<int>
#define mii map<int, int>
#define test_cases_loop \
	int t;              \
	cin >> t;           \
	loop(tc, 1, t + 1)
#define FIO                           \
	ios_base::sync_with_stdio(false); \
	cin.tie(NULL);cout.tie(NULL);
#define loop(var, initial, final) for (int var = initial; var < final; var++)
#define yesno(var) cout << (var ? "YES" : "NO") << endl;
using namespace std;

mii vis;

bool subset_sum(vi &arr, int i, int sum){
    if (i >= sz(arr)){
        // cout << sum << endl;
        if (vis[sum]){
            return true;
        }
        vis[sum] ++;
        return false;
    }
    return subset_sum(arr, i + 1, sum + arr[i]) or subset_sum(arr, i + 1, sum);
}

void solve()
{
	int n; cin >> n;
    vis = mii();
	vi arr(n);
	loop(i, 0, n)
	{
		cin >> arr[i];
        arr[i] = abs(arr[i]);
	}
    yesno(subset_sum(arr, 0, 0))
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

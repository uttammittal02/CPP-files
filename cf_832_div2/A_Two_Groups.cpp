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
#define test_cases_loop \
	int t;              \
	cin >> t;           \
	loop(tc, 1, t + 1)
#define FIO                           \
	ios_base::sync_with_stdio(false); \
	cin.tie(NULL);cout.tie(NULL);
#define loop(var, initial, final) for (int var = initial; var < final; var++)

using namespace std;

void solve()
{
	int n; cin >> n;
    int sum = 0;
	loop(i, 0, n)
	{
        int x; cin >> x;
        sum += x;
	}
    cout << abs(sum) << endl; return;

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

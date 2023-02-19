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
#define loop(i, s, e) for(int i = s; i < e; i ++)
#define sp ' '
#define test_cases_loop \
	int t;              \
	cin >> t;           \
	loop(tc, 1, t + 1)
#define FIO                           \
	ios_base::sync_with_stdio(false); \
	cin.tie(NULL);cout.tie(NULL);


using namespace std;

int ceil_(int n, int k)
{
	return n/k + (bool)(n%k);
}

void solve()
{
	int n; cin >> n;
    cout << ceil_(n, 2) << endl;
	if (n % 2){
        cout << n/2 * 3 + 1 << sp << n/2 * 3 + 2 << endl;
    }
    loop(i, 0, n/2){
        cout << 3 * i + 1 << sp << 3 * (n - i - 1) + 2 << endl;
    }

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

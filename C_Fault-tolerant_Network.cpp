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
//--------------------------------------------------------------------------------------------------------//
//--------------------------------------------------------------------------------------------------------//
//--------------------------------------------------------------------------------------------------------//
//--------------------------------------------------------------------------------------------------------//
//--------------------------------------------------------------------------------------------------------//
vi vis;


void solve()
{
	int n; cin >> n;
	vi a(n), b(n);
	loop(i, 0, n)
		cin >> a[i];
	loop(i, 0, n)
		cin >> b[i];
	int a1, an, b1, bn;
	a1 = an = b1 = bn = infinity;
	loop(i, 0, n){
		a1 = min(a1, abs(a[0] - b[i]));
		an = min(an, abs(a.back() - b[i]));
		b1 = min(b1, abs(b[0] - a[i]));
		bn = min(bn, abs(b.back() - a[i]));
	}
	// cout << a1 + an + b1 + bn << endl;
	vi x;
	x.pb(b[0]);
	x.pb(b.back());
	vi y(x);
	x.pb(a[0] + a1);
	y.pb(an + a.back());
	int ans = infinity;
	loop(i, 0, 3){
		vis = vi(3);
		int tmp = abs(a[0] - x[i]); // 3
		vis[i] ++; 
			// cout << tmp << endl;
		loop(j, 0, 3){
			int tmp1 = abs(a.back() - y[j]); // 3
			vis[j] ++;
			// cout << tmp << endl;
			if (!vis[0]){
				tmp1 += b1; // 10
			}
			if (!vis[1])
				tmp1 += bn; // 15
			ans = min(ans, tmp + tmp1);
			vis[j] --;
			// cout << i << sp << j << sp << tmp1 << endl;
		}
	}
	cout << ans << endl;
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

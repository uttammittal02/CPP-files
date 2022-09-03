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
template<typename T>
T _gcd(T a, T b){
	T temp1 = max(a,b), temp2 = min(a,b);
	a = temp1, b = temp2;
	if(a == 0) return b;
	if(b == 0) return a;
	if(a%b ==0) return b;
	return _gcd(b, a%b);
}
int ans = 0;
void divisors(int r, int q)
{
	for (int i = 1; i*i <= r; i++)
	{
		if (r % i == 0 and (i*q) == _gcd(i, q) * r)
		{
            // cout << i << sp << ans << endl;
			ans += (((r/i) % MOD) * ((r/i) % MOD) % MOD);
            ans %= MOD;
		}
        if (i == r/i) continue;
        if (r % (r/i) == 0 and (r/i) * q == _gcd(r/i, q) * r){
            // cout << r/i << sp << ans << endl;
            ans += ((i % MOD) * (i % MOD) % MOD);
            ans %= MOD;
        }
	}
	return;
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
    ans = 0;
	int b, q, y; cin >> b >> q >> y;
    int c, r, z; cin >> c >> r >> z;
    if (c < b or c + r*(z-1) > b + q*(y - 1)){
        cout << "0\n"; return;
    }
    if ((c-b) % q or r % q){
        cout << "0\n"; return;
    }
    if (c - b < r or b + q*(y - 1) - c - r*(z-1) < r){
        cout << "-1\n"; return;
    }
    divisors(r, q);
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
// -9, -6, -3, 0, 3, 6, 9, 12, 15, 18, 21
// 0, 6, 12
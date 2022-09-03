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

struct mint{ 
	int x, mod;
 
	mint() : x(0) {}
	mint(int _x) {
	    mod = MOD;
		_x %= mod;
		if (_x < 0) _x += mod;
		x = _x;
	}
 
	mint& operator += (const mint &a) {
		x += a.x;
		if (x >= mod) x -= mod;
		return *this;
	}
	mint& operator -= (const mint &a) {
		x += mod - a.x;
		if (x >= mod) x -= mod;
		return *this;
	}
	mint& operator *= (const mint &a) {
		x = x * a.x % mod;
		return *this;
	}
	mint pow(int pw) const {
		mint res = 1;
		mint cur = *this;
		while(pw) {
			if (pw & 1) res *= cur;
			cur *= cur;
			pw >>= 1;
		}
		return res;
	}
	mint inv() const {
		assert(x != 0);
		int t = x;
		int res = 1;
		while(t != 1) {
			int z = mod / t;
			res = res * (mod - z) % mod;
			t = mod - t * z;
		}
		return res;
	}
	mint& operator /= (const mint &a) {
		return *this *= a.inv();
	}
	mint operator + (const mint &a) const {
		return mint(*this) += a;
	}
	mint operator - (const mint &a) const {
		return mint(*this) -= a;
	}
	mint operator * (const mint &a) const {
		return mint(*this) *= a;
	}
	mint operator / (const mint &a) const {
		return mint(*this) /= a;
	}
	bool operator == (const mint &a) const {
		return x == a.x;
	}
	bool operator != (const mint &a) const {
		return x != a.x;
	}
	bool operator < (const mint &a) const {
		return x < a.x;
	}
};
struct Factorials {
	
	vector<mint> f, fi;
 
	Factorials() : f(), fi() {}
	Factorials(int n) {
		n += 10;
		f = vector<mint>(n);
		fi = vector<mint>(n);
		f[0] = 1;
		for (int i = 1; i < n; i++)
			f[i] = f[i - 1] * i;
		fi[n - 1] = f[n - 1].inv();
		for (int i = n - 1; i > 0; i--)
			fi[i - 1] = fi[i] * i;
	}
 
	mint C(int n, int k) {
		if (k < 0 || k > n) return 0;
		return f[n] * fi[k] * fi[n - k];
	}
};
struct Powers {
	vector<mint> p, pi;
 
	Powers() : p(), pi() {}
	Powers(int n, mint x) {
		n += 10;
		if (x == 0) {
			p = vector<mint>(n);
			p[0] = 1;
		} else {
			p = vector<mint>(n);
			pi = vector<mint>(n);
			p[0] = pi[0] = 1;
			mint xi = x.inv();
			for (int i = 1; i < n; i++) {
				p[i] = p[i - 1] * x;
				pi[i] = pi[i - 1] * xi;
			}
		}
	}
 
	mint pow(int n) {
		if (n >= 0)
			return p[n];
		else
			return pi[-n];
	}
};
struct Inverses {
	vector<mint> ii;
    int mod;
 
	Inverses() : ii() {}
	Inverses(int n) {
        mod = MOD;
		n += 10;
		ii = vector<mint>(n);
		ii[1] = 1;
		for (int x = 2; x < n; x++)
			ii[x] = mint() - ii[mod % x] * (mod / x);
	}
 
	mint inv(mint x) {
		assert(x != 0);
		int t = x.x;
		int res = 1;
		while(t >= (int)ii.size()) {
			int z = mod / t;
			res = res * (mod - z) % mod;
			t = mod - t * z;
		}
		return ii[t] * res;
	}
};

//--------------------------------------------------------------------------------------------------------//
//--------------------------------------------------------------------------------------------------------//
//--------------------------------------------------------------------------------------------------------//
//--------------------------------------------------------------------------------------------------------//
//--------------------------------------------------------------------------------------------------------//

void solve()
{
	int n; cin >> n;
	// int k; cin >> k;
	// string s; cin >> s;
	vi arr;
    mii freq;
	loop(i, 0, n)
	{
		int x; cin >> x;
        arr.pb(x);
        freq[x]++;
	}
    sort(all(arr));
    mint ans(1);
    // Inverses inv(100);
    int n1(0), n2(0), n3(0);
    int sum = accumulate(all(arr), 0ll);
    if (sum % n){
        cout << "0" << endl;
        return;
    }
    sum /= n;
    Factorials fact(n);
    loop(i, 0, n)
    {
        n1 += freq[arr[i]] * (bool)(arr[i] < sum);
        n2 += freq[arr[i]] * (bool)(arr[i] == sum);
        n3 += freq[arr[i]] * (bool)(arr[i] > sum);
        if (arr[i] != sum)
            ans *= fact.fi[freq[arr[i]]];
        int j = i + 1;
        while (j < n and arr[j] == arr[i]) j++;
        i = j - 1;
    }
    if (n1 == 1 or n3 == 1 or n == n2){
        ans *= fact.f[n];
        ans *= fact.fi[n2];
        cout << ans.x << endl; return;
    }
    ans *= mint(2) * (fact.f[n1] * fact.f[n3] * fact.C(n, n1 + n3));
    cout << ans.x << endl;
}

int32_t main()
{
	FIO
		// test_cases_loop
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
// sources(n1), non(n2), sink(n3)
// (n1)! * (n3)! * (n) C (n1 + n3)
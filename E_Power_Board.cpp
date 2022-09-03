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
#define umii unordered_map<int, int>
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

// template<typename T>
int power (int a, int x){
    int ans = 1;
    while(x){
        if (max(a, ans) > (int)(1e6))
            return infinity;
        if(x&1) ans = (ans*a);
        a = (a*a);
        x>>=1;
    }
    return ans;
}

vi vis;

int _gcd(int x, int y){
    if (y)
        return _gcd(y, x % y);
    return x;
}

int lcm(int x, int y){
    return (x / _gcd(max(x, y), min(x, y))) * y;
}

void solve()
{
    int n, m; cin >> n >> m;
    vi f(20, m);
    loop(i, 2, 20){
        loop(j, 1, i){
            f[i] -= (m * _gcd(i, j)) / i;
            // loop(k, 1, j){
            if (j > 1){
                int k = j - 1;
                f[i] += (m * k) / lcm(i, lcm(j, max(1ll, k)));
            }
            // }
            // cout << f[i] << endl;
        }
        // cout << i << sp << f[i] << endl;
    }
    vis = vi(n + 1);
    int ans = 1;
    loop(i, 2, n + 1)
    {
        if (vis[i])
            continue;
        // ans += m;
        vis[i] = 1;
        for (int j = 1; j < 20; j++){
            if (power(i, j) > n) break;
            vis[power(i, j)] = 1;
            ans += f[j];
        }
    }
    cout << ans << endl;
}

int32_t main()
{
    FIO
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

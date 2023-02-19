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
int _gcd(int a, int b){
	if (a < b) swap(a, b);
	if (b)
		return _gcd(b, a%b);
	return a;
}
//--------------------------------------------------------------------------------------------------------//
//--------------------------------------------------------------------------------------------------------//
//--------------------------------------------------------------------------------------------------------//
//--------------------------------------------------------------------------------------------------------//
//--------------------------------------------------------------------------------------------------------//

void solve()
{
	int p1, t1, p2, t2, h, s; cin >> p1 >> t1 >> p2 >> t2 >> h >> s;
	if (t1 > t2){
        swap(p1, p2);
        swap(t1, t2);
    }
    if (t1 == t2){
        cout << ceil_(h, p1 + p2 - s) * t1 << endl;
        return;
    }
    int ans1 = (h / ((p1 - s) * (t2 / t1 - 1) + p1 + p2 - s)) * t2;
    int x = h % ((p1 - s) * (t2 / t1 - 1) + p1 + p2 - s);
    ans1 += ceil_(x, p1 - s) * t1;
    int l = t1 * t2 / _gcd(t1, t2);
    int ans2 = (h / ((l / t1 - 1) * (p1 - s) + (l / t2 - 1) * (p2 - s) + (p1 + p2 - s))) * l;
    int t = 0;
    x = h % ((l / t1 - 1) * (p1 - s) + (l / t2 - 1) * (p2 - s) + (p1 + p2 - s));
    // cout << h << sp <<  << endl;
    while (x > 0){
        t += t1;
        if (t == t2){
            x -= (p1 + p2 - s);
            t -= t2;
            ans2 += t2;
            continue;
        }
        if (t > t2){
            x -= (p2 - s);
            if (x <= 0){
                ans2 += t2;
                t = 0;
                break;
            }
            t -= t2;
            ans2 += t2;
        }
        x -= (p1 - s);
        // cout << t << sp << x << endl;
    }
    ans2 += t;
    // cout << ans1 << endl;
    // cout << ans2 << endl;
    cout << min(ans1, ans2) << endl;
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

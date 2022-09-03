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
#define MOD (int)1111111111111111111
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

pii fun(vi &arr){
    int i = 0, j = sz(arr) - 1, a = 0, b = 0;
    while (i < sz(arr)){
        a += (abs(arr[i]) == 2);
        if (arr[i] < 0){
            break;
        }
        i ++;
    }
    while (j >= 0){
        b += (abs(arr[j]) == 2);

        if (arr[j] < 0)
            break;
        j --;
    }
    return ((a < b) ? (make_pair(i + 1, 0ll)) : (make_pair(0ll, sz(arr) - j)));
}

pii prod(vi &a, int i, int j){
    // jab dikh rha tha mod nahi lena to kyu liya
    int two = 0, neg = 0;
    loop(k, i, j){
        two += (abs(a[k]) == 2);
        neg += (a[k] < 0);
    }
    return make_pair(two, neg%2);
}

void solve()
{
	int n, ans = 0;
	cin >> n;
	vector <vi > arr(1);
	loop(i, 0, n)
	{
        vi a;
		int x; cin >> x;
        if (x == 0)
            arr.pb(a);
        else
            arr.back().pb(x);
	}
    pii ans_pair = make_pair(n, 0ll);
    int a = 0;
    loop(i, 0, sz(arr)){
        pii mul = prod(arr[i], 0, sz(arr[i]));
        pii p = make_pair(0ll, 0ll);
        if (mul.ss == 1){
            p = fun(arr[i]);
            // cout << p.ff << sp << p.ss << endl;
            mul = prod(arr[i], p.ff, sz(arr[i]) - p.ss);
        }
        if (mul.ff > ans){
            ans_pair.ff = p.ff + a;
            ans_pair.ss = p.ss + n - a - sz(arr[i]);
            ans = mul.ff; /* such a foolish mistake */
        }
        a += sz(arr[i]) + 1;
    }
    // assert(ans_pair.ff + ans_pair.ss <= n);
    cout << ans_pair.ff << sp << ans_pair.ss << endl;
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

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

int query(int x, int y){
    cout << "? " << x << sp << y << endl; cout.flush();
    int a; cin >> a;
    assert(a != 0);
    if (a == 0)
        exit(0);
    return a;
}

void solve()
{
	int ans = 3, l = 3, r = 1e18;
    // int q = 0;
    set <int> s;
    loop(i, 0, 50){
        if (i % 2){
            int x = query(i / 2 + 2, 1);
            if (x == - 1){
                cout << "! " << i/2 + 1 << endl;
                return;
            }
            if (*s.begin() != x){
                cout << "! " << *s.begin() + x << endl;
                return;
            }
            ans = max(ans, *s.begin() + x);
            s.erase(s.begin());
        }
        else{
            s.insert(query(1, i/2 + 2));
        }

    }
    cout << "! " << ans << endl;
    // while (l <= r){
    //     q ++;
    //     if (q > 50){
    //         return;
    //     }
    //     int mid = l + (r - l) / 2;
        
    //     int x = query(mid);
    //     if (x == -1){
    //         r = mid - 1;
    //     }
    //     else{
    //         ans = max(ans, max(x, mid));
    //         l = max(x, mid) + 1;
    //     }
    // // }
    // if (sz(s) > 1)
    //     cout << "! " << *s.begin() + *(++s.begin()) << endl;
    // else
    //     cout << "! " << 2 * *s.begin() << endl;;
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

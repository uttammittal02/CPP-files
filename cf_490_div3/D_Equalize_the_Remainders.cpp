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

void solve()
{
	int n, m;
	cin >> n >> m;
	// int k; cin >> k;
	// string s; cin >> s;
	vi arr(n);
    mii freq;
    vector <vi > changes(m);
	loop(i, 0, n)
	{
		cin >> arr[i];
        freq[arr[i] % m] ++;
	}
    set <pii> chk;
    loop(i, 0, m){
        chk.insert(make_pair(freq[i], i));
    }
    int ans = 0;
    while(true){
        pii p1 = *chk.begin(), p2 = *chk.rbegin();
        // cout << p1.ff << sp << p1.ss<< endl;
        // cout << p2.ff << sp << p2.ss<< endl << endl;
        if (ans == n)
            break;
        if (p1.ff == n/m or p2.ff == n/m)
            break;
        int x = p1.ss, y = p2.ss, t = (m + x - y) % m;
        changes[y].pb(t);
        chk.erase(p1);
        p1.ff ++;
        chk.insert(p1);
        chk.erase(p2);
        p2.ff --;
        chk.insert(p2);
        ans += (t);
    }
    
    cout << ans << endl;
    vi ptr(m);
    // loop(i, 0, m){
    //     loop(j, 0, sz(changes[i])){
    //         cout << changes[i][j] << sp;
    //     }
    //     cout << endl;
    // }
    loop (k, 0, n){
        int x = arr[k] % m;
        if (ptr[x] >= sz(changes[x])){
            cout << arr[k] << sp;
            continue;
        }
        arr[k] += changes[x][ptr[x]];
        ptr[x] ++;
        cout << arr[k] << sp;
    }

}

int32_t main()
{
	FIO
		// test÷
		solve();
	// }
	return 0;
}

//--------------------------------------------------------------------------------------------------------//
//--------------------------------------------------------------------------------------------------------//
//--------------------------------------------------------------------------------------------------------//
//--------------------------------------------------------------------------------------------------------//
//--------------------------------------------------------------------------------------------------------//
//--------------------------------------------------------------------------------------------------------//
// 1 2 1 0 1 1
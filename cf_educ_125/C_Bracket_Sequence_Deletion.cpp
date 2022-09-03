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

// #define YES cout << "YES" << endl;
// #define Yes cout << "Yes" << endl;
// #define NO cout << "NO" << endl;
// #define No cout << "No" << endl;
// #define infinity 999999999999999999
// #define float long double
#define sz(v) ((int)(v).size())
// #define all(v) (v).begin(), (v).end()
// #define MOD (int)1000000007
#define endl '\n'
#define sp ' '
// #define int long long
// #define pii pair<int, int>
// #define vi vector<int>
// #define pb(n) push_back(n)
// #define mii map<int, int>
// #define umii unordered map<int, int>
#define test_cases_loop \
	int t;              \
	cin >> t;           \
	while (t--)
#define FIO                           \
	ios_base::sync_with_stdio(false); \
	cin.tie(NULL);cout.tie(NULL);
// #define find_ele(ele, set) set.find(ele) != set.end()
#define loop(var, initial, final) for (int var = initial; var < final; var++)
// #define rloop(var, init, end) for (int var = init; var >= end; var--)
// #define ff first
// #define ss second
// #define iter(itr, start, end) for (itr = start; itr != end; itr++)
// #define yesno(var) cout << (var ? "YES" : "NO") << endl;
// #define vpii vector<pii>
// typedef long long ll;

using namespace std;


int fun(string &s, int i){
    if (s[i] == '('){
        if (i + 2 > sz(s))
            return i;

        return i + 2;
    }
    int j = i + 1;
    for(; j < sz(s); j ++){
        if (s[j] == ')')
            break;
    }
    if (j >= sz(s))
        return i;
    return j + 1;
}

void solve()
{
	int n;
	cin >> n;
	string s; cin >> s;
    int ans = 0;
    int i = 0;
	for(; i < n - 1; ){
        if (fun(s, i) <= i)
            break;
        i = fun(s, i);
        ans ++;
    }
    cout << ans << sp << n - i << endl;
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
// 1 3 9
// 2 6 10
// 5 7 11
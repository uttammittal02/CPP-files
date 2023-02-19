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
vector<string> arr(10);

bool dfs(int i, int j){
    int ptr1 = j + 1, ptr2 = j - 1, cnt = 0;
    while (ptr1 < 10 and arr[i][ptr1] == 'X') ptr1 ++, cnt ++;
    while (ptr2 >= 0 and arr[i][ptr2] == 'X') ptr2 --, cnt ++;
    if (cnt >= 4) return true;
    ptr1 = i + 1, ptr2 = i - 1, cnt = 0;
    while (ptr1 < 10 and arr[ptr1][j] == 'X') ptr1 ++, cnt ++;
    while (ptr2 >= 0 and arr[ptr2][j] == 'X') ptr2 --, cnt ++;
    if (cnt >= 4) return true;
    ptr1 = 1, ptr2 = -1, cnt = 0;
    while (max(i + ptr1, j + ptr1) < 10 and arr[i + ptr1][j + ptr1] == 'X') ptr1 ++, cnt ++;
    while (min(i + ptr2, j + ptr2) >= 0 and arr[i + ptr2][j + ptr2] == 'X') ptr2 --, cnt ++;
    if (cnt >= 4) return true;
    ptr1 = 1, ptr2 = -1, cnt = 0;
    while (i + ptr1 < 10 and (j - ptr1) >= 0 and arr[i + ptr1][j - ptr1] == 'X') ptr1 ++, cnt ++;
    while ((i + ptr2) >= 0 and j - ptr2 < 10 and arr[i + ptr2][j - ptr2] == 'X') ptr2 --, cnt ++;
    if (cnt >= 4) return true;
    return false;
}

void solve()
{
	int n = 10;
	// int k; cin >> k;
	// string s; cin >> s;
	loop(i, 0, n)
	{
		cin >> arr[i];
	}
    loop(i, 0, n){
        loop(j, 0, n){
            if (arr[i][j] == '.'){
                if (dfs(i, j)){
                    YES return;
                }
            }
        }
    }
    NO
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

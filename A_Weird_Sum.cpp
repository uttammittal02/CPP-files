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

int fun(vector <vi > &arr){
	int n = sz(arr);
	int m = sz(arr[0]);
	int ans = 0;
	vi occur(100005, -1);
	
	mii dist, col_freq;
	loop(i, 0, n)
	{
		mii freq;
		set <int> s;
		loop(j, 0, m)
		{
			freq[arr[i][j]] ++;
			s.insert(arr[i][j]);
		}
		
		set<int> ::iterator itr;
		iter(itr, s.begin(), s.end())
		{
			if (occur[*itr] == -1)
				occur[*itr] = i;
			else{
				int d = i - occur[*itr];
				d *= col_freq[*itr];
				dist[*itr] += d;
				ans += (dist[*itr] * freq[*itr]);
				// cout << *itr << sp << i << sp << d << sp << dist[*itr] << sp << col_freq[*itr] << sp << ans << endl;
				
				occur[*itr] = i;
				
			}
			col_freq[*itr] += freq[*itr];
		}
	}
	
	return ans;
}

void solve()
{
	int n, m;
	cin >> n >> m;

	vector <vi > arr(n, vi(m)), arr2(m, vi(n));
	loop(i, 0, n)
	{
		loop(j, 0, m)
		{
			cin >> arr[i][j];
			arr2[j][i] = arr[i][j];
		}
	}
	
	int ans = fun(arr);
	ans += fun(arr2);
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
// 1 3 9
// 2 6 10
// 5 7 11
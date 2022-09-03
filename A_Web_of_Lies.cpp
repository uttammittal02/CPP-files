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

void solve()
{
	int n, m;
	cin >> n >> m;
	vector <set<int> > adj(n + 1);
	loop(i, 0, m)
	{
		int u, v;
        cin >> u >> v;
        adj[u].insert(v);
        adj[v].insert(u);
	}
    int vulnerable = 0;
    vi vul(n + 1);
    loop(i, 1, n + 1){
        if (adj[i].upper_bound(i) != adj[i].end()){
            vulnerable++;
            vul[i] = 1;
        }
    }
    int q; cin >> q;
    loop(i, 0, q){
        int x; cin >> x;
        if (x == 3){
            cout << n - vulnerable << endl;
            continue;
        }
        if (x == 1){
            int u, v;
            cin >> u >> v;
            if (u < v)
                swap(u, v);
            if (!vul[v]){
                vul[v] = 1;
                vulnerable++;
            }
            adj[u].insert(v);
            adj[v].insert(u);
        }
        else{
            int u, v;
            cin >> u >> v;
            adj[u].erase(v);
            adj[v].erase(u);
            if (u < v)
                swap(u, v);
            if (vul[v]){
                if (adj[v].upper_bound(v) == adj[v].end()){
                    vul[v] = 0;
                    vulnerable--;
                }
            }
        }
    }
}

int32_t main()
{
	FIO
		// test_cases_loop
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
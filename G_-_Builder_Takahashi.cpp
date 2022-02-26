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
	cin.tie(NULL);
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
	return (n + k - 1) / k;
}

//--------------------------------------------------------------------------------------------------------//
//--------------------------------------------------------------------------------------------------------//
//--------------------------------------------------------------------------------------------------------//
//--------------------------------------------------------------------------------------------------------//
//--------------------------------------------------------------------------------------------------------//
int n;
map <int, set<int> > memo;
map <int, vi > paths;
vi vis;
vector<vi> adj;
int path = 0;
bool dfs(int vertex, int parent)
{
    if (vertex == n)
    {
        memo[n].insert(path);
        
        return true;
    }
    if (vis[vertex])
        return false;
    vis[vertex] = 1;
    // cout << vertex << sp << path << endl;
    // int i = 0;
    bool ok = false;
    for (auto child : adj[vertex])
    {
        if (child == parent)
            continue;
        if (dfs(child, vertex)){
            if (child != n){
                for (auto path : memo[child]){
                    memo[vertex].insert(path);
                    if (vertex != 1){
                        paths[path].pb(vertex);
                    }
                }
            }
            else{
                memo[vertex].insert(path);
                if (vertex != 1){
                    paths[path].pb(vertex);
                }
            }
            ok = true;
        }
        path ++;
    }
    vis[vertex] = 0;
    return ok;
}

void solve()
{
	cin >> n;
    vis.resize(n+1);
	int m; cin >> m;
	adj = vector<vi>(n + 1);
	loop(i, 0, m)
	{
		int u, v; cin >> u >> v;
        adj[u].pb(v);
        adj[v].pb(u);
	}
    vi c(n+1);
    loop(i, 1, n+1)
        cin >> c[i];
    dfs(1, -1);
    
}

int32_t main()
{
	FIO
	// 	test_cases_loop
	// {
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

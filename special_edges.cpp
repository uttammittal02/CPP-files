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
int n, m;
set <pii > special_edges;
vector<vi > adj;
vi parent;
vi vis;
vi trsz;
int dfs(int vertex, int root){
    vis[vertex] = 1;
    parent[vertex] = root;
    int ans = 1;
    for(int i = 0; i < adj[vertex].size(); i++){
        if (special_edges.find(make_pair(vertex, adj[vertex][i])) != special_edges.end() or special_edges.find(make_pair(adj[vertex][i], vertex)) != special_edges.end())
            continue;
        if(vis[adj[vertex][i]] == 0){
            ans += dfs(adj[vertex][i], root);
        }
    }
    return ans;    
}

void solve()
{
    int m1; // number of special edges
    cin >> n >> m >> m1;
    vis = trsz = vi(n + 1);
    parent = vi(n + 1, -1);
    adj = vector <vi > (n + 1);
    for (int i = 0; i < m; i ++){
        int a, b;
        cin >> a >> b;
        adj[a].pb(b);
        adj[b].pb(a);
    }
    for(int i = 0; i < m1; i++){
        int a, b;
        cin >> a >> b;
        special_edges.insert(make_pair(a, b));
        // special_edges.insert(make_pair(b, a));
    }
    int ans = 0;
    set<pii > :: iterator itr;
    for (itr = special_edges.begin(); itr != special_edges.end(); itr++)
    {
        int u = itr->first;
        int v = itr->second;
        if (parent[u] == -1)
            trsz[u] = dfs(u, u);
        if (parent[v] == -1)
            trsz[v] = dfs(v, v);
        ans += (trsz[parent[u]] * trsz[parent[v]]);
    }
    cout << ans << endl;
}

int32_t main()
{
	FIO
		test_cases_loop
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

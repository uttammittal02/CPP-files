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
#define infinity 999999999
#define float long double
#define sz(v) ((int)(v).size())
#define all(v) (v).begin(), (v).end()
#define MOD (int)1000000007
#define endl '\n'
#define sp ' '
// #define int long long
#define pii pair<int, int>
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
#define i32 int32_t
#define vi vector<int>
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

int paths = 0;
vi dist_, cnt_path;
queue <pair <i32, i32> > q;

void bfs(vector <vi > adj, i32 s, i32 t){
	dist_[s] = 0;
	q = queue <pair <i32, i32> > ();
    q.push(make_pair(s, s));
    int dist = 0, cnt = 1, p = infinity;
	mii freq;
	cnt_path[s] = 1;
    while(!q.empty()){
        if (dist > p + 1)
            return;
        int u = q.front().ff;
        int par = q.front().ss;
        cnt --;
		freq[u] += cnt_path[par];
		cout << u << sp << par << sp << cnt_path[par] << endl;
        q.pop();
        if (!cnt){
			mii :: iterator itr;
			iter(itr, freq.begin(), freq.end()){
				int u = itr->ff, num = itr->ss;
				cout <<"map " << u << sp << num << sp << dist << endl;
				// cnt_path[u] += num;
				// cnt_path[u] %= MOD;
				loop(i, 0, adj[u].size()){
					int v = adj[u][i];
					if (v == t){
						// cout << u << sp << dist << sp << num << endl;
						paths += num;
						cnt_path[v] += num;
						cnt_path[v] %= MOD;
						paths %= MOD;
						p = min(p, dist);
					}
					if (v != t and dist <= p){
						if (dist > dist_[v])
							continue;
						dist_[v] = min(dist_[v], dist + 1);
						cnt_path[v] += num;
						cnt_path[v] %= MOD;
						q.push(make_pair(v, u));
					}
					cout << v << sp << cnt_path[v] << endl;
				}
			}
			// cout << endl;
			freq = mii();
            dist++;
            cnt = q.size();
        }
    }
}

void solve()
{
    paths = 0;
	i32 n, m, s, t;
	cin >> n >> m >> s >> t;
	dist_ = vi(n + 1, infinity), cnt_path = vi(n + 1, 0);
	vector <vi > adj(n + 1);
	loop(i, 0, m)
	{
		int u, v;
        cin >> u >> v;
        adj[u].pb(v);
        adj[v].pb(u);
	}
    bfs(adj, s, t);
    cout << (cnt_path[t] % MOD) << endl;
	// loop(i, 1, n + 1){
	// 	cout << cnt_path[i] << endl;
	// }
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

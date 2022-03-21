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
    cin.tie(NULL);                    \
    cout.tie(NULL);
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

vi parent, dist, visited;
vector<vi> adj;
void prims(int u, int n)
{
    vi mst;
    dist[u] = 0;
    set<pii> pq;
    pq.insert(make_pair(0, u));
    while (!pq.empty())
    {
        pii p = *pq.begin();
        int u = p.ss;
        pq.erase(pq.begin());
        visited[u] = 1;
        for (int v = 1; v <= n; v++)
        {
            if (adj[u][v] == -1 or visited[v])
                continue;

            if (dist[v] > adj[u][v])
            {
                dist[v] = adj[u][v];
                parent[v] = u;
                pq.insert(make_pair(dist[v], v));
            }
        }
    }
}

int32_t main()
{
    FIO int n, m;
    cin >> n >> m;
    parent = vi(n + 1, -1);
    dist = vi(n + 1, infinity);
    visited = vi(n + 1, 0);
    adj = vector<vi>(n + 1, vi(n + 1, -1));
    loop(i, 0, m)
    {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u][v] = w;
        adj[v][u] = w;
    }
    prims(1, n);
    loop(i, 1, n + 1)
        cout << "Parent of node " << i << " is " << parent[i] << endl;
    
    return 0;
}

//--------------------------------------------------------------------------------------------------------//
//--------------------------------------------------------------------------------------------------------//
//--------------------------------------------------------------------------------------------------------//
//--------------------------------------------------------------------------------------------------------//
//--------------------------------------------------------------------------------------------------------//
//--------------------------------------------------------------------------------------------------------//
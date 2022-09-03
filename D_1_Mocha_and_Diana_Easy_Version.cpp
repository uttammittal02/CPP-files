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

struct DSU{
        // const int N = 1e5 + 5;
        int N;

        vi parent, Rank;

        DSU(int n){
                parent = vi(n + 1);
                Rank = vi(n + 1);
                N = n;
        }
        

        void makeSet(){
                for(int i = 1; i <= N; i++){
                        parent[i] = i;
                }
        }

        int findParent(int u){
                if(parent[u] == u){
                        return u;
                }
                return parent[u] = findParent(parent[u]);       // path compression
        }

        void Union(int u, int v){
                u = findParent(u);
                v = findParent(v);

                if(Rank[u] > Rank[v])
                        parent[v] = u;
                        
                else if(Rank[v] > Rank[u])
                        parent[u] = v;
                
                else{
                        parent[v] = u;
                        Rank[u]++;
                }
        }
};

void solve()
{
	int n, m1, m2;
	cin >> n >> m1 >> m2;
	vi arr(n);
    DSU set1(n), set2(n), set(n);
    set1.makeSet();
    set2.makeSet();
    set.makeSet();
	loop(i, 0, m1)
	{
		int u, v;
        cin >> u >> v;
        set.Union(u, v);
	}
	loop(i, 0, m2)
	{
		int u, v;
        cin >> u >> v;
        set.Union(u, v);
	}
    vpii ans;
    loop(i, 1, n){
        // int u = set.findParent(i);
        // int j = i + 1;
        // for (; j <= n; j ++){
        //     if (set.findParent(j) != u)break;
        // }
        // if (j <= n){
        //     ans.pb(make_pair(u, j));
        //     set.Union(u, j);
        // }
        // i = j;
        loop(j, i + 1, n + 1){
            // cout << set1.parent[i] << sp << set1.findParent(j) << endl;
            if (set1.findParent(i) != set1.findParent(j) and set2.findParent(i) != set2.findParent(j)){
                ans.pb(make_pair(i, j));
                set1.Union(i, j);
                set2.Union(i, j);
            }
        }
    }
    cout << sz(ans) << endl;
    loop(i, 0, sz(ans)){
        cout << ans[i].ff << sp << ans[i].ss << endl;
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
// 1 -> 7
// 2 -> 6
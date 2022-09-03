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

//--------------------------------------------------------------------------------------------------------//
//--------------------------------------------------------------------------------------------------------//
//--------------------------------------------------------------------------------------------------------//
//--------------------------------------------------------------------------------------------------------//
//--------------------------------------------------------------------------------------------------------//

void solve()
{
	int n; cin >> n;
	DSU s(n);
    s.makeSet();
	vpii blue, red;
    int ans = n;
	loop(i, 0, n)
	{
		int c, l, r; cin >> c >> l >> r;
        if (c == 1)
            blue.pb(make_pair(l, r));
        else
            red.pb(make_pair(l, r));
	}
    sort(all(blue));
    sort(all(red));
    int i = 0, j = 0;
    while(i < sz(red) and j < sz(blue)){
        while (j < sz(blue) and blue[j].ss < red[i].ff)
            j++;
        while (j < sz(blue) and blue[j].ff <= red[i].ss){
            if (blue[j].ss < red[i].ff){
                j ++;
                continue;
            }
            if (s.findParent(i + 1) != s.findParent(j + 1 + sz(red))){
                s.Union(i + 1, j + 1 + sz(red));
                ans --;
            }
            // cout << "red " << red[i].ff << " " << red[i].ss << endl;
            // cout << "blue " << blue[j].ff << " " << blue[j].ss << endl;
            // cout << "ans " << ans << endl;
            j++;
        }
        i ++;
    }
    i = 0, j = 0;
    while(i < sz(red) and j < sz(blue)){
        while(i < sz(red) and red[i].ss < blue[j].ff)
            i++;
        while (i < sz(red) and red[i].ff <= blue[j].ss){
            if (red[i].ss < blue[j].ff){
                i ++;
                continue;
            }
            if (s.findParent(i + 1) != s.findParent(j + 1 + sz(red))){
                s.Union(i + 1, j + 1 + sz(red));
                ans --;
            }
            // cout << "red " << red[i].ff << " " << red[i].ss << endl;
            // cout << "blue " << blue[j].ff << " " << blue[j].ss << endl;
            // cout << "ans " << ans << endl;
            i++;
        }
        j ++;
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

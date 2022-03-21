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

map <int, int> m;
vi arr;

void solve()
{
	int a, x; cin >> a >> x;
    if (a == 1){
        m[x] ++;
        arr.pb(x);
    }
    else{
        int k; cin >> k;
        if (a == 2){
            mii::iterator itr = m.lower_bound(x);
            if (itr -> ff != x){
                itr --;
            }
            x = itr -> ff;
            int i = 0;
            mii :: iterator t = m.find(x);
            if (t != m.end()){
                t ++;
            }
            while (i < k and t != m.begin()){
                // cout << i << endl;
                t --;
                i += t->ss;
            }
            if (i < k){
                
                cout << "-1\n"; return;
            }
            // if (t == m.begin()){
            //     cout << t->ff << endl;
            //     return;
            // }
            // t ++;
            cout << t->ff << endl;   
        }
        else {
            if (x < (m.begin() -> ff)){
                x = m.begin() -> ff;
                // cout << "debug ";
            }
            // cout << x << endl;
            x = m.lower_bound(x) -> ff;
            int i = 0;
            mii :: iterator t = m.find(x);
            while (i < k and t != m.end()){
                i += t->ss;
                t ++;
            }
            if (i < k){
                cout << "-1\n"; return;
            }
            t --;
            cout << t->ff << endl;   
        }
    }
    
}

int32_t main()
{
	FIO
    m.clear();
		test_cases_loop
	{
    // mii :: iterator itr;
    // iter(itr, m.begin(), m.end()){
    //     cout << itr -> ff << " " << itr -> ss << endl;
    // }
    // cout << endl;
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
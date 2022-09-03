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

template<typename T>
T _gcd(T a, T b){
	T temp1 = max(a,b), temp2 = min(a,b);
	a = temp1, b = temp2;
	if(a == 0) return b;
	if(b == 0) return a;
	if(a%b ==0) return b;
	return _gcd(b, a%b);
}


int match(string &a, string &b){
    int ans = 0;
    loop(i, 0, sz(a)){
        if (a[i] == b[i])
            ans ++;
    }
    return ans;
}

vector <string> perms;

void permute(string a, int q){
    if (sz(a) == q){
        perms.pb(a);
        return;
    }
    a+='T';
    permute(a, q);
    a.pop_back();
    a+='F';
    permute(a, q);
    return;
}

void solve()
{
    perms = vector<string>();
	int n, q;
	cin >> n >> q;
	permute("", q);
    int mx = 0;
    string ans = "";
    vector <pair<string, int> > arr(n);
    int cnt = 0;
    vector <vi > dp(q, vi(2ll));
    vi vis(sz(perms));
	loop(i, 0, n)
	{
        cin >> arr[i].ff >> arr[i].ss;
		loop(j, 0, sz(perms)){
            if (vis[j] != i) continue;
            if (match(perms[j], arr[i].ff) == arr[i].ss){
                
                if (vis[j] == n - 1){
                    cnt ++;
                    loop(k, 0, q){
                        perms[j][k] == 'F' ? dp[k][0] ++ : dp[k][1] ++;
                    }
                }
                vis[j] ++;
            }
        }
        
	}
    loop(i, 0, q){
        // cout << dp[i][0] << sp << dp[i][1] << endl;
        ans += (dp[i][0] > dp[i][1] ? 'F' : 'T');
        mx += max(dp[i][0], dp[i][1]);
    }
    cout << ans << sp << mx / _gcd(mx, cnt) << '/' << cnt / _gcd(mx, cnt) << endl;

}

int32_t main()
{
	FIO
    int t; cin >> t;
	loop(i, 1, t + 1)
	{
        cout << "Case #" << i << ": ";
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

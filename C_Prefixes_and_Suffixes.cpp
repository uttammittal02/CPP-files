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
#include <tuple>

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
	int n;
	cin >> n;

	vector <tuple <int, string, int> > arr(2*n - 2);
	loop(i, 0, 2*n - 2)
	{
		string x; cin >> x;
        arr[i] = make_tuple(sz(x), x, i);
	}
    sort(all(arr));
    string ans((n*2 - 2), ' ');
    vector<string> pref, suff;
    pref.pb(get<1>(arr[0]));
    suff.pb(get<1>(arr[1]));
    loop(len, 1, n - 1){
        string a = get<1>(arr[2*len]), b = get<1>(arr[2*len + 1]);
        int i = get<2>(arr[2*len]), j = get<2>(arr[2*len + 1]);
        if (a[0] == b[0]){
            if (a.back() == b.back()){
                if (a.substr(0, len) == pref.back()){
                    pref.pb(a), suff.pb(b);
                    ans[i] = 'P', ans[j] = 'S';
                }
                else if (b.substr(0, len) == pref.back()){
                    suff.pb(a), pref.pb(b);
                    ans[j] = 'P', ans[i] = 'S';
                }
            }
            else if (a.back() == suff[0][0]){
                ans[j] = 'P', ans[i] = 'S';
                suff.pb(a), pref.pb(b);
            }
            else if (b.back() == suff[0][0]){
                ans[i] = 'P', ans[j] = 'S';
                pref.pb(a), suff.pb(b);
            }
            else{
                ans = string((2*n - 2), ' ');
                pref = vector<string>(0), suff = vector<string>(0);
            }
        }
        else if (a[0] == pref[0][0])
            pref.pb(a), suff.pb(b);
        else if (b[0] == pref[0][0])
            suff.pb(a), pref.pb(b);
    }
    if (ans[0] == ' '){

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
// 1 3 1
// 1 2 1
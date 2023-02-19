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
#define umii unordered_map<int, int>
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

void solve()
{
	int n; cin >> n;
	int h; cin >> h;
	vi arr(n);
	loop(i, 0, n)
	{
		cin >> arr[i];
	}
    sort(all(arr));
    int x = 0, cnt = 0;
    bool a = (h == 1), done = false;
    bool b = false;
    loop(i, 0, n){
        // cout << h << sp << i << sp << cnt << endl;
        if (arr[i] < h){
            h += arr[i] / 2;
            cnt ++;
            continue;
        }
        if (!done and lower_bound(all(arr), h) == lower_bound(all(arr), 2*h)){
            a = true;
        }
        done = true;
        i --;
        if (a){
            if (x < 1)
                h *= 3, x ++;
            else if (x < 3)
                h *= 2, x ++;
            else break;
        }
        else{
            if (!x){
                h *= 2, x ++;
            }
            else if (x == 1){
                if (lower_bound(all(arr), 2*h) == lower_bound(all(arr), h)){
                    h *= 3, x ++; b = true;
                }
                else
                    h *= 2, x ++;
            }
            else if (b and x == 2){
                h *= 2, x ++;
            }
            else if (x == 2){
                h *= 3, x ++;
            }
            else 
                break;
        }
        
    }
    cout << cnt << endl;
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

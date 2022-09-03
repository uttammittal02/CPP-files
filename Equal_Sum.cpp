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
bool var = true;
void solve()
{
	int n;
	cin >> n;
    // n = 100;
    if (n == -1){
        var = false;
        return;
    }
    assert(n == 100);
	// int k; cin >> k;
	// string s; cin >> s;
	vi arr(n);
    int k = 1;
    int r = 0, cnt = 0;
	int i = 1;
    for (; i <= 1e9;){
        cout << i << sp;
        assert(i <= 1e9 and i >= 1);
        r += i;
        if (i / k >= 5){
            k *= 10;
            i = k;
        } 
        else
            i += k;
        cnt ++;
    }
    rloop(i, 1e9 - 1, 1e9 - 54){ 
        // arr[90 + 1e9 - i] = i;
        r += i;
        assert(i <= 1e9 and i >= 1);
        cout << i << sp;
        cnt ++;
    }
    cout << endl;
    // cout << cnt << endl;
    // cout <<endl <<  cnt << sp << r << endl;
    loop(i, 0, n){
        cin >> arr[i];
        if (arr [i] == -1){
            var = false; return;
        }
    }
    sort(all(arr));
    reverse(all(arr));
    int sum = accumulate(all(arr), r);
    int x = sum / 2;
    // int x; cin >> x;
    cnt = 0;
    if (x <= 1e9){
        int curr = 0;
        string a = to_string(x);
        reverse(all(a));
        k = 1;
        loop(i, 0, sz(a)){
            int digit = a[i] - '0';
            if (digit >= 5){
                curr += 5*k;
                cout << 5*k << sp;
                assert(5*k <= 1e9);
                cnt ++;
            }
            if (digit % 5){
                cout << (digit % 5) * k << sp;
                curr += (digit % 5) * k;
                assert((digit % 5)*k <= 1e9);
                cnt ++;
            }
            k *= 10;
        }
        assert(cnt and cnt <= 2*n - 1);
        assert(curr == x);
    }
    else{
        int curr = 0;
        int  i = 1e9;
        while (x - curr >= 1e9){
            curr += i;
            cout << i << sp;
            cnt ++;
            i --;
            if (i < 1e9 - 54) break;
            assert(i >= 1e9 - 54);
        }
        int j =0;
        while (j < n and x - curr >= 1e9){
            curr += arr[j]; j ++;
            cout << arr[j] << sp;
            cnt ++;
        }
        if (x == curr)
            return;
        string a = to_string(x - curr);
        reverse(all(a));
        k = 1;
        loop(i, 0, sz(a)){
            int digit = a[i] - '0';
            if (digit >= 5){
                cnt ++;
                cout << 5*k << sp;
                curr += 5*k;
            }
            if (digit % 5){
                cout << (digit % 5) * k << sp;
                cnt ++;
                curr += (digit % 5) * k;
            }
            k *= 10;
        }
        assert(curr == x);
        assert(cnt and cnt <= 2*n - 1);
        
    }
    cout << endl;
}

int32_t main()
{
	FIO 
		test_cases_loop
	{
		solve();
        if (!var) break;
	}
	return 0;
}

//--------------------------------------------------------------------------------------------------------//
//--------------------------------------------------------------------------------------------------------//
//--------------------------------------------------------------------------------------------------------//
//--------------------------------------------------------------------------------------------------------//
//--------------------------------------------------------------------------------------------------------//
//--------------------------------------------------------------------------------------------------------//
// 1 3 9
// 2 6 10
// 5 7 11
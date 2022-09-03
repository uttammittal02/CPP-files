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

vector <vi > arr;

void make(int i, vi temp){
    if (i == 6){
        arr.pb(temp);
        return;
    }
    temp.pb(1);
    make(i+1, temp);
    temp.pop_back();
    temp.pb(2);
    make(i+1, temp);
    temp.pop_back();
    temp.pb(3);
    make(i + 1, temp);
    temp.pop_back();
    temp.pb(4);
    make(i + 1, temp);
    temp.pop_back();
    temp.pb(5);
    make(i + 1, temp);
    temp.pop_back();
}
int mn = infinity;

void fun(vi a, vi b, int swaps, int id1, int id2){
    assert(sz(a) == 5);
    if (a == b){
        mn = min(mn, swaps);
        return;
    }
    if (swaps > 4){
        return;
    }
    loop(i, 0, 5){
        loop(j, 0, 5){
            if (i == id1 && j == id2) continue;
            if (i == j) continue;
            swap(a[i], a[j]);
            fun(a, b, swaps + 1, i, j);
            swap(a[i], a[j]);
        }
    }
}

void solve()
{
    loop(i, 0, sz(arr)){
	    mn = infinity;
        vi temp = arr[i];
        vi b(5);
        b[0] = temp.back();
        set <int> s;
        s.insert(b[0]);
        loop(j, 1, 5){
            b[j] = temp[j-1];
            s.insert(b[j]);
        }
        fun(temp, b, 0, -1, -1);
        if (mn != sz(s) - 1){
            cout << mn << endl;
            loop(j, 0, 5){
                cout << temp[j] << sp;
            }
            // return;
        }
    }
    cout << "OK" << endl;
}

int32_t main()
{
	FIO
    int n = 5;
    vi temp;
    make(1, temp);
    solve();
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
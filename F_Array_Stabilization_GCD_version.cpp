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
#define prt(x) cout << x.first << ' ' << x.second << endl;
#define vrt(x)                         \
    for (int i = 0; i < x.size(); i++) \
        cout << x[i] << ' ';
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
    return n / k + (bool)(n % k);
}
int _gcd(int a, int b)
{
    if (a < b)
        swap(a, b);
    if (b)
        return _gcd(b, a % b);
    return a;
}
//--------------------------------------------------------------------------------------------------------//
//--------------------------------------------------------------------------------------------------------//
//--------------------------------------------------------------------------------------------------------//
//--------------------------------------------------------------------------------------------------------//
//--------------------------------------------------------------------------------------------------------//
// We'll perform binary search on each index to calculate the minimum number of operations reqd to make that ele equal to gcd of the array
// Now, we need an O(1) good fn to get a time complexity of O(nlogn) -> n indices and logn binary search
// So, to get this we'll make use of sparse table to get gcd of a sub-array in O(1) time
vpii logs(200005);
class Sparse_table
{
public:
    vector<vi> table;
    void makeuptable(int, vi &, int (*fun)(int, int));
    int lookuptable(int, int, int (*fun)(int, int));
};

void Sparse_table::makeuptable(int n, vi &arr, int (*fun)(int, int))
{
    int cnt(0);
    while (n > 1)
    {
        n >>= 1;
        cnt++;
    }
    n = sz(arr);
    // table();
    /*
    fun is the function pointer to the function we wanna use.
    */
    table = vector<vi>(cnt + 1, vi(n + 1));
    // loop(i, 0, cnt+1){
    //     vi x(n+1);
    //     table[i] = x;
    // }
    loop(i, 0, n)
    {
        table[0][i + 1] = arr[i];
    }
    loop(i, 1, cnt + 1)
    {
        loop(j, 1, n + 1)
        {
            table[i][j] = fun(table[i - 1][j], table[i - 1][j + (1 << (i - 1))]);
        }
    }
}

int Sparse_table::lookuptable(int start, int length, int (*fun)(int, int))
{
    int end = start + length - 1;
    int n = logs[length].ff, cnt = logs[length].ss;
    // // // table();
    // cout<<cnt<<endl;
    // cout<<length <<" debug "<<start<<endl;
    // cout<<table[cnt][start]<<sp<<table[cnt][end - n + 1]<<endl;
    // return 1;
    return fun(table[cnt][start], table[cnt][end - n + 1]);
}

Sparse_table tbl;
int (*fun)(int, int) = &_gcd;

int bin_srch(int n, int idx, vi &arr, int g)
{
    int lo = 1, hi = n;
    int ans = n;
    while (lo <= hi)
    {
        int mid = (lo + hi) / 2;
        if (idx + mid > n)
        {
            if (_gcd(tbl.lookuptable(idx + 1, n - idx, fun), tbl.lookuptable(1, mid - n + idx, fun)) == g)
            {
                hi = mid - 1;
                ans = min(ans, mid);
                // cout << idx << sp << mid << sp << ans << endl;
            }
            else
            {
                lo = mid + 1;
            }
        }
        else
        {
            if (tbl.lookuptable(idx + 1, mid, fun) == g)
            {
                hi = mid - 1;
                ans = min(ans, mid);
                // cout << idx << sp << mid << sp << ans << endl;
            }
            else
            {
                lo = mid + 1;
            }
        }
    }
    // cout << ans << endl;
    return ans - 1;
}

void solve()
{
    int n;
    cin >> n;
    // int k; cin >> k;
    // string s; cin >> s;
    vi arr(n);
    int g = 0;
    loop(i, 0, n)
    {
        cin >> arr[i];
        g = _gcd(g, arr[i]);
    }
    tbl.makeuptable(n, arr, fun);
    int ans = 0;
    loop(i, 0, n)
    {
        if (arr[i] == g)
            continue;
        ans = max(ans, bin_srch(n, i, arr, g));
        // cout << ans << endl;
    }
    cout << ans << endl;
}

int32_t main()
{
    FIO
    int val = 1, cnt = 0;
    logs[1] = make_pair(1, 0);
    loop(i, 2, 200005){
        if (2 * val == i)
            val *= 2, cnt ++;   
        logs[i] = make_pair(val, cnt);   
    }
    // prt(logs[7]);
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

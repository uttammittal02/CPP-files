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

// void err(istream_iterator<string> it){};
// template <typename T, typename... Args>
// void err(istream_iterator<string> it, T a, Args... args)
// {
//     cout << a << " ";
//     err(++it, args...);
// };
// #define print(args...){string _s = #args; replace(_s.begin(), _s.end(), ',', ' '); stringstream _ss(_s);istream_iterator<string> _it(_ss);err(_it, args);cout<<"\n";};
// #define printarr(v, start, end)for (int _i = (start); _i < (end); _i++) cout << (v[_i]) << " ";cout << "\n";
using namespace std;

// #include <ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/tree_policy.hpp>
// using namespace __gnu_pbds;
// template<typename T>
// #define pbds(T) tree<T, null_type,less<T >, rb_tree_tag,tree_order_statistics_node_update>

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

template <typename T>
set<T> sieve(T n)
{
    vector<int> prime(n + 1, 1);
    for (int i = 2; i * i <= n; i++)
    {
        if (prime[i])
        {
            for (int j = 2; j * i <= n; j++)
            {
                prime[i * j] = 0;
            }
        }
    }
    set<T> ans;
    for (int i = 2; i <= n; i++)
    {
        if (prime[i])
            ans.insert(i);
    }
    return ans;
}
//--------------------------------------------------------------------------------------------------------//
//--------------------------------------------------------------------------------------------------------//
//--------------------------------------------------------------------------------------------------------//
//--------------------------------------------------------------------------------------------------------//
//--------------------------------------------------------------------------------------------------------//
set <int> primes;
int fun(vi &arr, int i, int e, int n, bool one)
{
    if (i + e >= n)
        return 0;
    if (arr[i + e] == 1)
        return 1 + fun(arr, i, e, n, one);
    if (!one and find_ele(arr[i + e], primes))
        return 1 + fun(arr, i, e, n, one);
    return 0;
}

int32_t main()
{
    primes = sieve((int)1e6);
    FIO
        test_cases_loop
    {
        int n, e;
        cin >> n >> e;
        vi arr(n);
        loop(i, 0, n)
        {
            cin >> arr[i];
        }
    }
    return 0;
}

//--------------------------------------------------------------------------------------------------------//
//--------------------------------------------------------------------------------------------------------//
//--------------------------------------------------------------------------------------------------------//
//--------------------------------------------------------------------------------------------------------//
//--------------------------------------------------------------------------------------------------------//
//--------------------------------------------------------------------------------------------------------//

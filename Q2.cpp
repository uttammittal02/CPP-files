#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cmath>
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
#include <functional>
// #include <ext/pb_ds/assoc_container.hpp>

#define infinity 8999999999999999999
#define debug(a) cout << "debug " <<a << endl;
#define sz(v) ((int)(v).size())
#define all(v) (v).begin(),(v).end()
#define And &&
#define Or ||
#define endl '\n'
#define space " "
#define int long long
#define vi vector<int>
#define pb(n) push_back(n)
#define mii map<int, int>
#define test_cases_loop int t; cin >> t; while(t--)
#define FIO ios_base::sync_with_stdio(false); cin.tie(NULL);
#define loop(var, initial, final) for(int var=initial; var < final; var++)
using namespace std;
// using namespace __gnu_pbds;
int gcd(int a, int b)
{
    if (b == 0)
        return a;
    return gcd(b, a % b);
     
}

int32_t main(){
    test_cases_loop{
        int n, cnt(0);
        cin>>n;
        vi arr(n);
        loop(i, 0, n){cin>>arr[i]; if (arr[i]%2==0) cnt++;}
        // cout<<cnt<<endl;
        int ans = cnt * (2*n - cnt - 1)/2;
        sort(arr.begin(), arr.end(), greater<int>());
        // cout<<ans<<endl;
        loop(i, 0, n){
            if (arr[i]%2 == 0) continue;
            loop(j, i+1, n){
                if (arr[j]%2 == 0) {continue;}
                if (gcd(arr[i], arr[j]) > 1) {ans++; }

            }
        }
        cout<<ans<<endl;
    }
    return 0;
}

// #include <ext/pb_ds/assoc_container.hpp>
// using namespace __gnu_pbds;
// using namespace std;
 
// #define ff              first
// #define ss              second
// #define int             long long
// #define pb              push_back
// #define mp              make_pair
// #define mt              make_tuple
// #define pii             pair<int,int>
// #define vi              vector<int>
// #define mii             map<int,int>
// #define pqb             priority_queue<int>
// #define pqs             priority_queue<int,vi,greater<int> >
// #define setbits(x)      __builtin_popcountll(x)
// #define mod             1000000007
// #define inf             1e18
// #define ps(x,y)         fixed<<setprecision(y)<<x
// #define mk(arr,n,type)  type *arr=new type[n];
// #define range(a,b)        substr(a,b-a+1)
// #define w(x)            int x; cin>>x; while(x--)
// #define trace(x)         cerr<<#x<<": "<<x<<" "<<endl;
// #define FIO             ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
// mt19937                 rng(chrono::steady_clock::now().time_since_epoch().count());
 
// typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> pbds;
 
// bool cmp(int a, int b)
// {
//     return (a % 2) < (b % 2);
// }

// int32_t main()
// {
//     FIO;
//     w(t)
//     {
//         int n; cin >> n;
//         mk(a, n, int);
 
//         for (int i = 0; i < n; ++i)
//             cin >> a[i];
 
//         sort(a, a + n, cmp);
 
//         int ans = 0;
 
//         for (int i = 0; i < n; ++i)
//             for (int j = i + 1; j < n; ++j)
//                 if (__gcd(a[i], 2 * a[j]) > 1)
//                     ans++;
 
//         cout << ans << '\n';
//     }
//     return 0;
// }
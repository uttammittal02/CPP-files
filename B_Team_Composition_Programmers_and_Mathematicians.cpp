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

#define YES                                         cout<<"YES"<<endl;
#define Yes                                         cout<<"Yes"<<endl;
#define NO                                          cout<<"NO"<<endl;
#define No                                          cout<<"No"<<endl;
#define infinity                                    999999999999999999
#define float                                       long double
#define sz(v)                                       ((int)(v).size())
#define all(v)                                      (v).begin(),(v).end()
#define MOD                                         (int)1000000007
#define endl                                        '\n'
#define space                                       " "
#define int                                         long long
#define pii                                         pair<int, int>
#define vi                                          vector<int>
#define pb(n)                                       push_back(n)
#define mii                                         map<int, int>
#define umii                                        unordered map<int, int>
#define test_cases_loop                             int t; cin >> t; while(t--)
#define FIO                                         ios_base::sync_with_stdio(false); cin.tie(NULL);
#define loop(var, initial, final)                   for(int var=initial; var < final; var++)
#define rloop(var, init, end)                       for (int var = init; var >= end; var--)
#define ff                                          first
#define ss                                          second
#define makepair(p, a, b)                           p.ff = a, p.ss = b
using namespace std;

// #include <ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/tree_policy.hpp>
// using namespace __gnu_pbds;
// template<typename T>
// #define pbds(T) tree<T, null_type,less<T >, rb_tree_tag,tree_order_statistics_node_update>


vector<int> divisors(int n){
	vector<int> ans;
	for(int i = 2;i<=sqrt(n);i++){
		if(n % i ==0){
			ans.pb(i);
			if(n/i != i) ans.pb(n/i);
		}
	}
	ans.pb(1);
	return ans;
}
void precision_print(float n, int p){
    cout<<fixed<<setprecision(p)<<n<<endl;
    return;
}


//--------------------------------------------------------------------------------------------------------//
//--------------------------------------------------------------------------------------------------------//
//--------------------------------------------------------------------------------------------------------//
//--------------------------------------------------------------------------------------------------------//
//--------------------------------------------------------------------------------------------------------//

int32_t main(){
    FIO
    test_cases_loop{
	    int x, y; cin >> x >> y;
        int a = max(x, y), b = min(x, y);
        int ans = 0;
        ans += min((a-b)/2, b);
        a -= (3*ans);
        b -= ans;
        ans += min(a/2, b/2);
        // if (a >= (3*b)/2){
        //     cout << min(a/3, b) << endl;
        // }
        // ans += (2 * min(a/4, b/4));
        // a -= (2*ans);
        // b -= (2*ans);
        
        // ans += (bool)(min(a, b) % 4 != 0);
        // ans += (max(min(a/2, b/2), max(min(a/3, b), min(a, b/3)))) ;
        // if (x >= 3 * y){
        //     cout << y << endl;
        //     continue;
        // }
        // ans += y/2;
        // x -= (2*ans);
        // y -= (2*ans);
        // ans += (x/3);
        // cout << ans << endl;
        // ans += min(x/3, y);
        // x -= (3*ans);
        // y -= ans;
        // ans += min(x, y/3);
        cout << ans << endl;
    }
    return 0;
}


//--------------------------------------------------------------------------------------------------------//
//--------------------------------------------------------------------------------------------------------//
//--------------------------------------------------------------------------------------------------------//
//--------------------------------------------------------------------------------------------------------//
//--------------------------------------------------------------------------------------------------------//
//--------------------------------------------------------------------------------------------------------//



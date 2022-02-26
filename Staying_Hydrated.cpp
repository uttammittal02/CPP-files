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
#define FIO                                         ios_base::sync_with_stdio(false); cin.tie(NULL);
#define loop(var, initial, final)                   for(int var=initial; var < final; var++)
#define test_cases_loop                             int t; cin >> t; loop(test, 0, t)
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
	    int n; cin>>n;
        vector <pair<pii, pii > > coordinates(n);
        int x_lb = 100, y_lb = 100, x_ub = -100, y_ub = -100; 
        int ans = INT64_MAX;
        loop(i, 0, n){
            pii p1, p2;
            pair <pii, pii > p;
            int x, y; cin >> x >> y;
            makepair(p1, x, y);
            cin >> x >> y;
            makepair(p2, x, y);
            makepair(p, p1, p2);
            coordinates[i] = p;
            x_lb = min(x_lb, min(x, p1.ff));
            y_lb = min(y_lb, min(y, p1.ss));
            x_ub = max(x_ub, max(x, p1.ff));
            y_ub = max(y_ub, min(y, p1.ss));
        }
        int x, y;
        loop(i, x_lb, x_ub + 1){
            loop(j, y_lb, y_ub + 1){
                int temp = 0;
                loop(k, 0, n){
                    if (i > coordinates[k].ss.ff)
                        temp += (i - coordinates[k].ss.ff);
                    
                    else if (i < coordinates[k].ff.ff)
                        temp += (coordinates[k].ff.ff - i);
                    
                    if (j > coordinates[k].ss.ss)
                        temp += (j - coordinates[k].ss.ss);
                    
                    else if (j < coordinates[k].ff.ss)
                        temp += (coordinates[k].ff.ss - j);
                }
                if (ans > temp){
                    // cout << ans << space << temp << endl;
                    ans = temp;
                    x = i, y = j;
                }
            }
        }
        cout << "Case #" << test + 1 << ": " << x << space << y << endl;
    }
    return 0;
}


//--------------------------------------------------------------------------------------------------------//
//--------------------------------------------------------------------------------------------------------//
//--------------------------------------------------------------------------------------------------------//
//--------------------------------------------------------------------------------------------------------//
//--------------------------------------------------------------------------------------------------------//
//--------------------------------------------------------------------------------------------------------//



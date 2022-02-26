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
#define sp	                                       	' '
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
#define iter(itr, start, end)						for (itr = start; itr != end; itr ++)
#define yesno(var)									cout << (var? "YES" : "NO") << endl;
#define vpii										vector <pii >

using namespace std;

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

int ceil_(int n, int k){
	// return (n - ((k-1)*n) / k);
    return (n + k - 1) / k;
}

//--------------------------------------------------------------------------------------------------------//
//--------------------------------------------------------------------------------------------------------//
//--------------------------------------------------------------------------------------------------------//
//--------------------------------------------------------------------------------------------------------//
//--------------------------------------------------------------------------------------------------------//

int32_t main(){
    FIO
    // vector <vi > dp(51, vi(10005, 1));
    // loop(p, 1, 10005){
    //     int a = 0;
    //     loop(h, 2, 51){
    //         dp[h][p] = ceil_((a + (1 << (h - 1))), p) + dp[h - 1][p] - (bool)(a);
    //         a = (a + (1 << (h - 1))) % p * (bool) (a + (1 << (h - 1)) >= p);
    //         // cout << dp[h][p] << sp << h << sp << p << sp << a << endl;
    //     }
    // }
    test_cases_loop{
	    int h, p; cin >> h >> p;
        int x = 1, ans = 0, temp = 1;
        while (x <= p){
            x *= 2; ans ++;
            temp += x;
        }
        // temp -= x;
        // x /= 2;
        x --;
        // ans --;
        // cout << x << sp << ans << sp << temp << endl;
        ans += ceil_(((1 << h) - x - 1), p);
        // int ans = 0;
        // loop(i, 0, h){
        //     ans += ceil_((1 << i), p);
        // }
        cout << ans << endl;
        // cout << dp[h][p] << endl;
    }
    return 0;
}

//--------------------------------------------------------------------------------------------------------//
//--------------------------------------------------------------------------------------------------------//
//--------------------------------------------------------------------------------------------------------//
//--------------------------------------------------------------------------------------------------------//
//--------------------------------------------------------------------------------------------------------//
//--------------------------------------------------------------------------------------------------------//

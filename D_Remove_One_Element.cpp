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
	return (n - ((k-1)*n) / k);
}

//--------------------------------------------------------------------------------------------------------//
//--------------------------------------------------------------------------------------------------------//
//--------------------------------------------------------------------------------------------------------//
//--------------------------------------------------------------------------------------------------------//
//--------------------------------------------------------------------------------------------------------//

int32_t main(){
    FIO
    // test_cases_loop{
	    int n; cin >> n;
        vi arr(n);
        int l = 0, r = 0;
        vector <pii > pairs;
        loop(i, 0, n){
            cin >> arr[i];
            if (i and arr[i] > arr[i-1]){
                r ++;
                // cout << "if\n";
            }
            else if (l != r){
                pairs.pb(make_pair(l, r));
                r ++; l = r;
                // cout << "elif\n";
            }
            else if (i){
                l ++; r ++;
                // cout << "else\n";
            }
            // cout << l << space << r << space << i << endl;
            // if (!pairs.empty())
            //     cout << pairs.back().ff << space << pairs.back().ss << endl;
        }
        if (l != r)
            pairs.pb(make_pair(l, n-1));
        int max_ = INT64_MIN;
        loop(i, 0, pairs.size()){
            if (i and (pairs[i].ff - pairs[i-1].ss <= 2 and arr[pairs[i].ff] > arr[pairs[i].ff - 2]))
                max_ = max(max_, pairs[i].ss - pairs[i-1].ff);
            else
                max_ = max(max_, pairs[i].ss - pairs[i].ff + 1);
            // cout << max_ << endl;
        }
        cout << max_ << endl;
    // }
    return 0;
}

//--------------------------------------------------------------------------------------------------------//
//--------------------------------------------------------------------------------------------------------//
//--------------------------------------------------------------------------------------------------------//
//--------------------------------------------------------------------------------------------------------//
//--------------------------------------------------------------------------------------------------------//
//--------------------------------------------------------------------------------------------------------//



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

int good(vi &pref, vi &suffix, int len){
    int l = 0, r = 2*len - 1;

    int sum = -infinity;
    while (r < sz(pref)){
        int ans;
        if (!l){
            ans = pref[r] + suffix[r + 1];
        }
        else if (l == 1){
            ans = pref[l - 1] + pref[r - 1] + suffix[r + 2];
        }
        else if (l % 2){
            ans = pref[l-1] + pref[r-1] - pref[l - 2] + suffix[r + 2];
        }
        else{
            ans = pref[l - 2] + pref[r] - pref[l - 1] + suffix[r + 1];
        }
        sum = max(sum, ans);
        l++, r ++;
    }
    return sum;
}

int32_t main(){
    FIO
    test_cases_loop{
	    int n; cin >> n;
		vi arr(n);
		loop(i, 0, n){
			cin >> arr[i];
		}
        vi pref(n), suff(n+1);
        pref[0] = arr[0], pref[1] = arr[1];
        loop(i, 2, n){
            pref[i] = pref[i - 2] + arr[i];
        }
        suff[n - 1 - (bool)(n % 2 == 0)] = arr[n - 1 - (bool)(n % 2 == 0)];
        for (int i = n - 3 - (bool)(n % 2 == 0); i >= 0; i -= 2){
            suff[i] = suff[i+2] + arr[i];
        }
        suff[n] = 0;
        int l = 1, r = ceil_(n, 2);
        int ans = suff[0];
        while (l <= r){
            int mid = l + (r - l) / 2;
            int temp = good(pref, suff, mid);
            if (temp >= ans){
                ans = temp;
                l = mid + 1;
            }
            else
                r = mid - 1;
            cout << l << space << r << space << ans << endl;
        }
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



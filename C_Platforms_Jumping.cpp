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

int32_t main(){
    FIO
    // test_cases_loop{
	    int n, m, d; cin >> n >> m >> d;
        // int k; cin >> k;
		// string s; cin >> s;
		vi arr(m), suff(m);
		loop(i, 0, m){
			cin >> arr[i];
		}
        suff[m-1] = arr[m-1];
        rloop(i, m-2, 0)
            suff[i] = suff[i+1] + arr[i];
        if (suff[0] > n){
            NO exit(0);
        }
        vi blocks(m, -1);
        int i = d, j = 0;
        int left = 0;
        while (i <= n+1 and j < m){
            blocks[j] = i;
            i += (arr[j] - 1);
            j ++;
            if (i >= n+1){
                left += (i - n); break;
            }
            i += d;
            // cout << i << space << j << endl;
        }
        if (i < n+1){
            NO exit(0);
        }
        YES
        if (j < m)
            left += suff[j];
        blocks[0] = max((int)1, blocks[0] - left);
        // cout << blocks[0] << space;
        loop(i, 1, sz(blocks)){
            if (blocks[i] != -1)
                blocks[i] = max(blocks[i-1] + arr[i-1], blocks[i] - left);
            else
                blocks[i] = blocks[i-1] + arr[i-1];
            // cout << blocks[i] << space;
        }
        // cout << endl;
        loop(i, 1, n+1){
            int idx = lower_bound(all(blocks), i) - blocks.begin();
            // cout << idx << space << i << endl;
            if (blocks[idx] != i and idx) idx --;
            if (idx == -1 or blocks[idx] + arr[idx] - 1 < i or blocks[idx] > i)
                cout << "0 ";
            else
                cout << idx + 1 << space;
        }
    // }
    return 0;
}

//--------------------------------------------------------------------------------------------------------//
//--------------------------------------------------------------------------------------------------------//
//--------------------------------------------------------------------------------------------------------//
//--------------------------------------------------------------------------------------------------------//
//--------------------------------------------------------------------------------------------------------//
//--------------------------------------------------------------------------------------------------------//



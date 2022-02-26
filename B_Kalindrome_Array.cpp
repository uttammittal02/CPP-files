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
	    int n; cin>>n;
        // set <int> unique_ele;
        vi arr(n);
        loop(i, 0, n){
            cin >> arr[i];
            // unique_ele.insert(arr[i]);
        }
        // if (sz(unique_ele) > (int)(ceil(n/2.0)) and n > 2){
        //     NO; continue;
        // }
        bool var = true;
        // set<int>::iterator itr;
        int i = 0, j = n-1;
        while(i != j){
            if (arr[i] == arr[j]){
                i ++; j --;
                continue;
            }
            int ele = arr[j];
            vi temp;
            loop(i, 0, n){
                if (arr[i] != ele) temp.pb(arr[i]);
            }
            var = true;
            loop(i, 0, sz(temp)/2){
                if (temp[i] != temp[sz(temp) - i - 1]){
                    var = false; break;
                }
            }
            if (var) break;
            ele = arr[i];
            temp.clear();
            loop(i, 0, n){
                if (arr[i] != ele) temp.pb(arr[i]);
            }
            var = true;
            loop(i, 0, sz(temp)/2){
                if (temp[i] != temp[sz(temp) - i - 1]){
                    var = false; break;
                }
            }
            break;
        }
        if (var) YES
        else NO
        
    }
    return 0;
}


//--------------------------------------------------------------------------------------------------------//
//--------------------------------------------------------------------------------------------------------//
//--------------------------------------------------------------------------------------------------------//
//--------------------------------------------------------------------------------------------------------//
//--------------------------------------------------------------------------------------------------------//
//--------------------------------------------------------------------------------------------------------//



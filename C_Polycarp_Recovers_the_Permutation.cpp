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
        vi arr(n);
        loop(i, 0, n){
            cin >> arr[i];
        }
        deque <int> ans;
        int i = 0, j = n - 1;
        while (i != j){
            if (arr[i] > arr[j]){
                ans.push_front(arr[i]);
                i++;
            }
            else{
                ans.push_back(arr[j]);
                j --;
            }
        }
        deque <int> check, temp = ans;
        // int i = 0, j = n - 1;
        temp.push_front(arr[i]);
        while (sz(temp) > 1){
            if (temp.front() < temp.back()){
                check.push_front(temp.front());
                // i++;
                temp.pop_front();
            }
            else{
                check.push_back(temp.back());
                temp.pop_back();
                // j --;
            }
        }
        check.push_front(temp.front());
        // temp = ans;
        // temp.push_front(arr[i]);
        bool var = true;
        loop(i, 0, n){
            if (arr[i] != check.front()){
                var = false; break;
            }
            // temp.pop_front();
            check.pop_front();
        }
        if (var){
        ans.push_back(arr[i]);
            loop(i, 0, n){
                cout << ans.front() << space;
                ans.pop_front();
            }
            cout << endl;
            continue;
        }
        // ans.pop_front();
        temp = ans;
        check.clear();
        temp.push_back(arr[i]);
        while (sz(temp) > 1){
            if (temp.front() < temp.back()){
                check.push_front(temp.front());
                // i++;
                temp.pop_front();
            }
            else{
                check.push_back(temp.back());
                temp.pop_back();
                // j --;
            }
        }
        check.push_back(temp.front());
        // temp = ans;
        // temp.push_back(arr[i]);
        var = true;
        loop(i, 0, n){
            if (arr[i] != check.front()){
                var = false; break;
            }
            // temp.pop_front();
            check.pop_front();
        }
        if (var){
            ans.push_back(arr[i]);
            loop(i, 0, n){
                cout << ans.front() << space;
                ans.pop_front();
            }
            cout << endl;
            continue;
        }
        cout << "-1\n";
    }
    return 0;
}


//--------------------------------------------------------------------------------------------------------//
//--------------------------------------------------------------------------------------------------------//
//--------------------------------------------------------------------------------------------------------//
//--------------------------------------------------------------------------------------------------------//
//--------------------------------------------------------------------------------------------------------//
//--------------------------------------------------------------------------------------------------------//



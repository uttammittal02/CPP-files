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

// int32_t main(){
//     FIO
//     test_cases_loop{
// 	    int n; cin>>n;
//         vi arr(n), visited(n+1);
//         set <int> no_gift, gifters;
//         loop(i, 0, n){
//             cin >> arr[i];
//             if (visited[arr[i]]) arr[i] = 0;
//             visited[arr[i]] ++;
//             if (!(arr[i]))  gifters.insert(i);
//         }
//         loop(i, 0, n){
//             if (!visited[i + 1]) no_gift.insert(i);
//         }
//         int k = n - sz(gifters);
//         // loop(i, 0, n) cout << arr[i] << space;
//         // cout << endl;
//         vi inter;
//         set <int> intersect;
//         set_intersection(no_gift.begin(), no_gift.end(), gifters.begin(), gifters.end(), std::back_inserter(inter));
//         if (sz(inter) == 1){
//             set<int> ::iterator itr = gifters.begin();
//             if ((*itr) == inter[0]) itr ++;
//             arr[(*itr)] = inter[0] + 1;
//             intersect.insert(*itr);
//             itr = no_gift.begin();
//             if ((*itr) == inter[0]) itr ++;
//             arr[inter[0]] = (*itr) + 1;
//             intersect.insert(inter[0]);
//             intersect.insert(*itr);
//         }
//         else{
//             loop(i, 0, sz(inter)){
//                 arr[inter[i]] = inter[(i+1) % sz(inter)] + 1;
//                 intersect.insert(inter[i]);
//             }
//         }
//         set<int> ::iterator itr1, itr2 = no_gift.begin();
//         for (itr1 = gifters.begin(); itr1 != gifters.end(); itr1 ++){
//             if (intersect.find(*itr1) != intersect.end()) continue;
//             while(intersect.find(*itr2) != intersect.end()) itr2 ++;
//             arr[*itr1] = (*itr2) + 1;
//             itr2 ++;
//         }
//         cout << k << endl;
//         loop(i, 0, n) cout << arr[i] << space;
//         cout << endl;
//     }
//     return 0;
// }
vi g(200000 + 1);
int findTail(int h){
    while(g[h]) h = g[h];
    return h;
}
 
int32_t main(){
    FIO
    test_cases_loop{
    int n; cin >> n;
    vi heads(n + 1, 1), visited(n+1);
    loop(i, 0, n){
        int t; cin >> t;
        visited[t] ++;
        g[i + 1] = t;
        if (visited[t] != 1) g[i+1] = 0;
    }
    loop(i, 1, n + 1)
            cout << g[i] << space; cout << endl;
    loop(i, 0, sz(g)) heads[g[i]] = 0;
    // for(auto p : heads) cout << p << ' '; cout << endl;
    vector <pii > circle;
    loop(i, 1, n + 1){
        if(heads[i]){
            int tail = findTail(i);
            // cout << i << space << tail << endl;
            circle.pb(make_pair(i, tail));
        }
    }
 
    loop(i, 0, sz(circle)){
        int tail = circle[i].ss;
        int head = circle[(i + 1)%(sz(circle))].ff;
        g[tail] = head;
    }
    loop(i, 1, n + 1)
            cout << g[i] << space; cout << endl;
    }
    return 0;
}

//--------------------------------------------------------------------------------------------------------//
//--------------------------------------------------------------------------------------------------------//
//--------------------------------------------------------------------------------------------------------//
//--------------------------------------------------------------------------------------------------------//
//--------------------------------------------------------------------------------------------------------//
//--------------------------------------------------------------------------------------------------------//



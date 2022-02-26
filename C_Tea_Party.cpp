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
    
	int n, w; cin >> n >> w;
    vi arr(n), ans(n);
    map <int, vi, greater<int> > indices;
    loop(i, 0, n){
        cin >> arr[i];
        ans[i] += (arr[i] - arr[i]/2);
        indices[arr[i]].pb(i);
        w -= (arr[i] - arr[i]/2);
    }
    
    map <int, vi, greater<int> >::iterator itr = indices.begin();
    while (w > 0 and itr != indices.end()){
        int ele = (*itr).ff;
        vi check = (*itr).ss;
        int i = 0;
        while (w > 0 and i < check.size()){
            // cout << w << " debug " << ele << space << check[i] << endl;
            ans[check[i]] += min(w, ele/2);
            w -= min(w, ele/2);
            i ++;
        }
        itr ++;
    }
    
    if (w != 0){
        cout << "-1\n"; exit(0);
    } 
    loop(i, 0, n){
        cout << ans[i] << space;
    }
    return 0;
}

//--------------------------------------------------------------------------------------------------------//
//--------------------------------------------------------------------------------------------------------//
//--------------------------------------------------------------------------------------------------------//
//--------------------------------------------------------------------------------------------------------//
//--------------------------------------------------------------------------------------------------------//
//--------------------------------------------------------------------------------------------------------//
// Practice zone will include questions arranged based on their difficulty level that is predicted by the Machine learning model that's carefully trained to incorporate various factors such as question rating, its tags and a variety of other factors to ensure good quality filtering of problems for the user

// So, the major component of the compete zone are these questions that are visible on your screen. These are the recommendations that the Machine Learning Model generates and are unique to each user. It uses a series of algorithms such as KNN, cosine similarity, exponential similarity to collaboratively filter problems based on the user's interest and needs. this model is backed by python libraries such as surpriselib and scikit learn.

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
	ans.pb(1);
	for(int i = 2;i<=sqrt(n);i++){
		if(n % i == 0){
			ans.pb(i);
			if(n / i != i) ans.pb(n/i);
		}
	}
	ans.pb(n);
	return ans;
}
void precision_print(float n, int p){
    cout<<fixed<<setprecision(p)<<n<<endl;
    return;
}

int ceil_(int n, int k){
	return (n + k - 1) / k;
}
//--------------------------------------------------------------------------------------------------------//
//--------------------------------------------------------------------------------------------------------//
//--------------------------------------------------------------------------------------------------------//
//--------------------------------------------------------------------------------------------------------//
//--------------------------------------------------------------------------------------------------------//

int32_t main(){
    FIO
    test_cases_loop{
	    int n; cin >> n;
		vi arr(n);
		loop(i, 0, n)
			cin >> arr[i];
		
        vi suff_mex(n), vis(n + 1);
        int mex = 0;
        rloop(i, n-1, 0){
            if (arr[i] == mex){
                mex ++;
                while (vis[mex]) mex ++;
            }
            suff_mex [i] = mex;
            vis[arr[i]] ++;
        }
        vis = vi(n + 1);
        set <int> visited;
        vi ans;
        mex = 0;
        int j = 0;
        loop(i, 0, n){
            if (arr[i] == mex){
                mex ++;
                while (visited.find(mex) != visited.end()) mex ++;
            }
            visited.insert(arr[i]);
            if (suff_mex[j] == mex){
                ans.pb(mex); mex = 0;
                visited.clear();
                j = i + 1;
            }
        }
        cout << sz(ans) << endl;
        loop(i, 0, sz(ans)) 
            cout << ans[i] << sp;
        cout << endl;
    }
    return 0;
}

//--------------------------------------------------------------------------------------------------------//
//--------------------------------------------------------------------------------------------------------//
//--------------------------------------------------------------------------------------------------------//
//--------------------------------------------------------------------------------------------------------//
//--------------------------------------------------------------------------------------------------------//
//--------------------------------------------------------------------------------------------------------//



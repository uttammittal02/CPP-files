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

class Sparse_table
{
    public:
        vector<vi> table;
        void makeuptable(int, vi &, int (*fun)(int, int));
        int lookuptable(int, int, int (*fun)(int, int));
};
void Sparse_table::makeuptable(int n, vi &arr, int (*fun)(int, int))
{
    int cnt(0);
    while(n > 1){
        n>>=1; cnt++;
    }
    n = sz(arr);
    // table();
    /* 
    fun is the function pointer to the function we wanna use.
    */
    table.resize(cnt + 1);
    loop(i, 0, cnt+1){
        vi x(n+1, 0);
        table[i] = x;
    }
    loop(i, 0, n){
        table[0][i+1] = arr[i];
    }
    loop(i, 1, cnt+1)
    {   
        cout << table[i].size() << endl;
        loop(j, 1, n-(1<<(i-1)) - 1)
        {
            cout << i << space << j + (1 << (i - 1)) << endl;
            table[i][j] = fun(table[i-1][j], table[i-1][j+(1<<(i-1))]);
        }
    }
}

int Sparse_table::lookuptable(int start, int length, int (*fun)(int, int))
{
    int end = start + length - 1;
    int n = 1; int cnt(-1);
    while(n <= length){
        n<<=1; cnt++;
    }
    n/=2;
    // // table();
    // cout<<cnt<<endl;
    // cout<<length <<" debug "<<start<<endl;
    // cout<<table[cnt][start]<<space<<table[cnt][end - n + 1]<<endl;
    return fun(table[cnt][start], table[cnt][end - n + 1]);
}
// template<typename T>
int _gcd(int a, int b){
	int temp1 = max(a,b), temp2 = min(a,b);
	a = temp1, b = temp2;
	if(b == 0) return a;
	return _gcd(b, a%b);
}
//--------------------------------------------------------------------------------------------------------//
//--------------------------------------------------------------------------------------------------------//
//--------------------------------------------------------------------------------------------------------//
//--------------------------------------------------------------------------------------------------------//
//--------------------------------------------------------------------------------------------------------//

bool good(Sparse_table table, int len, int n, int (*fun)(int, int))
{
    int l = 0;
    while (l + len < n){
        if (table.lookuptable(l, len, fun) >= 2) return true;
        l ++;
    }
    return false;
}

int32_t main(){
    FIO
    test_cases_loop{
	    int n; cin>>n;
        vi arr(n), diff(n-1);
        loop(i, 0, n){
            cin >> arr[i];
            if (i) diff[i-1] = arr[i] - arr[i-1];
        }
        Sparse_table find_x;
        
        find_x.makeuptable(n-1, diff, &(_gcd));
        int l = 1, r = n;
        int ans = 0;
        // while (l < r){
        //     int mid = (l + r) / 2;
        //     if (good(find_x, mid, n, fun)){
        //         ans = mid; l = mid + 1;
        //     }
        //     else r = mid - 1;
        // }
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



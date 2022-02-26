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
#define MOD                                         1000000007
#define And                                         &&
#define Or                                          ||
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
#define ff                                          first
#define ss                                          second
using namespace std;


template<typename T>
void print(array<T,2> &arr);
template<typename T>
void print(vector<T> &v);
template<typename T>
void print(deque<T> &v); 
template<typename T>
T _gcd(T a, T b);
template<typename T>
vector<T> sieve(T n);
template<typename T>
T power(T x, T y, int p = LLONG_MAX);
int nxt();
// Returns n^(-1) mod p 
template<typename T>
T modInverse(T n, T p);
int gcd(vector<int> &diff);
bool isPowerof2(int x);
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
class Sparse_table{
    public:
        vector<vi> table;
        void makeuptable(int, vi &, int (*fun)(int, int));
        int lookuptable(int, int, int (*fun)(int, int));
};
void Sparse_table::makeuptable(int n, vi &arr, int (*fun)(int, int)){
    int cnt(0);
    while(n > 1){
        n>>=1; cnt++;
    }
    n = sz(arr);
    // table();
    
    table.resize(cnt + 1);
    loop(i, 0, cnt+1){
        vi x(n+1);
        table[i] = x;
    }
    loop(i, 0, n){
        table[0][i+1] = arr[i];
    }
    loop(i, 1, cnt+1){
        loop(j, 1, n+1){
            table[i][j] = fun(table[i-1][j], table[i-1][j+(1<<(i-1))]);
        }
    }
}

int Sparse_table::lookuptable(int start, int length, int (*fun)(int, int)){
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


//--------------------------------------------------------------------------------------------------------//
//--------------------------------------------------------------------------------------------------------//
//--------------------------------------------------------------------------------------------------------//
//--------------------------------------------------------------------------------------------------------//
//--------------------------------------------------------------------------------------------------------//

int good(vector<int> ones, vector<int> twos, int mid, int m){
    // if (ones[n-mid] >= m) return true;
    int sum = 0;
    pii pair;
    int i = 0;
    // i = max((int)0, mid - sz(ones));
    if (mid > sz(ones)) i = mid - sz(ones);
    while (sum < m And i <= mid){
        sum = 0;
        // if (mid - i > sz(ones)) i = sz(ones);
        if (i > sz(twos)) break;
        pair.ff = mid - i, pair.ss = i;
        if (i)
            sum += twos[sz(twos)-i];
        if (mid - i)    
            sum += ones[sz(ones)-(mid - i)];
        i++;
        
    }
    if (sum >= m) {
        // cout<<"i "<<i<<endl;
        return mid + i + 1;
    }
    pair.ff = -1;
    pair.ss = -1;
    return -1;
}


int32_t main(){
    FIO
    test_cases_loop{
	    int n, m; cin>>n>>m;
        vi arr(n);
        vi ones, twos;

        loop(i, 0, n)
            cin>>arr[i];

        loop(i,0, n){
            int temp; cin>>temp;
            if (temp == 1) ones.pb(arr[i]);
            else twos.pb(arr[i]);
        }
        sort(all(ones));
        sort(all(twos));
        for (int i = sz(ones)-2; i >= 0; i--){
            ones[i] += ones[i+1];
        }
        for (int i = sz(twos)-2; i >= 0; i--){
            // ones[i] += ones[i+1];
            twos[i] += twos[i+1];
        }
        int lo = 1;
        int ans = INT64_MAX;
        int hi = n;
        while (lo <= hi){
            int mid = lo + (hi - lo)/2;
            pii pair; 
            // pair = good(ones, twos, mid, m);
            int temp = good(ones, twos, mid, m);
            if (temp != -1){
                hi = mid - 1;
                ans = min(ans, temp);
            }
            else
                lo = mid + 1;
            
//             if (pair.ss > 0) {
// // cout<<"if\n";
//                 lo = mid + 1, ans = min(ans, 2*pair.ss + pair.ff);
//             }
//             else if (pair.ff == -1){ 
// // cout<<"elseif\n";

//                 lo = mid + 1;
//             }
//             else{ 
// // cout<<"else\n";

//                 hi = mid - 1, ans = min(ans, 2*pair.ss + pair.ff);
//             }

            // cout<<mid << " ans "<<ans<<endl;
        }
        if (ans == INT64_MAX) {
            cout<<-1<<endl; continue;
        }
        cout<<ans<<endl;
    }
    return 0;
}


//---------------------------------------9 7 4-----------------------------------------------------------------//
//---------------------------------------6 5-----------------------------------------------------------------//
//--------------------------------------------------------------------------------------------------------//
//--------------------------------------------------------------------------------------------------------//
//--------------------------------------------------------------------------------------------------------//
//--------------------------------------------------------------------------------------------------------//

template<typename T>
T power(T x, T y, int p) { 
    T res = 1;      // Initialize result 
  
    x = x % p;  // Update x if it is more than or 
                // equal to p 
    // cout <<"x= "<< x << endl;
    while (y > 0) 
    { 
        // If y is odd, multiply x with result 
        if (y & 1) 
            res = (res*x) % p; 
  
        // y must be even now 
        y = y>>1; // y = y/2 
        x = (x*x) % p; 
    } 
    // cout << "res" << res << endl;
    return res; 
} 
 
template<typename T>
vector<T> sieve(T n){
	vector<int> prime(n+1, 1);
	for(int i = 2; i*i<=n; i++){
		if(prime[i]){
			for(int j = 2; j*i<=n; j++){
				prime[i*j] = 0;
			}
		}
	}
	vector<T> ans;
	for(int i = 2; i<=n;i++){
		if(prime[i]) ans.pb(i);
	}
	return prime;
}
 
template<typename T>
T _gcd(T a, T b){
	T temp1 = max(a,b), temp2 = min(a,b);
	a = temp1, b = temp2;
	if(a == 0) return b;
	if(b == 0) return a;
	if(a%b ==0) return b;
	return _gcd(b, a%b);
}
 
template<typename T>
void print(array<T,2> &arr){
	cout << arr[0] << " " << arr[1] << endl;
}
 
// template<typename T>
// void print(vector<T> &v){
// 	for(T x: v) cout << x << " ";
// 	cout << endl;
// }
 
template<typename T>
T modInverse(T n, T p){
    return power(n, p-2, p)%p; 
} 
 
// template<typename T>
// void print(deque<T> &v){
// 	for(auto x: v) cout << x << " ";
// 	cout << endl;
// }
 
int nxt(){
    int x;
    cin >> x;
    return x;
}
 
bool isPowerof2(int x){
	return !(x && (x & (x-1)));
}
 

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
// ----------------------------------------------------------------------------------------------------------- //
// ----------------------------------------------------------------------------------------------------------- //
// ----------------------------------------------------------------------------------------------------------- //
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


// ----------------------------------------------------------------------------------------------------------- //
// ----------------------------------------------------------------------------------------------------------- //

int32_t main(){
    FIO
	test_cases_loop{
        int n, k;cin>>n>>k;
        vi arr(n);
        int first_pos(INT64_MAX), last_pos(-1);//it stores the indices of first and last +ve elements.
        loop(i, 0, n) {
            cin>>arr[i];
            if (arr[i] > 0) {
                first_pos = min(first_pos, i);
                last_pos = max(last_pos, i);
            }
        }
        if (last_pos < 0) {
            cout<<0<<endl; continue;
        }
        int cnt = n - last_pos;
        vi left(n), right(n); // for any index i left[i] and right[i] denote the distance of nearest +ve element to the left and right resp
        loop(i, 0, n){
            left[i] = cnt;
            if (arr[i]){
                cnt = 0; left[i] = min ((int)2, left[i]);//if the element itself is one its neighbours will become 1 after 1 sec and it will have a +ve neighbour on 2nd second
            }
            cnt++;
        }
        cnt = first_pos + 1;
        for (int i = n-1; i >= 0; i--){
            right[i] = cnt;
            if (right[i] < left[i]){
                left[i] = min(left[i], right[i] + 2);
            }
            else right[i] = min(right[i], left[i] + 2);
            if (arr[i]) {cnt = 0; right[i] = min((int)2, right[i]);}
            cnt++;
        }
        int ans = 0;
        loop(i, 0, n){
            ans += arr[i];
            ans += max((int)0, k - left[i] + 1);
            ans += max((int)0, k-right[i] + 1);
            // cout<<ans<<endl;
        }
        cout<<ans<<endl;
    }
    return 0;
}


// -----------------------------1  1------------------------------------------------------------------------------ //
// ----------------------------------------------------------------------------------------------------------- //
// ----------------------------------------------------------------------------------------------------------- //
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
 
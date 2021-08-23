#include <stack>
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <climits>
#include <algorithm>
#include <cmath>
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
#include <functional>

#define YES cout<<"YES"<<endl;
#define Yes cout<<"Yes"<<endl;
#define NO cout<<"NO"<<endl;
#define No cout<<"No"<<endl;
#define infinity 999999999999999999
#define float long double
#define sz(v) ((int)(v).size())
#define all(v) (v).begin(),(v).end()
#define MOD_DEFINE const int MOD = 1e9 + 7;
#define And &&
#define Or ||
#define endl '\n'
#define space " "
#define int long long
#define pii pair<int, int>
#define vi vector<int>
#define pb(n) push_back(n)
#define mii map<int, int>
#define umii unordered map<int, int>
#define test_cases_loop int t; cin >> t; while(t--)
#define FIO ios_base::sync_with_stdio(false); cin.tie(NULL);
#define loop(var, initial, final) for(int var=initial; var < final; var++)
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
// ----------------------------------------------------------------------------------------------------------- //
// ----------------------------------------------------------------------------------------------------------- //
// ----------------------------------------------------------------------------------------------------------- //



// ----------------------------------------------------------------------------------------------------------- //
// ----------------------------------------------------------------------------------------------------------- //

int32_t main(){
    FIO
	#ifndef ONLINE_JUDGE
  
    // For getting input from input.txt file
    freopen("input.txt", "r", stdin);
  
    // Printing the Output to output.txt file
    freopen("output.txt", "w", stdout);
    
	#endif
	int n; cin>>n;
    
    vector <int> arr(n);
    for(int i = 0; i < n; i++){
        cin>>arr[i];
    }
    bool cntst(0), gym(0);
    // int rest = 0;
    vector <vi > dp(105, vi (3, infinity));
    // cout<<dp[-1][0]<<endl;
    dp[0][0] = 0; dp[0][1] = 0; dp[0][2] = 0;
    loop(i, 1, n+1){
    	if (arr[i-1] == 0){
    		cntst = 0; gym = 0;
    		dp[i][0] = 1 + min(dp[i-1][0], min(dp[i-1][1], dp[i-1][2]));
    	}
    	else if (arr[i-1] == 1){
    		if (cntst) {
    			dp[i][0] = 1 + dp[i-1][1]; cntst = 0; 
    		}
    		else {
    			dp[i][1] = min(dp[i-1][0], dp[i-1][2]);
    			cntst = true; gym = false;
    		}
    	}
    	else if (arr[i-1] == 2){
    		if (gym) {
    			dp[i][0] = 1 + dp[i-1][2]; gym = 0;
    		}
    		else {
    			dp[i][2] = min(dp[i-1][0], dp[i-1][1]);
    			cntst = false; gym = true;
    		}
    	}
    	else {
    		if (gym) {
    // 			dp[i][0] = 1 + dp[i-1][2];
    			gym = 0;
    			dp[i][1] = dp[i-1][2]; cntst = true;
    		}
    		else if (cntst){
    // 			dp[i][0] = 1 + dp[i-1][1]; 
    			cntst = 0;
    			dp[i][2] = dp[i-1][1]; gym = true;
    		}
    		else {
    		   // cout<<"debug"<<endl;
    // 			dp[i][0] = 1 + dp[i-1][0];
    			dp[i][2] = dp[i-1][0];
    			dp[i][1] = dp[i-1][0];
    		}
    	}
    // 	cout<<i<<space<<dp[i][0]<<space<<dp[i][1]<<space<<dp[i][2]<<endl;
    } 
    cout<<min(dp[n][0], min(dp[n][1], dp[n][2]))<<endl;
    return 0;
}

// ----------------------------------------------------------------------------------------------------------- //
// ----------------------------------------------------------------------------------------------------------- //



// ----------------------------------------------------------------------------------------------------------- //
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
 
template<typename T>
void print(vector<T> &v){
	for(T x: v) cout << x << " ";
	cout << endl;
}
 
template<typename T>
T modInverse(T n, T p){
    return power(n, p-2, p)%p; 
} 
 
template<typename T>
void print(deque<T> &v){
	for(auto x: v) cout << x << " ";
	cout << endl;
}
 
int nxt(){
    int x;
    cin >> x;
    return x;
}
 
bool isPowerof2(int x){
	return !(x && (x & (x-1)));
}
 


#include <stack>
#include <iostream>
#include <cstdio>
#include <cstdlib>
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
	// cout<<"hello";
	test_cases_loop{
		int n; cin>>n;
		// n = (int)x;
		vi arr(2*n);
		loop(i, 0, 2*n){
			cin>>arr[i];
		}
		sort(all(arr));
		// for (std::vector<int>::iterator i = arr.begin(); i != arr.end(); ++i)
		// {
		// 	cout<<*i<<space;
		// }
		// cout<<endl;
		if (arr[2*n - 1] % (2*n)){cout<<"NO"<<endl; continue;}
		vi brr(n);
		// cout<<arr[2*n - 1]<<space<<2*n<<endl;
		brr[n-1] = arr[2*n-1]/(2*n);
		// cout<<brr[n-1]<<endl;
		bool odd = false;
		for (int i = 0; i < 2*n; i+=2)
		{
			int j = n - i/2 -1;
			if (arr[i] != arr[i+1] Or arr[i]%2 != 0){odd = true; break;}
			if (i != 2*n - 2 And arr[i] == arr[i+2]){odd = true; break;}
			if (i == 0){continue;}
			brr[j] = brr[j+1] - (arr[2*j + 2] - arr[2*j])/(2*j + 2);
			// cout<<brr[j]<<space;
			if (brr[j] <= 0 Or (arr[2*j + 2] - arr[2*j]) % (2*j + 2)){
				odd = true; 
				// cout<<"debug "<<brr[j]<<space<<j<<endl; 
				break;
			}
		}
		// for (std::vector<int>::iterator i = brr.begin(); i != brr.end(); ++i)
		// {
		// 	cout<<*i<<space;
		// }
		if (odd){
			cout<<"NO"<<endl; continue;
		}
		cout<<"YES"<<endl;
	}
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
 


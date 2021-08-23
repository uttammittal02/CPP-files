#include<iostream>
#include <vector>
#include <cmath>
#include <deque>
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
#define umii unordered_map<int, int>
#define test_cases_loop int t; cin >> t; while(t--)
#define FIO ios_base::sync_with_stdio(false); cin.tie(NULL);
#define loop(var, initial, final) for(int var=initial; var < final; var++)
using namespace std;
typedef long long ll;
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
// template<typename T>
// T power(T x, T y, ll p = LLONG_MAX);
ll nxt();
// // Returns n^(-1) mod p 
template<typename T>
T modInverse(T n, T p);
ll gcd(vector<int> &diff);
bool isPowerof2(ll x);
vector<int> divisors(ll n){
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
int binomial_cofficient(int n, int r){
    
    if(r == 0) return 1;
    return n*binomial_cofficient(n-1, r-1)/r;
}
// ░░░░░░░░░░░░▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄░░░░░░░░░░░░░
// ░░░░░▄▄▄▄█▀▀▀░░░░░░░░░░░░▀▀██░░░░░░░░░░░
// ░░▄███▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄█▄▄▄░░░░░░░
// ▄▀▀░█░░░░▀█▄▀▄▀██████░▀█▄▀▄▀████▀░░░░░░░
// █░░░█░░░░░░▀█▄█▄███▀░░░░▀▀▀▀▀▀▀░▀▀▄░░░░░
// █░░░█░▄▄▄░░░░░░░░░░░░░░░░░░░░░▀▀░░░█░░░░
// █░░░▀█░░█░░░░▄░░░░▄░░░░░▀███▀░░░░░░░█░░░
// █░░░░█░░▀▄░░░░░░▄░░░░░░░░░█░░░░░░░░█▀▄░░
// ░▀▄▄▀░░░░░▀▀▄▄▄░░░░░░░▄▄▄▀░▀▄▄▄▄▄▀▀░░█░░
// ░█▄░░░░░░░░░░░░▀▀▀▀▀▀▀░░░░░░░░░░░░░░█░░░
// ░░█░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░▄██░░░░
// ░░▀█▄░░░░░░░░░░░░░░░░░░░░░░░░░▄▀▀░░░▀█░░
// █▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀█
// █░░█▀▄ █▀▀ █▀█ █░░░░█░▄░█ █ ▀█▀ █░█░░█ ▀█▀░█
// █░░█░█ █▀▀ █▀█ █░░░░▀▄▀▄▀ █ ░█░ █▀█░░█ ░█░░█
// █░░▀▀░ ▀▀▀ ▀░▀ ▀▀▀░░░▀░▀░ ▀ ░▀░ ▀░▀░░▀ ░▀░░█
// ▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀
MOD_DEFINE
int multiply(int a, int b){
    // cout << a << space << b <<endl;
    if(b == 1){
        return a%MOD;
    }
    int pip = multiply(a, b/2);
    if(b%2){
        // cout << pip << endl;     
        return ((pip + pip)%MOD + a%MOD)%MOD;
    }
    else return (pip + pip)%MOD;
}
int power(int x, int y)
{
    // cout << x << space << y << endl;
    if (y == 0)
        return 1;
    else if (y % 2 == 0)
    {
        int chloe = power(x, y/2);
        return multiply(chloe, chloe);
    }
    else
    {
        int mermaid = power(x, y/2);
        return multiply(multiply(x, mermaid), mermaid);
    }

}
int32_t main(){
    cout << multiply(1000000000 + 6, 1000000000 + 6) << endl;
    FIO
    int candidate = 0;
    #ifndef ONLINE_JUDGE
  
    // For getting input from input.txt file
    freopen("input.txt", "r", stdin);
  
    // Printing the Output to output.txt file
    freopen("output.txt", "w", stdout);
  
	#endif
    
    // vi pallindromes {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10001, 10101, 10201, 10301, 10401, 10501, 10601, 10701, 10801, 10901, 1000001, 1001001, 1002001, 1003001, 1004001, 1005001, 1006001, 1007001, 1008001, 1009001, 100000001, 100010001, 100020001, 100030001, 100040001, 100050001, 100060001, 100070001, 100080001, 100090001};
    vi pallindromes;
    loop(i, 0, 10){
    	pallindromes.pb(i);
    }
    int curr = 1;
    loop(i, 0, 5*1e3+100){

        // if(!(curr%10)) curr++;

        string replica = to_string(curr);
        reverse(all(replica));            

        loop(i, 0, 10)
        {    
            // cout << "debug " << replica << endl;
            int lara = curr*round(pow(10, (sz(replica) + 1)));
            // cout << "debug " << lara << space << curr << endl;
            int palindrome = lara + i*pow(10, sz(replica)) + stoi(replica);

            pallindromes.pb(palindrome); 
        }
        curr++;
    }
    sort(all(pallindromes));
    
    vi pref_sum(sz(pallindromes), 0);

    loop(i, 1, sz(pallindromes)){
        pref_sum[i] = pref_sum[i-1] + pallindromes[i];
    }
    int q; cin >> q;

    loop(i, 0, q){
        int l, r; cin >> l >> r;
        // cout << pref_sum[r] - pref_sum[l] << endl;
        // cout << pallindromes[l] << endl;
        // cout << power(pallindromes[l]%MOD, pref_sum[r] - pref_sum[l])%MOD << endl;
    }
    // cout << power(9, 257 - 45) << endl;
    return 0;
}

//          ▄              ▄    
//         ▌▒█           ▄▀▒▌   
//         ▌▒▒█        ▄▀▒▒▒▐   
//        ▐▄█▒▒▀▀▀▀▄▄▄▀▒▒▒▒▒▐   
//      ▄▄▀▒▒▒▒▒▒▒▒▒▒▒█▒▒▄█▒▐   
//    ▄▀▒▒▒░░░▒▒▒░░░▒▒▒▀██▀▒▌   
//   ▐▒▒▒▄▄▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▀▄▒▌  
//   ▌░░▌█▀▒▒▒▒▒▄▀█▄▒▒▒▒▒▒▒█▒▐  
//  ▐░░░▒▒▒▒▒▒▒▒▌██▀▒▒░░░▒▒▒▀▄▌ 
//  ▌░▒▒▒▒▒▒▒▒▒▒▒▒▒▒░░░░░░▒▒▒▒▌ 
// ▌▒▒▒▄██▄▒▒▒▒▒▒▒▒░░░░░░░░▒▒▒▐ 
// ▐▒▒▐▄█▄█▌▒▒▒▒▒▒▒▒▒▒░▒░▒░▒▒▒▒▌
// ▐▒▒▐▀▐▀▒▒▒▒▒▒▒▒▒▒▒▒▒░▒░▒░▒▒▐ 
//  ▌▒▒▀▄▄▄▄▄▄▒▒▒▒▒▒▒▒░▒░▒░▒▒▒▌ 
//  ▐▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒░▒░▒▒▄▒▒▐  
//   ▀▄▒▒▒▒▒▒▒▒▒▒▒▒▒░▒░▒▄▒▒▒▒▌  
//     ▀▄▒▒▒▒▒▒▒▒▒▒▄▄▄▀▒▒▒▒▄▀   
//       ▀▄▄▄▄▄▄▀▀▀▒▒▒▒▒▄▄▀     
//          ▀▀▀▀▀▀▀▀▀▀▀▀       

// template<typename T>
// T power(T x, T y, ll p) { 
//     T res = 1;      // Initialize result 
  
//     x = x % p;  // Update x if it is more than or 
//                 // equal to p 
//     // cout <<"x= "<< x << endl;
//     while (y > 0) 
//     { 
//         // If y is odd, multiply x with result 
//         if (y & 1) 
//             res = (res*x) % p; 
  
//         // y must be even now 
//         y = y>>1; // y = y/2 
//         x = (x*x) % p; 
//     } 
//     // cout << "res" << res << endl;
//     return res; 
// } 
 
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
	// for(T x: v) cout << x << " ";
	cout << endl;
}
 
template<typename T>
T modInverse(T n, T p){
    return power(n, p-2, p)%p; 
} 
 
template<typename T>
void print(deque<T> &v){
	// for(auto x: v) cout << x << " ";
	cout << endl;
}
 
ll nxt(){
    ll x;
    cin >> x;
    return x;
}
 
bool isPowerof2(ll x){
	return !(x && (x & (x-1)));
}


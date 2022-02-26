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
// ----------------------------------------------------------------------------------------------------------- //
// ----------------------------------------------------------------------------------------------------------- //

int count(string s, char c)
{
    // Count variable
    int res = 0;
 
    for (int i=0;i<s.length();i++)
 
        // checking character in string
        if (s[i] == c)
            res++;
 
    return res;
}
// vi visited(4, 0);
// int cnt = 0;
string novel(string a, string b, int x){
    int n = sz(a);
    char var = '1';
    if (x >= n/2){
        var = '0';
    }
    // cnt++;
    
    // char check = to_string(var);
    int idx = 0;
    string ans = a;
    int i = 0, j = 0;
    
    i = count(ans, var);

    // cout<<"ans "<<ans<<endl;
    while(i < x){
        ans += var, i++;
        
    }
    // ans = ans.substr(0, sz(ans)-1);
    i = 0;
    while(i < n){
        if (b[i] == ans[idx]){
            i++; idx++; continue;
        }
        if (b[i] != var){
            if (idx == sz(ans)) {
                ans+=b[i], idx++;
                i++;
                continue;
            } 
            ans.insert(idx + 1, b, i, 1);
            i++;
        }
        idx++;
    }
    //111010
    //010001
    // // visited[]
    // int i(0), j(0), k(0);
    // while (i < 2*n And j < 2*n){
    //     if (a[i] == b[j]){              // 011111001111101000
    //         ans += a[i];
    //         i++; j++; k++; continue;
    //     }
    //     if (!k) {ans += a[i]; i++; k++; continue;}
    //     if (a[i] == ans[k-1]){
    //         ans += a[i]; i++; k++;
    //     }
    //     else {
    //         ans += b[j]; j++; k++;
    //     }
    // }
    // while (i < 2*n){
    //     ans += a[i]; i++; k++;
    // }
    // while(j < 2*n){
    //     ans += b[j]; j++; k++;
    // }
    // // while (k < 3*n){
    // //     ans += '0'; k++;
    // // }
    // if (k > 3*n And visited[cnt/2]){
    //     ans = novel(b, a);
    // }
    // if (k > 3*n){
    //     ans = "";
    // }
    return ans;
}

int32_t main(){
    FIO
	test_cases_loop{
        // cnt = 0;
        int n; cin>>n;
        string a, b, c;
        cin>>a>>b>>c;
        vi cnt(4, 0);
        loop(i, 0, 2*n){
            if (b[i] == '0') cnt[1] ++;
            if (c[i] == '0') cnt[2] ++;
            if (a[i] == '0') cnt[0] ++;
        }
        string ans = "";
        // assert(cnt[0] > n);
        if (cnt[0] >= n){
            if (cnt[1] >= n) ans = novel(a, b, max(cnt[0], cnt[1]));
            else if (cnt[2] >= n) ans = novel(a,c, max(cnt[0], cnt[2]));
        }
        else if (cnt[1] <= n) ans = novel(a,b, min(cnt[0], cnt[1]));
        else if (cnt[2] <= n) ans = novel(a,c, min(cnt[0], cnt[2]));
        if (ans == "") {
            if (cnt[1] >= n) ans = novel(b,c, max(cnt[1], cnt[2]));
            ans = novel(b,c, min(cnt[1], cnt[2]));
        }
        // visited[0] = 1;
        // ans = novel(first, b);   
        // if (ans == ""){
        //     visited[1] = 1;
        //     ans = novel(b, c);
        // }
        // if (ans == ""){
        //     visited[2] = 1;
        //     ans = novel(first, c);
        // }
        cout<<ans<<endl;
    }

    return 0;
}

/*
1111111101001111101111111110111111010111111111111111111111111111111011111111010111101111111111111111
0000010101101000000000000100011011000010111100000001001000000000000000010100000001000100001000000000
1011110111111101111101101111111111111011101111011111111111111010111011111111111011111011111111111111
*/
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
 

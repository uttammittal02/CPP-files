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
#define rloop(var, init, end)                       for (int var = init; var >= end; var--)
#define ff                                          first
#define ss                                          second
using namespace std;

// #include <ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/tree_policy.hpp>
// using namespace __gnu_pbds;
// template<typename T>
// #define pbds(T) tree<T, null_type,less<T >, rb_tree_tag,tree_order_statistics_node_update>

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
class Segment_tree{
    public:
        int n;

        int *arr;

        Segment_tree(int n){
            arr = new int[3*n];
        };

        void build(vi &input, int node_idx, int l, int r);

        int query(int l, int r, int node, int tl, int tr);

        void update(int idx, int num, int l, int r, int node);


};
/* 
We've stored the whole segment tree in an array.
Here, if we are present at any node i, then its left child is at index i + 1 and right child will be present after all the left children.
So, if node i represents subsegment [l, r] then its right child will be at the index i + 2*(mid - l + 1).
Another approach is to store it simply like in a bfs.
It takes array of size 4n and children of node at i-th index are 2i and 2i+1.
*/
// void Segment_tree::segment_tree(int n){
    
// }

void Segment_tree::build(vi &input, int node_idx, int l, int r){
    if (l==r){
        arr[node_idx] = input[l];
        return;
    }
    int mid = l + (r-l)/2;
    build(input, node_idx + 1, l, mid);
    build(input, node_idx + 2*(mid - l + 1), mid, r);

    arr[node_idx] = arr[2*node_idx] + arr[2*node_idx + 1];
}

int Segment_tree::query(int l, int r, int node, int tl, int tr){
    if (l > r)
        return 0;
    
    if (tl == l And tr == r){
        return arr[node];
    }

    int mid = tl + (tr - tl)/2;

    return query(l, min(r, mid), node + 1, tl, mid) + query(max(mid+1, l), r, node + 2*(mid - tl + 1), mid+1, tr);
}

void Segment_tree::update(int idx, int num, int l, int r, int node){
    if (l==r){
        arr[node] = num;
        return;
    }
    int mid = l + (r-l)/2;
    if (idx <= mid)
        update(idx, num, l, mid, 1+node);
    else
        update(idx, num, mid+1, r, node+2*(mid - l + 1));
    arr[node] = arr[2*(mid - l + 1)+node] + arr[node+1];
    return;
}

//--------------------------------------------------------------------------------------------------------//
//--------------------------------------------------------------------------------------------------------//
//--------------------------------------------------------------------------------------------------------//
//--------------------------------------------------------------------------------------------------------//
//--------------------------------------------------------------------------------------------------------//

int32_t main(){
    FIO
    test_cases_loop{
	    int n; cin>>n;
        vi arr(n+1);
        loop(i, 1, n+1) cin>>arr[i];
        Segment_tree trial(n);
        // trial.segment_tree(n);
        trial.build(arr, 1, 0, n-1);
        cout<<trial.query(1, 3, 1, 0, n-1)<<endl;
        trial.update(2, -5, 0, n-1, 1);
        cout<<trial.query(1, 3, 1, 0, n-1)<<endl;
    }
    return 0;
}


//--------------------------------------------------------------------------------------------------------//
//--------------------------------------------------------------------------------------------------------//
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
 
